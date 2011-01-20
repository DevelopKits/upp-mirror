#ifndef _SysExec_ShellLib_h_
#define _SysExec_ShellLib_h_

#include <Core/Core.h>

NAMESPACE_UPP

#ifdef PLATFORM_WINDOWS

// executes a command via shell "runas" as admin user;
// if wait is true, will wait for command end, otherwise executes it in background
bool ShellExec(String const &args, VectorMap<String, String> const &env, bool wait);

#endif

END_UPP_NAMESPACE

#endif
