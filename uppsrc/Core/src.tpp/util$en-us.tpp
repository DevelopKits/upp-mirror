topic "Miscellaneous";
[2 $$0,0#00000000000000000000000000000000:Default]
[i448;a25;kKO9;2 $$1,0#37138531426314131252341829483380:class]
[l288;2 $$2,0#27521748481378242620020725143825:desc]
[0 $$3,0#96390100711032703541132217272105:end]
[H6;0 $$4,0#05600065144404261032431302351956:begin]
[i448;a25;kKO9;2 $$5,0#37138531426314131252341829483370:item]
[l288;a17;*@5;1 $$6,6#70004532496200323422659154056402:requirement]
[l288;i1121;b17;O9;~~~.1408;2 $$7,0#10431211400427159095818037425705:param]
[{_}%EN-US 
[s0; Miscellaneous&]
[s0; &]
[s0;%- class_[* Exc]&]
[s2; &]
[s2; This is the preferred root class of U`+`+ exception. It is basically 
a String. The idea is that all kinds of exception can be either 
managed by specific handlers, or simple Exc handler can be used, 
displaying textual information to the user.&]
[s2; &]
[s0;%- [%%/ Derived from][%%  ]String&]
[s0;3 &]
[s0;:`:`:Exc`:`:Exc`(`):%- [* Exc]()&]
[s2; Default constructor.&]
[s0;3 &]
[s0;:`:`:Exc`:`:Exc`(const`:`:String`&`):%- [* Exc](const_String`&_[*@3 desc])&]
[s2; Constructor from String.&]
[s7; [%-*C@3 desc]-|Description of error.&]
[s0; &]
[s0; ]