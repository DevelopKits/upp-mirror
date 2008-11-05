topic "Text formatting";
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
[s0; [*+117 Format `- text formatting]&]
[s0;*+117 &]
[s5;:`:`:Format`(const char`*`,const`:`:Vector`<`:`:Value`>`&`):%- [^`:`:String^ String
]_[* Format][@(64) (][@(0.0.255) const][@(64) _][@(0.0.255) char][@(64) _`*][*@3 format][@(64) , 
][@(0.0.255) const][@(64) _][^`:`:Vector^@(64) Vector][@(64) <][^`:`:Value^@(64) Value][@(64) >
`&_][*@3 args][@(64) )]&]
[s5;%- [^`:`:String^ String]_[* Format][@(64) (][@(0.0.255) const][@(64) _][@(0.0.255) char][@(64) _
`*][*@3 format][@(64) , ][^`:`:Value^@(64) Value][@(64) _][*@3 arg][*,@3 1][*@3  
][@4 `[], [^`:`:Value^@(64) Value][@(64) _][*@3 arg][*,@3 n][@4 `]...] [@(64) )]&]
[s5;:Format`(int`,const char`*`,const Vector`<Value`>`&`):%- [^String^ String]_[* Format](
[@(0.0.255) int]_[*@3 language], [@(0.0.255) const]_[@(0.0.255) char]_`*[*@3 s], 
[@(0.0.255) const]_Vector[@(0.0.255) <]Value[@(0.0.255) >`&]_[*@3 v])&]
[s5;%- [^`:`:String^ String]_[* Format][@(64) (][@(0.0.255) int][@(64) _][*@3 language][@(64) , 
][@(0.0.255) const][@(64) _][@(0.0.255) char][@(64) _`*][*@3 format][@(64) , 
][^`:`:Value^@(64) Value][@(64) _][*@3 arg][*,@3 1][*@3  ][@4 `[], [^`:`:Value^@(64) Value][@(64) _
][*@3 arg][*,@3 n][@4 `]...] [@(64) )]&]
[s2; &]
[s0; Format forms output text based on [*@3 format], inserting actual 
arguments to placeholders. Argument values are converted to text 
using formatters. U`+`+ specifies set of standard formatters; 
application can freely register their own formatters for specific 
Value types too.&]
[s0; &]
[s0; Note that the variable number of Value arguments is implemented 
by overloading the Format up to 20 parameters.&]
[s0; &]
[s0; Placeholders start with [* %] and have format:&]
[s0; &]
[s0; [* %][*@4 `[][*@(0.0.255) commands][*@4 `]`[][*@(0.0.255) options][*@4 `]`[][*@(0.0.255) forma
tter`-id][*@4 `]`[][*@(0.0.255) ``][*@4 `]]&]
[s0; &]
[s0; [*@(0.0.255) commands] are interpreted by Format routine (not 
specific formatter). Each command sequence ends with character 
specifying the kind of command, this delimits it from options 
and/or formatter.&]
[s0; &]
[s0; Available commands:&]
[s0; &]
[ {{1785:8215^ [s0; [*/@(0.0.255) position][* :]]
::= [s0; Seeks to an argument at [*/@(0.0.255) position]. Allows to `"reorganize`" 
ordering of arguments, useful with translations.]
::^ [s0; [*/@(0.0.255) width][* <]]
::= [s0; Places formatter result into field with [*/@(0.0.255) width] characters, 
aligns left.]
::^ [s0; [*/@(0.0.255) width][* >]]
::= [s0; Places formatter result into field with [*/@(0.0.255) width] characters, 
aligns right.]
::^ [s0; [*/@(0.0.255) width][* `=]]
::= [s0; Places formatter result into field with [*/@(0.0.255) width] characters, 
aligns to center.]
::^ [s0; [* `[][*/@(0.0.255) text][* `]`~]]
::= [s0; If argument is [* Null], uses [*/@(0.0.255) text] instead of formatter 
result.]}}&]
[s0; &]
[s0; [*@(0.0.255) formatter`-id][*  ]must consist of alpha characters 
only, unlike C identifiers, digits or `'`_`' are not allowed. 
Everything between [*@(0.0.255) commands] and [*@(0.0.255) formatter`-id] 
is considered to be [*@(0.0.255) options] and passed to formatter. 
Note that [*@(0.0.255) formatter`-id] is Value type specific `- 
the same name can specify different formatter depending on Value 
type. [*@(0.0.255) formatter`-id] is case`-sensitive.&]
[s0; &]
[s0; Character [* `*] in [*@(0.0.255) options] section is replaced by 
argument converted using AsString.&]
[s0; &]
[s0; If [*@(0.0.255) options] are to contain alpha characters, they 
need to be escaped using [* `[ `]] to distinguish options from 
formatter`-id.&]
[s0; &]
[s0; Placeholder can end either by non`-alpha character or by [* ``]. 
formatter`-id can be left empty; in that case Format uses AsString 
to convert Value to text (defined in RichValue interface) `- 
the most trivial placeholder is therefore [* %``].&]
[s0; &]
[s0; While Format implements all of classic printf formatter, please 
notice two incompatibilities:&]
[s0; &]
[s0;i150;O0; All arguments of Format must be convertible (and are 
converted) to Value. On the positive side, Value performs natural 
conversions like double `-> int, so it is possible to e.g. use 
%d for double value.&]
[s0; &]
[s0;i150;O0; formatter`-id `"eats`" all alpha characters. This is 
a problem when non`-placeholder alpha character is to follow 
placeholder, e.g. %dpt `- this has to be written as %d``pt (`` 
delimits the formatter`-id).&]
[s0; &]
[s0; &]
[s0; [*/ Standard formatters]&]
[s0; &]
[s0; [* default formatter]&]
[s0; &]
[s0; If formatter`-id is empty, Value is converted using AsString 
(implemented in RichValue interface).&]
[s0; &]
[s0; &]
[s0; [* printf formatters]&]
[s0; &]
[s0; Most printf formatters are supported:&]
[s0; &]
[s0; [* c d i o x X ld li lo lx lX e E f g G s]&]
[s0; &]
[s0; Please refer to printf documentation for the description.&]
[s0; &]
[s0; &]
[s0; [* switch formatter]&]
[s0; &]
[s0; This is special number formatter (registered for double, int 
and int64 values). [*@(0.0.255) options] of switch formatter contain 
a list of values and respective texts `- a text for actual argument 
is printed. [*@(0.0.255) formatter`-id] is [* s].&]
[s0; &]
[s0; The format of switch [*@(0.0.255) options] is&]
[s0; &]
[s0; [*@4 `[][*@(0.0.255) modulo][* %][*@4 `]`[][*@(0.0.255) case][* :][*@(0.0.255) text];[*@4 `]...`[
][*@(0.0.255) default][*@4 `]]&]
[s0; &]
[ {{1395:8605 [s0; [*@(0.0.255) modulo]]
:: [s0; If this optional part is present, modulo of argument is used 
for switch cases.]
:: [s0; [*@(0.0.255) case]]
:: [s0; Numeric case.]
:: [s0; [*@(0.0.255) text]]
:: [s0; Text for given numeric case.]
:: [s0; [*@(0.0.255) default]]
:: [s0; Default text when no case is matched.]}}&]
[s0; &]
[s0; Note that as text usually contains letters, whole switch options 
section is almost always escaped using [* `[] [* `]].&]
[s0; &]
[s0; &]
[s0; [* simple integer formatters]&]
[s0; &]
[s0; These formatters are registered for double, int and int64 values.&]
[s0; &]
[ {{1426:8574h1;@(204) [s0; [*@(0.0.255) formatter`-id]]
:: [s0; Description]
::@2 [s0;%- [* month]]
:: [s0; [C Lower`-case month name.]]
:: [s0;%- [* Month]]
:: [s0; [C Month name with first letter upper`-case, rest lower`-case.]]
:: [s0;%- [* MONTH]]
:: [s0; [C Upper`-case month name.]]
:: [s0;%- [* mon]]
:: [s0; [C Abbreviated lower`-case month name.]]
:: [s0;%- [* Mon]]
:: [s0; [C Abbreviated month name, first letter upper`-case, rest lower`-case.]]
:: [s0;%- [* MON]]
:: [s0; [C Abbreviated upper`-case month name.]]
:: [s0;%- [* day]]
:: [s0; [C Lower`-case day name.]]
:: [s0;%- [* Day]]
:: [s0; [C Day name with first letter upper`-case, rest lower`-case.]]
:: [s0;%- [* DAY]]
:: [s0; [C Upper`-case day name.]]
:: [s0;%- [* dy]]
:: [s0; [C Abbreviated lower`-case day name.]]
:: [s0;%- [* Dy]]
:: [s0; [C Abbreviated day name, first letter upper`-case, rest lower`-case.]]
:: [s0;%- [* DY]]
:: [s0; [C Abbreviated upper`-case day name.]]
:: [s0;%- [* tw]]
:: [s0; [C 12`-hour modulo format.]]
:: [s0;%- [* a]]
:: [s0; [C Letter format, 1: a, 2: b, ... 26: z, 27: aa, ...]]
:: [s0;%- [* A]]
:: [s0; [C Letter format, 1: a, 2: b, ... 26: z, 27: aa, ...]]
:: [s0;%- [* r]]
:: [s0; [C Lower`-case roman numbers.]]
:: [s0;%- [* R]]
:: [s0; [C Upper`-case roman numbers.]]}}&]
[s0; &]
[s0; &]
[s0; [* alternate real number formatters]&]
[s0; &]
[s0;O9;~~~.352; [* n]-|fixed decimals&]
[s0;O9;~~~.352; [* v]-|valid decimals&]
[s0;O9;~~~.352; [* ne], [* ve]-|force exponential notation&]
[s0;O9;~~~.352; [* nf], [* vf]-|force fixed notation&]
[s0;O9;~~~.352; [* nl], [* vl]-|language`-based formatting&]
[s0; &]
[s0; The format of [*@(0.0.255) options] is&]
[s0; &]
[s0; [*@4 `[][* `+][*@4 `]`[`[][* `-][*@4 `]][*@(0.0.255) digits][*@4 `]`[][* !][*@4 `]`[][* `^][*@4 `[][* `+
][*@4 `]][*@(0.0.255) expdig][*@4 `]]&]
[s0; &]
[s0;O9;~~~.576; `+-|always prepend sign&]
[s0;O9;~~~.576; [*@4 `[][* `-][*@4 `]][*@(0.0.255) digits][@(0.0.255) -|]number 
of decimals to print (negative `= left of decimal point, default 
`= 6)&]
[s0;O9;~~~.576; [* !]-|keep insignificant zeros&]
[s0;O9;~~~.576; [* `^]-|exponent options:&]
[s0;l160;O9;~~~.640; [* `+]-|always prepend sign to exponent&]
[s0;l160;O9;~~~.640; [*@(0.0.255) expdig][@(0.0.255) -|]exponent padding 
width&]
[s0; &]
[s0; &]
[s0; &]
[s0;%- [*/ Examples of standard formatters]&]
[s0; &]
[ {{5311:4689 [s0;%- Format(`"[* %d], [* %s]`", 123, `"TEXT`")]
:: [s0;%- [C 123, TEXT]]
:: [s0;%- Format(`"[* %2:s], [* %1:d]`", 123, `"TEXT`")]
:: [s0;%- [C TEXT, 123]]
:: [s0;%- Format(`"[* %010d]`", 123)]
:: [s0;%- [C 0000000123]]
:: [s0;%- Format(`"[* %0`*d]`", 11, 123)]
:: [s0;%- [C 00000000123]]
:: [s0;%- Format(`"`|[* %20<d]`|`", 123)]
:: [s0;%- [C `|123                 `|]]
:: [s0;%- Format(`"`|[* %20>d]`|`", 123)]
:: [s0;%- [C `|                 123`|]]
:: [s0;%- Format(`"`|[* %20`=d]`|`", 123)]
:: [s0;%- [C `|        123         `|]]
:: [s0;%- Format(`"[* %d``]pt`", 123)]
:: [s0;%- [C 123pt]]
:: [s0;%- Format(`"[* %`[empty`]`~d], [* %`[empty`]`~d]`", 123, Null)]
:: [s0;%- [C 123, empty]]
:: [s0;%- Format(`"[* %``]`", 123)]
:: [s0;%- [C 123]]
:: [s0;%- Format(`"[* %c]`", 65)]
:: [s0;%- [C A]]
:: [s0;%- Format(`"[* %d]`", 123)]
:: [s0;%- [C 123]]
:: [s0;%- Format(`"[* %i]`", 123)]
:: [s0;%- [C 123]]
:: [s0;%- Format(`"[* %o]`", 123)]
:: [s0;%- [C 173]]
:: [s0;%- Format(`"[* %x]`", 123)]
:: [s0;%- [C 7b]]
:: [s0;%- Format(`"[* %X]`", 123)]
:: [s0;%- [C 7B]]
:: [s0;%- Format(`"[* %e]`", 1.23)]
:: [s0;%- [C 1.230000e`+000]]
:: [s0;%- Format(`"[* %E]`", 1.23)]
:: [s0;%- [C 1.230000E`+000]]
:: [s0;%- Format(`"[* %f]`", 1.23)]
:: [s0;%- [C 1.230000]]
:: [s0;%- Format(`"[* %g]`", 1.23)]
:: [s0;%- [C 1.23]]
:: [s0;%- Format(`"[* %G]`", 1.23)]
:: [s0;%- [C 1.23]]
:: [s0;%- Format(`"[* %n]`", 1.23)]
:: [s0;%- [C 1.23]]
:: [s0;%- Format(`"[* %1n]`", 1.23)]
:: [s0;%- [C 1.2 ][/ (explicit number of decimals)]]
:: [s0;%- Format(`"[* %3!n]`", 1.23)]
:: [s0;%- [C 1.230 ][/ (force insignificant zeros)]]
:: [s0;%- Format(`"[* %ne]`", 1.23)]
:: [s0;%- [C 1.23e0]]
:: [s0;%- Format(`"[* %2`^`+3ne]`", 1.23)]
:: [s0;%- [C 1.2e`+000 ][/ (exponent formatting)]]
:: [s0;%- Format(`"[* %nf]`", 1.23e30)]
:: [s0;%- [C 1230000000000000000000000000000]]
:: [s0;%- Format(`"[* %nl]`", 1.23)]
:: [s0;%- [C 1,23]]
:: [s0;%- Format(`"[* %v]`", 1.23)]
:: [s0;%- [C 1.23]]
:: [s0;%- Format(`"[* %2v]`", 1.23)]
:: [s0;%- [C 1.2 ][/ (2 valid digits)]]
:: [s0;%- Format(`"[* %2v]`", 123)]
:: [s0;%- [C 120 ][/ (2 valid digits)]]
:: [s0;%- Format(`"[* %ve]`", 1.23)]
:: [s0;%- [C 1.23e0]]
:: [s0;%- Format(`"[* %vf]`", 1.23e30)]
:: [s0;%- [C 1230000000000000000000000000000]]
:: [s0;%- Format(`"[* %vl]`", 1.23)]
:: [s0;%- [C 1,23]]
:: [s0;%- Format(`"[* %`[1:one;2:two;3:three;another`]s]`", 2)]
:: [s0;%- [C two]]
:: [s0;%- Format(`"[* %`[1:one;2:two;3:three;another`]s]`", 20)]
:: [s0;%- [C another]]
:: [s0;%- Format(`"[* %`[3%1:one;2:two;3:three;another`]s]`", 20)]
:: [s0;%- [C two]]
:: [s0;%- Format(`"[* %month]`", 6)]
:: [s0;%- [C june]]
:: [s0;%- Format(`"[* %Month]`", 6)]
:: [s0;%- [C June]]
:: [s0;%- Format(`"[* %MONTH]`", 6)]
:: [s0;%- [C JUNE]]
:: [s0;%- Format(`"[* %mon]`", 6)]
:: [s0;%- [C jun]]
:: [s0;%- Format(`"[* %Mon]`", 6)]
:: [s0;%- [C Jun]]
:: [s0;%- Format(`"[* %MON]`", 6)]
:: [s0;%- [C JUN]]
:: [s0;%- Format(`"[* %day]`", 6)]
:: [s0;%- [C saturday]]
:: [s0;%- Format(`"[* %Day]`", 6)]
:: [s0;%- [C Saturday]]
:: [s0;%- Format(`"[* %DAY]`", 6)]
:: [s0;%- [C SATURDAY]]
:: [s0;%- Format(`"[* %dy]`", 6)]
:: [s0;%- [C sa]]
:: [s0;%- Format(`"[* %Dy]`", 6)]
:: [s0;%- [C Sa]]
:: [s0;%- Format(`"[* %DY]`", 6)]
:: [s0;%- [C SA]]
:: [s0;%- Format(`"[* %tw]`", 0)]
:: [s0;%- [C 12]]
:: [s0;%- Format(`"[* %tw]`", 5)]
:: [s0;%- [C 5]]
:: [s0;%- Format(`"[* %tw]`", 15)]
:: [s0;%- [C 3]]
:: [s0;%- Format(`"[* %0tw]`", 15)]
:: [s0;%- [C 03]]
:: [s0;%- Format(`"[* %a]`", 1)]
:: [s0;%- [C a]]
:: [s0;%- Format(`"[* %a]`", 123)]
:: [s0;%- [C es]]
:: [s0;%- Format(`"[* %A]`", 1)]
:: [s0;%- [C A]]
:: [s0;%- Format(`"[* %A]`", 123)]
:: [s0;%- [C ES]]
:: [s0;%- Format(`"[* %r]`", 8)]
:: [s0;%- [C viii]]
:: [s0;%- Format(`"[* %R]`", 1231)]
:: [s0;%- [C MCCXXXI]]
:: [s0;%- Format(`"[* %``]`", GetSysDate())]
:: [s0;%- [C 08/25/2006]]
:: [s0;%- Format(`"[* %``]`", GetSysTime())]
:: [s0;%- [C 08/25/2006 20:37:09]]
:: [s0;%- Format(`"[* %``]`", `"text`")]
:: [s0;%- [C text]]
:: [s0;%- Format(`"[* %``]`", GetSysDate())]
:: [s0;%- [C 25.08.2006]]}}&]
[s0; &]
[s0; &]
[s0; &]
[s0;%- [*+117 Registering custom formatters]&]
[s0; &]
[s5;:Formatter`:`:typedef:%- typedef_[^String^ String]_(`*Formatter)([@(0.0.255) const][@(64) _
][^Formatting^@(64) Formatting][@(64) `&_fmt)]&]
[s2; Formatter has to have form of function with single [^Formatting^ Formatting] 
argument.&]
[s0; &]
[ {{10000F(128)G(128)@1 [s0; [* Formatting]]}}&]
[s0;%- &]
[s1;:Formatting`:`:struct:%- [@(0.0.255) struct]_[* Formatting]&]
[s2; This structure passes all informations to format Value argument 
to the formatter.&]
[s3;%- &]
[s4;%- &]
[s5;:FormatInt`(int`):%- [_^String^ String]_[* FormatInt]([@(0.0.255) int]_[*@3 i])&]
[s2; Outputs decimally formatted signed integer without `+ or any 
paddings. Supposed to be quite fast. Equivalent to FormatIntBase(i, 
10).&]
[s2; &]
[s0;l288;O9;~~~.640; [* i]-|the number to format.&]
[s3; [* v]&]
[s4;%- &]
[s5;:FormatIntDec`(int`,int`,char`,bool`):%- [_^String^ String]_[* FormatIntDec]([@(0.0.255) i
nt]_[*@3 i], [@(0.0.255) int]_[*@3 width], [@(0.0.255) char]_[*@3 lpad]_`=_`'_`', 
[@(0.0.255) bool]_[*@3 always`_sign]_`=_[@(0.0.255) false])&]
[s0;l288; Formats a signed decimal integer (i) with left padding 
up to given (width) characters with a given (lpad) character.&]
[s0;l288; &]
[s0;l288;O9;~~~.1152; [* i]-|the number to format.&]
[s0;l288;O9;~~~.1152; [* width]-|left padding width (output longer than 
this is not padded)&]
[s0;l288;O9;~~~.1152; [* lpad]-|character to left pad output with&]
[s2;~~~.1152; [* always`_sign]-|true `= start positive numbers with 
`[`+`], false `= just negative with `[`-`]&]
[s3; &]
[s4;%- &]
[s5;:FormatIntHex`(int`,int`,char`):%- [_^String^ String]_[* FormatIntHex]([@(0.0.255) int]_
[*@3 i], [@(0.0.255) int]_[*@3 width]_`=_[@3 8], [@(0.0.255) char]_[*@3 lpad]_`=_`'[@3 0]`')&]
[s0;l288; Formats an unsigned hexadecimal (radix 16) integer (i) 
with left padding up to given (width) characters with a given 
(lpad) character.&]
[s0;l288; &]
[s0;l288;O9;~~~.1152; [* i]-|the number to format.&]
[s0;l288;O9;~~~.1152; [* width]-|left padding width (output longer than 
this is not padded)&]
[s2;~~~.1152; [* lpad]-|character to left pad output with&]
[s4;%- &]
[s5;:FormatIntOct`(int`,int`,char`):%- [_^String^ String]_[* FormatIntOct]([@(0.0.255) int]_
[*@3 i], [@(0.0.255) int]_[*@3 width]_`=_[@3 12], [@(0.0.255) char]_[*@3 lpad]_`=_`'[@3 0]`')&]
[s0;l288; Formats an unsigned octal (radix 8) integer (i) with left 
padding up to given (width) characters with a given (lpad) character 
(usually a space or 0).&]
[s0;l288; &]
[s0;l288;O9;~~~.1152; [* i]-|the number to format.&]
[s0;l288;O9;~~~.1152; [* width]-|left padding width (output longer than 
this is not padded)&]
[s0;l288;O9;~~~.1152; [* lpad]-|character to left pad output with&]
[s3; &]
[s4;%- &]
[s5;:FormatIntRoman`(int`,bool`):%- [_^String^ String]_[* FormatIntRoman]([@(0.0.255) int]_
[*@3 i], [@(0.0.255) bool]_[*@3 upper]_`=_[@(0.0.255) false])&]
[s0;l288; Formats a signed integer in Roman numerals. The biggest 
`"implemented`" numeral is M (1000), so expect quite a long return 
string when formatting a billion. Negative numbers are prepended 
with `[`-`], 0 or Null is output as a Null String.&]
[s0;l288; &]
[s0;l288;O9;~~~.1152; [* i]-|the number to format.&]
[s0;l288;O9;~~~.1152; [* upper]-|use uppercase `[true`] or lowercase 
`[false`] letters&]
[s0;l288;O9;~~~.1152;* &]
[s3; &]
[s4;%- &]
[s5;:FormatIntAlpha`(int`,bool`):%- [_^String^ String]_[* FormatIntAlpha]([@(0.0.255) int]_
[*@3 i], [@(0.0.255) bool]_[*@3 upper]_`=_[@(0.0.255) true])&]
[s0;l288; Formats a signed integer in length`-first lexicographic 
index, i.e. excel column numbering (1 `= A,2 `= B..  26 `= Z, 
27 `= AA, 28 `= AB .. 52 `= AZ, 53 `= BA ... 78 `= BZ etc). 0 
or Null is output as a Null String. Only negative numbers are 
prepended with a `[`-`].&]
[s0;l288; &]
[s0;l288;O9;~~~.1152; [* i]-|the number to format.&]
[s0;l288;O9;~~~.1152; [* upper]-|use uppercase `[true`] or lowercase 
`[false`] letters&]
[s0;l288;O9;~~~.1152;* &]
[s3; &]
[s4;%- &]
[s5;:Format64`(uint64`):%- [_^String^ String]_[* Format64]([_^uint64^ uint64]_[*@3 a])&]
[s2; Formats an unsigned decimal 64`-bit integer. Supposed to be 
quite fast.&]
[s2; &]
[s0;l288;O9;~~~.1152; [* a]-|the number to format.&]
[s3; &]
[s4;%- &]
[s5;:Format64Hex`(uint64`):%- [_^String^ String]_[* Format64Hex]([_^uint64^ uint64]_[*@3 a])&]
[s2; Formats an unsigned hexadecimal (radix 16) 64`-bit integer. 
Supposed to be quite fast. Lowecase letters a`-f are used for 
digits `[10`] through `[15`].&]
[s2; &]
[s0;l288;O9;~~~.1152; [* a]-|the number to format.&]
[s3; &]
[s4;%- &]
[s5;:FormatIntHex`(const void`*`):%- [_^String^ String]_[* FormatIntHex]([@(0.0.255) const]_
[@(0.0.255) void]_`*[*@3 ptr])&]
[s2; Formats the pointer address as a hexadecimal (base 16) number 
zero`-padded to the number of digits appropriate for the memory 
model (8 digits in 32`-bit systems, 16 digits in 64`-bit systems). 
Useful for logging and debugging purposes. Equivalent to FormatHex, 
god knows why there are two of them.&]
[s2; &]
[s0;l288;O9;~~~.1152; [* ptr]-|the number to format.&]
[s3; &]
[s4;%- &]
[s5;:FormatHex`(const void`*`):%- [_^String^ String]_[* FormatHex]([@(0.0.255) const]_[@(0.0.255) v
oid]_`*[*@3 ptr])&]
[s2; Formats the pointer address as a hexadecimal (base 16) number 
zero`-padded to the number of digits appropriate for the memory 
model (8 digits in 32`-bit systems, 16 digits in 64`-bit systems). 
Useful for logging and debugging purposes. Equivalent to FormatIntHex.&]
[s2; &]
[s0;l288;O9;~~~.1152; [* ptr]-|the number to format.&]
[s3; &]
[s4;%- &]
[s5;:FormatInteger`(int`):%- [_^String^ String]_[* FormatInteger]([@(0.0.255) int]_[*@3 a])&]
[s2; Formats a signed decimal integer without padding. In comparison 
to FormatInt it returns String(Null) when given int(Null) whereas 
FormatInt returns a plain empty string, hah.&]
[s2; &]
[s0;l288;O9;~~~.1152; [* ptr]-|the number to format.&]
[s3; &]
[s4;%- &]
[s5;:FormatUnsigned`(unsigned long`):%- [_^String^ String]_[* FormatUnsigned]([@(0.0.255) u
nsigned]_[@(0.0.255) long]_[*@3 a])&]
[s2; A very old freak, implemented through Sprintf(`"%u`", a). Definitely 
deprecated, I hope.&]
[s2; &]
[s0;l288;O9;~~~.1152; [* a]-|the number to format.&]
[s3; &]
[s4;%- &]
[s5;:FormatDouble`(double`):%- [_^String^ String]_[* FormatDouble]([@(0.0.255) double]_[*@3 a
])&]
[s2; Formats a floating point in decimal notation automatically selecting 
ordinary or scientific (exponential) notation according to the 
absolute value of a. In ordinary notation, the number is formatted 
to 10 significant digits; in exponential notation, the mantissa 
is formatted to 10 decimal digits.&]
[s2; &]
[s0;l288;O9;~~~.1152; [* a]-|the number to format.&]
[s3; &]
[s4;%- &]
[s5;:FormatBool`(bool`):%- [_^String^ String]_[* FormatBool]([@(0.0.255) bool]_[*@3 a])&]
[s2; Formats a boolean as one of the fixed words `"true`" or `"false`" 
(regardless of language settings).&]
[s0; &]
[s0;l288;O9;~~~.1152; [* a]-|the logical value to format.&]
[s3; &]
[s4;%- &]
[s5;:FormatInt64`(int64`):%- [_^String^ String]_[* FormatInt64]([_^int64^ int64]_[*@3 a])&]
[s2; Formats a signed decimal 64`-bit integer without any padding. 
Only negative numbers are prepended with a `[`-`].&]
[s0; &]
[s0;l288;O9;~~~.1152; [* a]-|the number to format&]
[s3; &]
[s4;%- &]
[s5;:FormatDouble`(double`,int`,int`,int`):%- [_^String^ String]_[* FormatDouble]([@(0.0.255) d
ouble]_[*@3 d], [@(0.0.255) int]_[*@3 digits], [@(0.0.255) int]_[*@3 flags]_`=_[@3 0], 
[@(0.0.255) int]_[*@3 fill`_exp]_`=_[@3 0])&]
[s2; Formats a floating point in decimal notation automatically selecting 
ordinary or scientific (exponential) notation according to the 
absolute value of a and the given number of digits. In the (default) 
absolute decimal mode, a number is formatted in exponential notation 
whenever its absolute value exceeds the interval `[1e`-15, 1e`+15`]; 
in relative (significant) decimal mode (FD`_REL), a number is 
formatted in exponential notation whenever its absolute value 
exceeds the interval `[10`^`-<2 `* digits>, 10`^`+<2 `* digits>`].&]
[s2; &]
[s0;l288;O9;~~~.1152; [* d]-|the number to format&]
[s0;l288;O9;~~~.1152; [* digits]-|number of digits&]
[s0;l288;O9;~~~.1152; [* flags]-|formatting flags, can be or`-ed (`|) 
together:&]
[s0;l704;O9;~~~.1472; [/@(90) FD`_SIGN-|always prepend sign (`+10)]&]
[s0;l704;O9;~~~.1472; [/@(90) FD`_REL-|relative decimal places (valid 
digits)]&]
[s0;l704;O9;~~~.1472; [/@(90) FD`_SIGN`_EXP-|always prepend sign to 
exponent (1e`+2)]&]
[s0;l704;O9;~~~.1472; [/@(90) FD`_CAP`_E-|capital E for exponent (1E10)]&]
[s0;l704;O9;~~~.1472; [/@(90) FD`_ZERO-|keep trailing zeros (1.25000)]&]
[s0;l704;O9;~~~.1472; [/@(90) FD`_FIX-|always use fixed notation (FormatDouble 
only)]&]
[s0;l704;O9;~~~.1472; [/@(90) FD`_EXP-|always use exponential notation 
(FormatDouble only)]&]
[s0;l288;O9;~~~.1152; [* fill`_exp]-|left zero`-padding of exponent 
in exponential notation&]
[s3; &]
[s4;%- &]
[s5;:FormatDoubleFix`(double`,int`,int`):%- [_^String^ String]_[* FormatDoubleFix]([@(0.0.255) d
ouble]_[*@3 d], [@(0.0.255) int]_[*@3 digits], [@(0.0.255) int]_[*@3 flags]_`=_[@3 0])&]
[s2; Formats a floating point in ordinary decimal notation (whole 
part, comma, decimal part). Then number of digits (digits) can 
be interpreted either as the absolute number of decimal digits 
(the default mode) or the relative number of significant digits 
excluding leading zeros. Decimal point is always output as a 
period independent on language settings.&]
[s0; &]
[s0;l288;O9;~~~.1152; [* d]-|the number to format&]
[s0;l288;O9;~~~.1152; [* digits]-|number of digits&]
[s0;l288;O9;~~~.1152; [* flags]-|formatting flags, can be or`-ed (`|) 
together:&]
[s0;l704;O9;~~~.1472; [/@(90) FD`_SIGN-|always prepend sign (`+10)]&]
[s0;l704;O9;~~~.1472; [/@(90) FD`_REL-|relative decimal places (valid 
digits)]&]
[s0;l704;O9;~~~.1472; [/@(90) FD`_ZERO-|keep trailing zeros (1.25000)]&]
[s3; &]
[s4;%- &]
[s5;:FormatDoubleExp`(double`,int`,int`,int`):%- [_^String^ String]_[* FormatDoubleExp]([@(0.0.255) d
ouble]_[*@3 d], [@(0.0.255) int]_[*@3 digits], [@(0.0.255) int]_[*@3 flags]_`=_[@3 0], 
[@(0.0.255) int]_[*@3 fill`_exp]_`=_[@3 0])&]
[s2; Formats a floating point in scientific / exponential notation 
(sign, single digit, period, decimal part, `"e`" decimal exponent).&]
[s2; &]
[s0;l288;O9;~~~.1152; [* d]-|the number to format&]
[s0;l288;O9;~~~.1152; [* digits]-|number of digits&]
[s0;l288;O9;~~~.1152; [* flags]-|formatting flags, can be or`-ed (`|) 
together:&]
[s0;l704;O9;~~~.1472; [/@(90) FD`_SIGN-|always prepend sign (`+10)]&]
[s0;l704;O9;~~~.1472; [/@(90) FD`_SIGN`_EXP-|always prepend sign to 
exponent (1e`+2)]&]
[s0;l704;O9;~~~.1472; [/@(90) FD`_CAP`_E-|capital E for exponent (1E10)]&]
[s0;l704;O9;~~~.1472; [/@(90) FD`_ZERO-|keep trailing zeros (1.25000)]&]
[s0;l288;O9;~~~.1152; [* fill`_exp]-|left zero`-padding of exponent&]
[s2; &]
[s3; &]
[s4;%- &]
[s5;:FormatIntBase`(int`,int`,int`,char`,int`):%- [_^String^ String]_[* FormatIntBase]([@(0.0.255) i
nt]_[*@3 i], [@(0.0.255) int]_[*@3 base], [@(0.0.255) int]_[*@3 width]_`=_[@3 0], 
[@(0.0.255) char]_[*@3 lpad]_`=_`'_`', [@(0.0.255) int]_[*@3 sign]_`=_[@3 0])&]
[s0;l288; Formats a signed or unsigned integer (i) in a given radix 
(base) with left padding to given (width) with a given (lpad) 
character. &]
[s0;l288; &]
[s0;l288;O9;~~~.1152; [* i]-|the number to format.&]
[s0;l288;O9;~~~.1152; [* base]-|radix to format i in, 2 to 36 (0..9a..z)&]
[s0;l288;O9;~~~.1152; [* width]-|left padding width (output longer than 
this is not padded)&]
[s0;l288;O9;~~~.1152; [* lpad]-|character to left pad output with&]
[s0;l288;O9;~~~.1152; [* sign]-|`+1 `= always prepend `+/`-; 0 `= auto 
(`- only); `-1 `= unsigned formatting&]
[s0;~~~.1152;%- -|&]
[s4;%- &]
[s5;:Formatting`:`:language:%- [@(0.0.255) int]_[* language]&]
[s2; Language of resulting text.&]
[s3;%- &]
[s4;%- &]
[s5;:Formatting`:`:arg:%- Value_[* arg]&]
[s2; Actual argument.&]
[s3;%- &]
[s4;%- &]
[s5;:Formatting`:`:format:%- String_[* format]&]
[s2; Formatting [*@(0.0.255) options].&]
[s3;%- &]
[s4;%- &]
[s5;:Formatting`:`:id:%- String_[* id]&]
[s2; Formatter`-id.&]
[s0; &]
[ {{10000F(128)G(128)@1 [s0; [* Format registration functions]]}}&]
[s3;%- &]
[s5;:RegisterFormatter`(int`,const char`*`,Formatter`):%- [@(0.0.255) void]_[* RegisterFo
rmatter]([@(0.0.255) int]_[*@3 type], [@(0.0.255) const]_[@(0.0.255) char]_`*[*@3 id], 
Formatter_[*@3 f])&]
[s2; Registers formatter for specific Value [%-*@3 type]. If [%-*@3 type] 
is VALUE`_V, formatter is applied to all Value types if no formatter 
for specific type is specified.&]
[s3;%- &]
[s4;%- &]
[s5;:RegisterNumberFormatter`(const char`*`,Formatter`):%- [@(0.0.255) void]_[* RegisterN
umberFormatter]([@(0.0.255) const]_[@(0.0.255) char]_`*[*@3 id], Formatter_[*@3 f])&]
[s2; Registers formatter for bool, int, double and int64 types.&]
[s3;%- &]
[s4;%- &]
[s5;:RegisterStringFormatter`(const char`*`,Formatter`):%- [@(0.0.255) void]_[* RegisterS
tringFormatter]([@(0.0.255) const]_[@(0.0.255) char]_`*[*@3 id], Formatter_[*@3 f])&]
[s2; Registers formatter for String and WString types.&]
[s3;%- &]
[s4;%- &]
[s5;:RegisterDateTimeFormatter`(const char`*`,Formatter`):%- [@(0.0.255) void]_[* Registe
rDateTimeFormatter]([@(0.0.255) const]_[@(0.0.255) char]_`*[*@3 id], 
Formatter_[*@3 f])&]
[s2; Registers formatter for Date and Time types.&]
[s3;%- &]
[s4;%- &]
[s5;:RegisterValueFormatter`(const char`*`,Formatter`):%- [@(0.0.255) void]_[* RegisterVa
lueFormatter]([@(0.0.255) const]_[@(0.0.255) char]_`*[*@3 id], Formatter_[*@3 f])&]
[s2; Registers formatter to be applied when no formatter for specific 
type is specified.&]
[s0; &]
[s4;%- &]
[s5;:RegisterNullFormatter`(const char`*`,Formatter`):%- [@(0.0.255) void]_[* RegisterNul
lFormatter]([@(0.0.255) const]_[@(0.0.255) char]_`*[*@3 id], Formatter_[*@3 f])&]
[s2; Registers formatter [%-*@3 id] to be applied when the Value argument 
is Void (Value()) or ErrorValue.&]
[s3; &]
[s0; ]