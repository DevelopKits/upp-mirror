#include "Builders.h"

AndroidModuleMakeFile::AndroidModuleMakeFile()
{
	
}

AndroidModuleMakeFile::AndroidModuleMakeFile(const String& name)
{
	this->name = name;
}

AndroidModuleMakeFile::~AndroidModuleMakeFile()
{
	
}

void AndroidModuleMakeFile::Clear()
{
	name.Clear();
	sourceFiles.Clear();
	cppFlags.Clear();
	ldLibraries.Clear();
	staticLibraries.Clear();
	sharedLibraries.Clear();
}

String AndroidModuleMakeFile::ToString() const
{
	String makeFile;
	
	makeFile << "include $(CLEAR_VARS)\n";
	AppendName(makeFile);
	AppendSourceFiles(makeFile);
	AppendCppFlags(makeFile);
	AppendLdLibraries(makeFile);
	AppendStaticLibraries(makeFile);
	AppendSharedLibraries(makeFile);
	makeFile << "include $(BUILD_SHARED_LIBRARY)\n";
	
	return makeFile;
}

void AndroidModuleMakeFile::AddSourceFile(const String& path)
{
	sourceFiles.Add(path);
}

void AndroidModuleMakeFile::AddCppFlag(const String& name, const String& value)
{
	cppFlags.Add(name, value);
}

void AndroidModuleMakeFile::AddLdLibrary(const String& ldLibrary)
{
	ldLibraries.Add(ldLibrary);
}

void AndroidModuleMakeFile::AddStaticLibrary(const String& staticLibrary)
{
	staticLibraries.Add(staticLibrary);
}

void AndroidModuleMakeFile::AddSharedLibrary(const String& sharedLibrary)
{
	sharedLibraries.Add(sharedLibrary);
}

void AndroidModuleMakeFile::AppendName(String& makeFile) const
{
	makeFile << "LOCAL_MODULE := " << name << "\n";
}

void AndroidModuleMakeFile::AppendSourceFiles(String& makeFile) const
{
	AppendStringVector(makeFile, sourceFiles, "LOCAL_SRC_FILES");
}

void AndroidModuleMakeFile::AppendCppFlags(String& makeFile) const
{
	if(!cppFlags.IsEmpty()) {
		makeFile << "LOCAL_CPPFLAGS := ";
		for(int i = 0; i < cppFlags.GetCount(); i++) {
			String value = cppFlags[i];
			makeFile << "-D" << cppFlags.GetKey(i);
			if(!value.IsEmpty())
				makeFile << "=" << value;
			if(i + 1 < sourceFiles.GetCount())
				makeFile << " ";
		}
		makeFile << "\n";
	}
}

void AndroidModuleMakeFile::AppendLdLibraries(String& makeFile) const
{
	AppendStringVector(makeFile, ldLibraries, "LOCAL_LDLIBS", "-l");
}

void AndroidModuleMakeFile::AppendStaticLibraries(String& makeFile) const
{
	AppendStringVector(makeFile, staticLibraries, "LOCAL_STATIC_LIBRARIES");
}

void AndroidModuleMakeFile::AppendSharedLibraries(String& makeFile) const
{
	AppendStringVector(makeFile, sharedLibraries, "LOCAL_SHARED_LIBRARIES");
}

void AndroidModuleMakeFile::AppendStringVector(String& makeFile,
                                               const Vector<String>& vec, 
                                               const String& variableName,
                                               const String& variablePrefix) const
{
	if(!vec.IsEmpty()) {
		makeFile << variableName << " := ";
		for(int i = 0; i < vec.GetCount(); i++) {
			makeFile << variablePrefix << vec[i];
			if(i + 1 < vec.GetCount())
				makeFile << " ";
		}
		makeFile << "\n";
	}
}