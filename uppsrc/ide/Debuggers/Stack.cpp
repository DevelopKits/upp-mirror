#include "Debuggers.h"

#define LLOG(x) DLOG(x)

Pdb::Thread& Pdb::Current()
{
	return threads.Get((int)~threadlist);
}

void Pdb::Sync0()
{
	Thread& ctx = Current();
	const VectorMap<int, CpuRegister>& reg = Pdb::GetRegisterList();
	cpu.Clear();
	for(int i = 0; i < reg.GetCount(); i++) {
		const CpuRegister& r = reg[i];
		if(r.name) {
			DLOG(r.name << " = 0x" << Hex(GetCpuRegister(ctx, r.sym)));
			cpu.Add(String().Cat() << r.name << "|0x" << Hex(GetCpuRegister(ctx, r.sym)));
		}
	}

	stop = false;

	framelist.Clear();
	frame.Clear();

	STACKFRAME64 stackFrame = {0};
	stackFrame.AddrPC.Mode = stackFrame.AddrFrame.Mode = stackFrame.AddrStack.Mode = AddrModeFlat;
	DWORD machineType = IMAGE_FILE_MACHINE_I386;
	void *c;
#ifdef CPU_64
	if(win64) {
		machineType = IMAGE_FILE_MACHINE_AMD64;
		stackFrame.AddrPC.Offset = ctx.context64.Rip;
		stackFrame.AddrFrame.Offset = ctx.context64.Rbp;
		stackFrame.AddrStack.Offset = ctx.context64.Rsp;
		c = &ctx.context64;
	}
	else
#endif
	{
		machineType = IMAGE_FILE_MACHINE_I386;
		stackFrame.AddrPC.Offset = ctx.context32.Eip;
		stackFrame.AddrFrame.Offset = ctx.context32.Ebp;
		stackFrame.AddrStack.Offset = ctx.context32.Esp;
		c = &ctx.context32;
	}

	DDUMP(Hex(stackFrame.AddrPC.Offset));

	DWORD64 lastFrame = 0; // Prevent loops with optimised stackframes
	int fc = -1;
	while(::StackWalk64(machineType, hProcess, ctx.hThread, &stackFrame, c,
	      0, ::SymFunctionTableAccess64, ::SymGetModuleBase64, 0)) {
	    if(stackFrame.AddrPC.Offset == 0 || lastFrame >= stackFrame.AddrFrame.Offset) {
	    	LLOG("Invalid stack frame");
	      	break;
	    }
		lastFrame = stackFrame.AddrFrame.Offset;
		DLOG("PC: " << Hex(stackFrame.AddrPC.Offset));
		Frame& f = frame.Add();
		f.pc = stackFrame.AddrPC.Offset;
		f.frame = stackFrame.AddrFrame.Offset;
		f.stack = stackFrame.AddrStack.Offset;
		f.fn = GetFnInfo(f.pc);
		String r;
		if(IsNull(f.fn.name)) {
			r = Hex(f.pc);
			for(int i = 0; i < module.GetCount(); i++) {
				const ModuleInfo& m = module[i];
				if(f.pc >= m.base && f.pc < m.base + m.size) {
					r << " (" << GetFileName(m.path) << ")";
					break;
				}
			}
		}
		else {
			GetLocals(f, ctx, f.param, f.local);
			r = f.fn.name;
			r << '(';
			for(int i = 0; i < f.param.GetCount(); i++) {
				if(i)
					r << ", ";
				r << f.param.GetKey(i) << "=" << Visualise(f.param[i]).GetString();
			}
			r << ')';
			if(fc < 0)
				fc = frame.GetCount() - 1;
		}
		framelist.Add(frame.GetCount() - 1, r);
	}
	framelist <<= max(fc, 0);
}
