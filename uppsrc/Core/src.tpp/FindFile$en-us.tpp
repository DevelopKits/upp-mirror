topic "";
[2 $$0,0#00000000000000000000000000000000:Default]
[i448;a25;kKO9;2 $$1,0#37138531426314131252341829483380:class]
[l288;2 $$2,0#27521748481378242620020725143825:desc]
[0 $$3,0#96390100711032703541132217272105:end]
[H6;0 $$4,0#05600065144404261032431302351956:begin]
[i448;a25;kKO9;2 $$5,0#37138531426314131252341829483370:item]
[l288;a4;*@5;1 $$6,6#70004532496200323422659154056402:requirement]
[l288;i1121;b17;O9;~~~.1408;2 $$7,0#10431211400427159095818037425705:param]
[i448;b42;O9;2 $$8,8#61672508125594000341940100500538:tparam]
[b42;2 $$9,9#13035079074754324216151401829390:normal]
[{_}%EN-US 
[ {{10000@(113.42.0) [s0; [*@7;4 FindFile]]}}&]
[s0;i448;a25;kKO9;@(0.0.255)%- &]
[s1;:FindFile`:`:class:%- [@(0.0.255)3 class][3 _][*3 FindFile]&]
[s2; This class serves as platform independent encapsulation of directory 
enumeration.&]
[s0;i448;a25;kKO9;@(0.0.255)%- &]
[ {{10000F(128)G(128)@1 [s0; [* Public Method List]]}}&]
[s3;%- &]
[s5;:FindFile`:`:Search`(const char`*`):%- [@(0.0.255) bool]_[* Search]([@(0.0.255) const]_
[@(0.0.255) char]_`*[*@3 path])&]
[s2; Starts a new listing. [%-*@3 path] can contain wildcards (`'`*`', 
`'?`') to list more than single file. Returns true if first file 
is found.&]
[s3; &]
[s4; &]
[s5;:FindFile`:`:Next`(`):%- [@(0.0.255) bool]_[* Next]()&]
[s2; Attemts to iterate to the next file, returns true if successful.&]
[s3; &]
[s4; &]
[s5;:FindFile`:`:GetAttributes`(`)const:%- [_^dword^ dword]_[* GetAttributes]()_[@(0.0.255) c
onst]&]
[s6;%- `[Win32`]&]
[s2; Returns win32 attributes of file.&]
[s3; &]
[s4; &]
[s5;:FindFile`:`:GetName`(`)const:%- [_^String^ String]_[* GetName]()_[@(0.0.255) const]&]
[s2; Returns the name of current directory entry.&]
[s3; &]
[s4; &]
[s5;:FindFile`:`:GetLength`(`)const:%- [_^int64^ int64]_[* GetLength]()_[@(0.0.255) const]&]
[s2; Returns the length of current file. Undefined if current directory 
entry is not file.&]
[s3; &]
[s4; &]
[s5;:FindFile`:`:GetCreationTime`(`)const:%- [_^FileTime^ FileTime]_[* GetCreationTime]()
_[@(0.0.255) const]&]
[s6; `[Win32`]&]
[s2; Returns Win32 creation time. Does not work with all filesystems.&]
[s3; &]
[s4; &]
[s5;:FindFile`:`:GetLastAccessTime`(`)const:%- [_^FileTime^ FileTime]_[* GetLastAccessTim
e]()_[@(0.0.255) const]&]
[s2; Returns the last time the entry was accessed. Does not work 
with all filesystems.&]
[s3; &]
[s4; &]
[s5;:FindFile`:`:GetLastWriteTime`(`)const:%- [_^FileTime^ FileTime]_[* GetLastWriteTime](
)_[@(0.0.255) const]&]
[s2; Returns the last time the entry was modified. Always works.&]
[s3; &]
[s4; &]
[s5;:FindFile`:`:GetLastChangeTime`(`)const:%- [_^FileTime^ FileTime]_[* GetLastChangeTim
e]()_[@(0.0.255) const]&]
[s6; `[POSIX`]&]
[s2; Returns the last change time (st`_ctime member of stat structure).&]
[s3; &]
[s4; &]
[s5;:FindFile`:`:IsDirectory`(`)const:%- [@(0.0.255) bool]_[* IsDirectory]()_[@(0.0.255) co
nst]&]
[s2; Returns true if entry is a directory. Note that FindFile returns 
`'..`' and `'.`' pseudo`-directories in the listing (on both 
platforms), these return true as well.&]
[s3; &]
[s4; &]
[s5;:FindFile`:`:IsFolder`(`)const:%- [@(0.0.255) bool]_[* IsFolder]()_[@(0.0.255) const]&]
[s2; Returns true if entry is a directory, but [* not] `'..`' nor `'.`'.&]
[s3; &]
[s4; &]
[s5;:FindFile`:`:IsFile`(`)const:%- [@(0.0.255) bool]_[* IsFile]()_[@(0.0.255) const]&]
[s2; Returns true if entry is a file.&]
[s3; &]
[s4; &]
[s5;:FindFile`:`:IsArchive`(`)const:%- [@(0.0.255) bool]_[* IsArchive]()_[@(0.0.255) const]&]
[s6; `[Win32`]&]
[s2; Returns true if entry has archive flag set.&]
[s3; &]
[s4; &]
[s5;:FindFile`:`:IsCompressed`(`)const:%- [@(0.0.255) bool]_[* IsCompressed]()_[@(0.0.255) c
onst]&]
[s6; `[Win32`]&]
[s2; Returns true if entry has compressed flag set.&]
[s3; &]
[s4; &]
[s5;:FindFile`:`:IsHidden`(`)const:%- [@(0.0.255) bool]_[* IsHidden]()_[@(0.0.255) const]&]
[s6; `[Win32`]&]
[s2; Returns true if entry has hidden flag set.&]
[s3; &]
[s4; &]
[s5;:FindFile`:`:IsReadOnly`(`)const:%- [@(0.0.255) bool]_[* IsReadOnly]()_[@(0.0.255) cons
t]&]
[s2; Returns true if entry is read only (in current user context).&]
[s3; &]
[s4; &]
[s5;:FindFile`:`:IsSystem`(`)const:%- [@(0.0.255) bool]_[* IsSystem]()_[@(0.0.255) const]&]
[s6; `[Win32`]&]
[s2; Returns true if entry has system flag set.&]
[s3; &]
[s4; &]
[s5;:FindFile`:`:IsTemporary`(`)const:%- [@(0.0.255) bool]_[* IsTemporary]()_[@(0.0.255) co
nst]&]
[s6; `[Win32`]&]
[s2; Returns true if entry has system flag set.&]
[s3; &]
[s4; &]
[s5;:FindFile`:`:IsSymLink`(`)const:%- [@(0.0.255) bool]_[* IsSymLink]()_[@(0.0.255) const]&]
[s6; `[POSIX`]&]
[s2; Returns true if entry is POSIX symlink.&]
[s3; &]
[s4; &]
[s5;:FindFile`:`:GetMode`(`)const:%- [_^dword^ dword]_[* GetMode]()_[@(0.0.255) const]&]
[s6; `[POSIX`]&]
[s2; Returns UNIX access mode.&]
[s3; &]
[s4; &]
[s5;:FindFile`:`:operator bool`(`)const:%- [* operator_bool]()_[@(0.0.255) const]&]
[s2; Returns true if there is current entry in FindFile (if false, 
all entry information methods have undefined behaviour). Usually, 
this is used as condition to the loop that enumerates directory.&]
[s3; &]
[s0; &]
[ {{10000F(128)G(128)@1 [s0; [* Constructor detail]]}}&]
[s3; &]
[s5;:FindFile`:`:FindFile`(`):%- [* FindFile]()&]
[s2; Initializes to empty state.&]
[s3; &]
[s4; &]
[s5;:FindFile`:`:FindFile`(const char`*`):%- [* FindFile]([@(0.0.255) const]_[@(0.0.255) ch
ar]_`*[*@3 name])&]
[s2; Initializes and performs Search([%-*@3 name]).&]
[s3; ]