topic "Id";
[2 $$0,0#00000000000000000000000000000000:Default]
[i448;a25;kKO9;2 $$1,0#37138531426314131252341829483380:class]
[l288;2 $$2,2#27521748481378242620020725143825:desc]
[0 $$3,0#96390100711032703541132217272105:end]
[H6;0 $$4,0#05600065144404261032431302351956:begin]
[i448;a25;kKO9;2 $$5,0#37138531426314131252341829483370:item]
[l288;a4;*@5;1 $$6,6#70004532496200323422659154056402:requirement]
[l288;i1121;b17;O9;~~~.1408;2 $$7,0#10431211400427159095818037425705:param]
[i448;b42;O9;2 $$8,8#61672508125594000341940100500538:tparam]
[b42;2 $$9,9#13035079074754324216151401829390:normal]
[{_} 
[ {{10000@(113.42.0) [s0;%% [*@7;4 Id]]}}&]
[s0;i448;a25;kKO9;@(0.0.255) &]
[s1;:Id`:`:class: [@(0.0.255)3 class][3 _][*3 Id][3 _:_][@(0.0.255)3 private][3 _][*@3;3 Moveable][3 <
][*3 Id][3 >_]&]
[s2;%% Id is simple wrapper over String class intended as `"identifier`" 
text. The main purpose for wrapping is overloading resolution 
in places where the distinction between text value and identifier 
is required.&]
[s3; &]
[s0;i448;a25;kKO9;@(0.0.255) &]
[ {{10000F(128)G(128)@1 [s0;%% [* Public Method List]]}}&]
[s0; &]
[s4; &]
[s5;:Id`:`:ToString`(`)const: [@(0.0.255) const]_[_^String^ String][@(0.0.255) `&]_[* ToStrin
g]()_[@(0.0.255) const]&]
[s2;%% Returns contained text.&]
[s3; &]
[s4; &]
[s5;:Id`:`:GetHashValue`(`)const: [_^dword^ dword]_[* GetHashValue]()_[@(0.0.255) const]&]
[s2;%% Returns hashing value.&]
[s3; &]
[s4; &]
[s5;:Id`:`:IsNull`(`)const: [@(0.0.255) bool]_[* IsNull]()_[@(0.0.255) const]&]
[s2;%% Returns true if empty.&]
[s3; &]
[s4; &]
[s5;:Id`:`:operator const String`&`(`)const: [* operator_const_String`&]()_[@(0.0.255) co
nst]&]
[s2;%% Same as ToString().&]
[s3; &]
[s4; &]
[s5;:Id`:`:operator`~`(`)const: [@(0.0.255) const]_[_^String^ String][@(0.0.255) `&]_[* opera
tor`~]()_[@(0.0.255) const]&]
[s2;%% Same as ToString().&]
[s3; &]
[s4; &]
[s5;:Id`:`:operator Value`(`)const: [* operator_Value]()_[@(0.0.255) const]&]
[s2;%% Converts Id to String Value.&]
[s3; &]
[s4; &]
[s5;:Id`:`:operator`=`=`(const Id`&`)const: [@(0.0.255) bool]_[* operator`=`=]([@(0.0.255) c
onst]_[_^Id^ Id][@(0.0.255) `&]_[*@3 b])_[@(0.0.255) const]&]
[s2;%% Returns true if both Id contain the same text.&]
[s3;%% &]
[s4;%% &]
[s5;:Id`:`:operator`!`=`(const Id`&`)const: [@(0.0.255) bool]_[* operator!`=]([@(0.0.255) c
onst]_[_^Id^ Id][@(0.0.255) `&]_[*@3 b])_[@(0.0.255) const]&]
[s2;%% Same as !operator`=`=([%-*@3 b]).&]
[s3;%% &]
[s4;%% &]
[s5;:Id`:`:operator bool`(`)const: [* operator_bool]()_[@(0.0.255) const]&]
[s2;%% Same as !IsNull().&]
[s3;%% &]
[s4;%% &]
[s5;:Id`:`:Id`(`): [* Id]()&]
[s2;%% Constructs Id with empty text.&]
[s3;%% &]
[s4;%% &]
[s5;:Id`:`:Id`(const String`&`): [* Id]([@(0.0.255) const]_[_^String^ String][@(0.0.255) `&]_
[*@3 s])&]
[s5;:Id`:`:Id`(const char`*`): [* Id]([@(0.0.255) const]_[@(0.0.255) char]_`*[*@3 s])&]
[s2;%% Constructs Id with text [%-*@3 s].&]
[s3;%% ]]