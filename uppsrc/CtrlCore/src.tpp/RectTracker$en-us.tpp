topic "RectTracker";
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
[ {{10000t/25b/25@3 [s0; [*@(229)4 RectTracker]]}}&]
[s3; &]
[s1;:RectTracker`:`:class: [@(0.0.255)3 class][3 _][*3 RectTracker][3 _:_][@(0.0.255)3 public][3 _
][*@3;3 LocalLoop]&]
[s9;%% RectTracker is a class that represent repositioning modal 
loop. It can reposition and/or resize rectangle or line as single 
modal operation.&]
[s3;%% &]
[s0; &]
[ {{10000F(128)G(128)@1 [s0;%% [* Public Member List]]}}&]
[s3; &]
[s5;:RectTracker`:`:sync: [_^Callback1^ Callback1]<[_^Rect^ Rect]>_[* sync]&]
[s2;%% This callback is called each time the dimensions change.&]
[s3;%% &]
[s4; &]
[s5;:RectTracker`:`:round: [_^Callback1^ Callback1]<Rect[@(0.0.255) `&]>_[* round]&]
[s2;%% If present, this callback is used to alter coordinates of 
rectangle after they are determined from mouse position, before 
other processing. Can be used e.g. to implement `"snap to grid`" 
operations. This is more recent alternative to defining rounding 
object and method Round.&]
[s3; &]
[s4; &]
[s5;:RectTracker`:`:SetCursorImage`(const Image`&`): [_^RectTracker^ RectTracker][@(0.0.255) `&
]_[* SetCursorImage]([@(0.0.255) const]_[_^Image^ Image][@(0.0.255) `&]_[*@3 m])&]
[s2;%% Sets the mouse cursor appearance during the loop.&]
[s3;%% &]
[s4; &]
[s5;:RectTracker`:`:MinSize`(Size`): [_^RectTracker^ RectTracker][@(0.0.255) `&]_[* MinSize
]([_^Size^ Size]_[*@3 sz])&]
[s2;%% Sets the minimal size of rectangle.&]
[s3;%% &]
[s4; &]
[s5;:RectTracker`:`:MaxSize`(Size`): [_^RectTracker^ RectTracker][@(0.0.255) `&]_[* MaxSize
]([_^Size^ Size]_[*@3 sz])&]
[s2;%% Sets the maximal size of rectangle.&]
[s3;%% &]
[s4; &]
[s5;:RectTracker`:`:MaxRect`(const Rect`&`): [_^RectTracker^ RectTracker][@(0.0.255) `&]_
[* MaxRect]([@(0.0.255) const]_[_^Rect^ Rect][@(0.0.255) `&]_[*@3 mr])&]
[s2;%% Sets the bounding rectangle which the resulting rectangle 
cannot exceed.&]
[s3;%% &]
[s4; &]
[s5;:RectTracker`:`:Clip`(const Rect`&`): [_^RectTracker^ RectTracker][@(0.0.255) `&]_[* Cl
ip]([@(0.0.255) const]_[_^Rect^ Rect][@(0.0.255) `&]_[*@3 c])&]
[s2;%% Sets the clipping rectangle.&]
[s3;%% &]
[s4; &]
[s5;:RectTracker`:`:Width`(int`): [_^RectTracker^ RectTracker][@(0.0.255) `&]_[* Width]([@(0.0.255) i
nt]_[*@3 n])&]
[s2;%% Sets the width of tracking rectangle shape lines.&]
[s3;%% &]
[s4; &]
[s5;:RectTracker`:`:SetColor`(Color`): [_^RectTracker^ RectTracker][@(0.0.255) `&]_[* SetCo
lor]([_^Color^ Color]_[*@3 c])&]
[s2;%% Sets the color of tracking rectangle (if on white background).&]
[s3;%% &]
[s4; &]
[s5;:RectTracker`:`:Pattern`(int`): [_^RectTracker^ RectTracker][@(0.0.255) `&]_[* Pattern](
[@(0.0.255) int]_[*@3 p])&]
[s2;%% Sets the pattern used to drive lines. [%-*@3 p] can be one of&]
[s2;%% &]
[ {{5000:5000<288; [s2;l0;%% DRAWDRAGRECT`_SOLID]
:: [s2;l0;%% solid line]
:: [s2;l0;%% DRAWDRAGRECT`_NORMAL]
:: [s2;l0;%% line of alternating single dots `- default]
:: [s2;l0;%% DRAWDRAGRECT`_DASHED ]
:: [s2;l0;%% line of alternating 4 pixel segments]}}&]
[s3;%% &]
[s4; &]
[s5;:RectTracker`:`:Dashed`(`): [_^RectTracker^ RectTracker][@(0.0.255) `&]_[* Dashed]()&]
[s2;%% Same as Pattern(DRAWDRAGRECT`_DASH).&]
[s3;%% &]
[s4; &]
[s5;:RectTracker`:`:Solid`(`): [_^RectTracker^ RectTracker][@(0.0.255) `&]_[* Solid]()&]
[s2;%% Same as Pattern(DRAWDRAGRECT`_SOLID).&]
[s3;%% &]
[s4; &]
[s5;:RectTracker`:`:Normal`(`): [_^RectTracker^ RectTracker][@(0.0.255) `&]_[* Normal]()&]
[s2;%% Same as Pattern(DRAWDRAGRECT`_NORMAL).&]
[s3; &]
[s4; &]
[s5;:RectTracker`:`:Animation`(int`): [_^RectTracker^ RectTracker][@(0.0.255) `&]_[* Animat
ion]([@(0.0.255) int]_[*@3 step`_ms]_`=_[@3 40])&]
[s2;%% Activates pattern animation.&]
[s3;%% &]
[s4; &]
[s5;:RectTracker`:`:KeepRatio`(bool`): [_^RectTracker^ RectTracker][@(0.0.255) `&]_[* KeepR
atio]([@(0.0.255) bool]_[*@3 b])&]
[s2;%% Forces rectangle to keep the original ratio.&]
[s3;%% &]
[s4; &]
[s5;:RectTracker`:`:Round`(RectTracker`:`:Rounder`&`): [_^RectTracker^ RectTracker][@(0.0.255) `&
]_[* Round]([_^RectTracker`:`:Rounder^ Rounder][@(0.0.255) `&]_[*@3 r])&]
[s2;%% Sets the rounding object. This is somewhat obsoleted by round 
callback.&]
[s3;%% &]
[s4; &]
[s5;:RectTracker`:`:Get`(`): [_^Rect^ Rect]_[* Get]()&]
[s2;%% Returns the current tracking rectangle.&]
[s3;%% &]
[s4; &]
[s5;:RectTracker`:`:Track`(const Rect`&`,int`,int`): [_^Rect^ Rect]_[* Track]([@(0.0.255) c
onst]_[_^Rect^ Rect][@(0.0.255) `&]_[*@3 r], [@(0.0.255) int]_[*@3 tx]_`=_ALIGN`_RIGHT, 
[@(0.0.255) int]_[*@3 ty]_`=_ALIGN`_BOTTOM)&]
[s2;%% Performs the modal rectangle tracking loop. [%-*@3 tx] and [%-*@3 ty] 
specify which edge or corner of rectangle is being changed:&]
[s2;%% &]
[ {{2807:2850:4343<288;>1088;h1;@(204) [s0; [*@3 tx]]
:: [s0; [*@3 ty]]
:: [s0;%% Changed]
::@2 [s0;%% ALIGN`_LEFT]
:: [s0;%% ALIGN`_TOP]
:: [s0;%% Top`-left corner.]
:: [s0;%% ALIGN`_LEFT]
:: [s0;%% ALIGN`_CENTER]
:: [s0;%% Left edge.]
:: [s0;%% ALIGN`_LEFT]
:: [s0;%% ALIGN`_BOTTOM]
:: [s0;%% Bottom`-left corner.]
:: [s0;%% ALIGN`_CENTER]
:: [s0;%% ALIGN`_TOP]
:: [s0;%% Top edge.]
::@(255.255.192) [s0;%% ALIGN`_CENTER]
:: [s0;%% ALIGN`_CENTER]
:: [s0;%% Rectangle is moved.]
::@2 [s0;%% ALIGN`_CENTER]
:: [s0;%% ALIGN`_BOTTOM]
:: [s0;%% Bottom edge.]
:: [s0;%% ALIGN`_RIGHT]
:: [s0;%% ALIGN`_TOP]
:: [s0;%% Top`-right corner.]
:: [s0;%% ALIGN`_RIGHT]
:: [s0;%% ALIGN`_CENTER]
:: [s0;%% Right edge.]
:: [s0;%% ALIGN`_RIGHT]
:: [s0;%% ALIGN`_BOTTOM]
:: [s0;%% Bottom`-right corner.]}}&]
[s2;%% &]
[s2;%% Returns a new rectangle.&]
[s3;%% &]
[s4; &]
[s5;:RectTracker`:`:TrackHorzLine`(int`,int`,int`,int`): [@(0.0.255) int]_[* TrackHorzLin
e]([@(0.0.255) int]_[*@3 x0], [@(0.0.255) int]_[*@3 y0], [@(0.0.255) int]_[*@3 cx], 
[@(0.0.255) int]_[*@3 line])&]
[s2;%% Performs tracking look of horizontal line. [%-*@3 x0], [%-*@3 y0] 
is base point, [%-*@3 cx] the width of line, [%-*@3 line] the current 
position. Returns the new position.&]
[s3;%% &]
[s4; &]
[s5;:RectTracker`:`:TrackVertLine`(int`,int`,int`,int`): [@(0.0.255) int]_[* TrackVertLin
e]([@(0.0.255) int]_[*@3 x0], [@(0.0.255) int]_[*@3 y0], [@(0.0.255) int]_[*@3 cy], 
[@(0.0.255) int]_[*@3 line])&]
[s2;%% Performs tracking look of vertical line. [%-*@3 x0], [%-*@3 y0] 
is base point, [%-*@3 cy] the height of line, [%-*@3 line] the current 
position. Returns the new position.&]
[s3;%% &]
[s4; &]
[s5;:RectTracker`:`:RectTracker`(Ctrl`&`): [* RectTracker]([_^Ctrl^ Ctrl][@(0.0.255) `&]_[*@3 m
aster])&]
[s2;%% Constructs RectTracker, the view area of [%-*@3 master] is used 
for drawing and coordinate system.&]
[s3;%% &]
[s0;%% ]