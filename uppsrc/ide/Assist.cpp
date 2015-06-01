#include "ide.h"

#if 0
#define LDUMP(x)     DDUMP(x)
#define LDUMPC(x)    DDUMPC(x)
#define LLOG(x)      DLOG(x)
#else
#define LDUMP(x)
#define LDUMPC(x)
#define LLOG(x)
#endif

#define LTIMING(x)

class IndexSeparatorFrameCls : public CtrlFrame {
	virtual void FrameLayout(Rect& r)                   { r.right -= 1; }
	virtual void FramePaint(Draw& w, const Rect& r) {
		w.DrawRect(r.right - 1, r.top, 1, r.Height(), SColorShadow);
	}
	virtual void FrameAddSize(Size& sz) { sz.cx += 2; }
};

AssistEditor::AssistEditor()
{
	assist.NoHeader();
	assist.NoGrid();
	assist.AddColumn().Margin(0).SetDisplay(Single<CppItemInfoDisplay>());
	assist.NoWantFocus();
	assist.WhenLeftClick = THISBACK(AssistInsert);
	type.NoHeader();
	type.NoGrid();
	type.AddColumn();
	type.WhenCursor = THISBACK(SyncAssist);
	type.NoWantFocus();
	popup.Horz(type, assist);
	popup.SetPos(2000);
	auto_assist = true;
	commentdp = false;

	InsertFrame(1, navigatorframe);
	navigatorframe.Left(navigatorpane, HorzLayoutZoom(140));
	navigating = false;

	int cy = search.GetMinSize().cy;
	navigatorpane.Add(search.TopPos(0, cy).HSizePos(0, cy + 4));
	navigatorpane.Add(sortitems.TopPos(0, cy).RightPos(0, cy));
	navigatorpane.Add(navigator_splitter.VSizePos(cy, 0).HSizePos());
	navigator_splitter.Vert() << scope << list << navlines;
	navigator_splitter.SetPos(1500, 0);
	navigator_splitter.SetPos(9500, 1);

	navigator = true;

	WhenAnnotationMove = THISBACK(SyncAnnotationPopup);
	WhenAnnotationClick = THISBACK1(EditAnnotation, true);
	WhenAnnotationRightClick = THISBACK1(EditAnnotation, false);
	Annotations(12);
	annotation_popup.Background(White);
	annotation_popup.SetFrame(BlackFrame());
	annotation_popup.Margins(6);
	annotation_popup.NoSb();
	
	thisback = false;
	
	cachedpos = INT_MAX;
	cachedln = -1;
	
	parami = 0;

	param_info.Margins(2);
	param_info.Background(SWhite());
	param_info.SetFrame(BlackFrame());
	param_info.BackPaint();
	param_info.NoSb();
	
	include_assist = false;
}

int CppItemInfoOrder(const Value& va, const Value& vb) {
	const CppItemInfo& a = ValueTo<CppItemInfo>(va);
	const CppItemInfo& b = ValueTo<CppItemInfo>(vb);
	return CombineCompare(a.name, b.name)(a.natural, b.natural);
};

void AssistEditor::CloseAssist()
{
	if(popup.IsOpen())
		popup.Close();
	if(annotation_popup.IsOpen())
		annotation_popup.Close();
	assist_item.Clear();
	CloseTip();
}

bool isincludefnchar(int c)
{
	return c && c != '<' && c != '>' && c != '?' &&
	       c != ' ' && c != '\"' && c != '/' && c != '\\' && c >= 32 && c < 65536;
}

String AssistEditor::ReadIdBackPos(int& pos, bool include)
{
	String id;
	bool (*test)(int c) = include ? isincludefnchar : iscid;
	while(pos > 0 && (*test)(GetChar(pos - 1)))
		pos--;
	int q = pos;
	while(q < GetLength() && (*test)(GetChar(q)))
		id << (char)GetChar(q++);
	return id;
}

String AssistEditor::ReadIdBack(int q, bool include)
{
	return ReadIdBackPos(q, include );
}

void AssistEditor::DirtyFrom(int line)
{
	if(line >= cachedln) {
		cachedpos = INT_MAX;
		cachedline.Clear();
		cachedln = -1;
	}
	CodeEditor::DirtyFrom(line);
}

int AssistEditor::Ch(int i)
{
	if(i >= 0 && i < GetLength()) {
		if(i < cachedpos || i - cachedpos > cachedline.GetCount()) {
			cachedln = GetLine(i);
			cachedline = GetWLine(cachedln);
			cachedpos = GetPos(cachedln);
		}
		i -= cachedpos;
		return i < cachedline.GetCount() ? cachedline[i] : '\n';
	}
	return 0;
}

int AssistEditor::ParsBack(int q)
{
	int level = 1;
	--q;
	while(q > 0) {
		if(isrbrkt(Ch(q)))
			level++;
		if(islbrkt(Ch(q)))
			if(--level <= 0)
				break;
		--q;
	}
	return max(0, q);
}

bool IsSpc(int c)
{
	return c > 0 && c <= 32;
}

void AssistEditor::SkipSpcBack(int& q)
{
	while(q > 0 && IsSpc(Ch(q - 1)))
		q--;
}

String AssistEditor::IdBack(int& qq)
{
	String r;
	if(iscid(Ch(qq - 1))) {
		int q = qq;
		while(iscid(Ch(q - 1)))
			q--;
		if(iscib(Ch(q))) {
			qq = q;
			while(q < GetLength() && iscid(Ch(q)))
				r.Cat(Ch(q++));
		}
	}
	return r;
}

String AssistEditor::CompleteIdBack(int& q)
{
	String id;
	for(;;) {
		SkipSpcBack(q);
		if(Ch(q - 1) == '>') {
			q--;
			id = '>' + id;
		}
		else
		if(Ch(q - 1) == '<') {
			q--;
			id = '<' + id;
		}
		else
		if(Ch(q - 1) == ':') {
			while(Ch(q - 1) == ':')
				q--;
			id = "::" + id;
		}
		else {
			if(iscib(*id))
				break;
			String nid = IdBack(q);
			if(IsNull(nid))
				break;
			id = nid + id;
		}
	}
	return id;
}


Vector<String> AssistEditor::ReadBack(int q)
{
	Vector<String> r;
	type.Clear();
	bool wasid = true;
	for(;;) {
		if(r.GetCount() > 200) {
			r.Clear();
			type.Clear();
			break;
		}
		SkipSpcBack(q);
		int c = Ch(q - 1);
		if(c == '>' && !wasid) {
			q--;
			r.Add() = CompleteIdBack(q) + ">";
			wasid = true;
			continue;
		}
		if(iscid(c)) {
			if(wasid)
				break;
			String id;
			for(;;) {
				id = IdBack(q) + id;
				SkipSpcBack(q);
				if(Ch(q - 1) != ':')
					break;
				while(Ch(q - 1) == ':')
					q--;
				id = "::" + id;
				SkipSpcBack(q);
			}
			r.Add() = id;
			wasid = true;
			continue;
		}
		else {
			if(c == ']') {
				if(wasid)
					break;
				r.Add("[]");
				q = ParsBack(q - 1);
				wasid = false;
				continue;
			}
			else
			if(c == ')') {
				if(wasid)
					break;
				r.Add("()");
				q = ParsBack(q - 1);
				wasid = false;
				continue;
			}
			wasid = false;
			c = Ch(q - 1);
			if(c == '>' && Ch(q - 2) == '-') {
				r.Add("->");
				q -= 2;
				continue;
			}
			if(c == '.') {
				r.Add(".");
				q--;
				continue;
			}
		}
		break;
	}
	Reverse(r);
	return r;
}

void AssistEditor::SyncAssist()
{
	LTIMING("SyncAssist");
	String name = ReadIdBack(GetCursor(), include_assist);
	String uname = ToUpper(name);
	assist.Clear();
	int typei = type.GetCursor() - 1;
	Buffer<bool> found(assist_item.GetCount(), false);
	for(int pass = 0; pass < 2; pass++) {
		VectorMap<String, int> over;
		LTIMING("FindPass");
		for(int i = 0; i < assist_item.GetCount(); i++) {
			const CppItemInfo& m = assist_item[i];
			if(!found[i] &&
			   (typei < 0 || m.typei == typei) &&
			   (pass ? m.uname.StartsWith(uname) : m.name.StartsWith(name))) {
					int q = include_assist ? -1 : over.Find(m.name);
					if(q < 0 || over[q] == m.typei && m.scope.GetCount()) {
						LTIMING("Assist Add");
						found[i] = true;
						assist.Add(RawToValue(m));
						if(q < 0)
							over.Add(m.name, m.typei);
					}
			}
		}
	}
	if(!include_assist) {
		LTIMING("Sort assist");
		assist.Sort(0, CppItemInfoOrder);
	}
}

bool AssistEditor::IncludeAssist()
{
	Vector<String> include;
	String ln = GetUtf8Line(GetCursorLine());
	CParser p(ln);
	if(!p.Char('#') || !p.Id("include"))
		return false;
	if(p.Char('\"')) {
		include.Add(GetFileFolder(theide->editfile));
		include_local = true;
	}
	else {
		p.Char('<');
		include = SplitDirs(theide->GetIncludePath());
		include_local = false;
	}
	include_path.Clear();
	include_back = 0;
	if(include_local)
		while(p.Char3('.', '.', '/') || p.Char3('.', '.', '\\')) {
			include.Top() = GetFileFolder(include.Top());
			include_back++;
		}
	for(;;) {
		String dir;
		while(isincludefnchar(p.PeekChar()))
			dir.Cat(p.GetChar());
		if(dir.GetCount() && (p.Char('/') || p.Char('\\'))) {
			if(include_path.GetCount())
				include_path << '/'; 
			include_path << dir;
		}
		else
			break;
	}
	Vector<String> folder, upper_folder, file, upper_file;
	for(int i = 0; i < include.GetCount(); i++) {
		FindFile ff(AppendFileName(AppendFileName(include[i], include_path), "*.*"));
		while(ff) {
			String fn = ff.GetName();
			if(!ff.IsHidden()) {
				if(ff.IsFolder()) {
					folder.Add(fn);
					upper_folder.Add(ToUpper(fn));
				}
				else {
					static Index<String> ext(Split(".h;.hpp;.hh;.hxx;.i;.lay;.iml;.t;.dli", ';'));
					String fext = GetFileExt(fn);
					if(fext.GetCount() == 0 || ext.Find(ToLower(fext)) >= 0) {
						file.Add(fn);
						upper_file.Add(ToUpper(fn));
					}
				}
			}
			ff.Next();
		}
	}
	IndexSort(upper_folder, folder);
	for(int i = 0; i < folder.GetCount(); i++) {
		String fn = folder[i];
		CppItemInfo& f = assist_item.GetAdd(fn);
		f.name = f.natural = fn;
		f.access = 0;
		f.kind = KIND_INCLUDEFOLDER;
	}
	IndexSort(upper_file, file);
	for(int i = 0; i < file.GetCount(); i++) {
		String fn = file[i];
		CppItemInfo& f = assist_item.Add(fn);
		f.name = f.natural = fn;
		f.access = 0;
		static Index<String> hdr(Split(".h;.hpp;.hh;.hxx", ';'));
		String fext = GetFileExt(fn);
		f.kind = hdr.Find(ToLower(GetFileExt(fn))) >= 0 || fext.GetCount() == 0 ? KIND_INCLUDEFILE
		                                                                        : KIND_INCLUDEFILE_ANY;
	}
	include_assist = true;
	if(include_path.GetCount())
		include_path << "/";
	PopUpAssist();
	return true;
}

void AssistEditor::Assist()
{
	LTIMING("Assist");
	if(!assist_active)
		return;
	CloseAssist();
	int q = GetCursor();
	assist_cursor = q;
	assist_type.Clear();
	assist_item.Clear();
	include_assist = false;
	if(IncludeAssist())
		return;
	Parser parser;
	Context(parser, GetCursor());
	Index<String> in_types;
	while(iscid(Ch(q - 1)))
		q--;
	SkipSpcBack(q);
	thisback = false;
	if(Ch(q - 1) == '(') {
		--q;
		String id = IdBack(q);
		if(id == "THISBACK") {
			thisback = true;
			thisbackn = false;
			GatherItems(parser.current_scope, false, in_types, false);
			RemoveDuplicates();
			PopUpAssist();
			return;
		}
		if(id == "THISBACK1" || id == "THISBACK2" || id == "THISBACK3" || id == "THISBACK4") {
			thisback = true;
			thisbackn = true;
			GatherItems(parser.current_scope, false, in_types, false);
			RemoveDuplicates();
			PopUpAssist();
			return;
		}
	}
	if(Ch(q - 1) == ':') {
		while(Ch(q - 1) == ':')
			q--;
		Vector<String> tparam;
		String scope = ParseTemplatedType(Qualify(parser.current_scope, CompleteIdBack(q), parser.context.namespace_using), tparam);
		GatherItems(scope, false, in_types, true);
	}
	else {
		String tp;
		Vector<String> xp = ReadBack(q);
		if(xp.GetCount()) {
			Index<String> typeset = EvaluateExpressionType(parser, xp);
			for(int i = 0; i < typeset.GetCount(); i++)
				if(typeset[i].GetCount())
					GatherItems(typeset[i], xp.GetCount(), in_types, xp.GetCount() == 0);
		}
		else {
			GatherItems(parser.current_scope, false, in_types, true);
			Vector<String> usings = Split(parser.context.namespace_using, ';');
			for(int i = 0; i < usings.GetCount(); i++)
				if(parser.current_scope != usings[i]) // Do not scan namespace already scanned
					GatherItems(usings[i], false, in_types, true);
			if(parser.current_scope.GetCount()) // Do not scan global namespace twice
				GatherItems("", false, in_types, true);
		}
	}
	RemoveDuplicates();
	PopUpAssist();
}

void AssistEditor::PopUpAssist(bool auto_insert)
{
	if(assist_item.GetCount() == 0)
		return;
	int lcy = max(16, BrowserFont().Info().GetHeight());
	type.Clear();
	type.Add(AttrText("<all>").Ink(SColorHighlight()));
	if(assist_type.GetCount() == 0)
		popup.Zoom(1);
	else {
		for(int i = 0; i < assist_type.GetCount(); i++) {
			String s = assist_type[i];
			if(s[0] == ':' && s[1] == ':')
				s = s.Mid(2);
			s = Nvl(s, "<globals>");
			if(s[0] == '<')
				type.Add(AttrText(s).Ink(SColorMark()));
			else
				type.Add(Nvl(s, "<globals>"));
		}
		popup.NoZoom();
	}
	type.SetCursor(0);
	if(!assist.GetCount())
		return;
//	int cy = min(300, lcy * max(type.GetCount(), assist.GetCount()));
//	cy += 4;	
	int cy = VertLayoutZoom(304);
	cy += HeaderCtrl::GetStdHeight();
	assist.SetLineCy(lcy);
	Point p = GetCaretPoint() + GetScreenView().TopLeft();
	Rect wa = GetWorkArea();
	int cx = min(wa.Width() - 100, HorzLayoutZoom(600));
	if(p.x + cx > wa.right)
		p.x = wa.right - cx;
	if(p.y + cy + GetFontSize().cy < wa.bottom)
		popup.SetRect(p.x, p.y + GetFontSize().cy, cx, cy);
	else
		popup.SetRect(p.x, p.y - cy, cx, cy);
	popup.BackPaint();
	if(auto_insert && assist.GetCount() == 1) {
		assist.GoBegin();
		AssistInsert();
	}
	else
		popup.Ctrl::PopUp(this, false, false, true);
}

Vector<String> AssistEditor::GetFileIds()
{
	Index<String> id;
	int l = GetCursorLine() - 1;
	while(l >= 0) {
		String x = GetUtf8Line(l);
		CParser p(x);
		while(!p.IsEof())
			if(p.IsId())
				id.FindAdd(p.ReadId());
			else
				p.SkipTerm();
		l--;
	}
	return id.PickKeys();
}

void AssistEditor::Complete()
{
	CloseAssist();
	Vector<String> id = GetFileIds();
	for(int i = 0; i < id.GetCount(); i++) {
		CppItemInfo& f = assist_item.Add(id[i]);
		f.name = id[i];
		f.natural = id[i];
		f.access = 0;
		f.kind = 100;
	}
	assist_type.Clear();
	PopUpAssist(true);
}

void AssistEditor::Complete2()
{
	CloseAssist();
	int c = GetCursor();
	String q = IdBack(c);
	if(IsNull(q))
		return;
	String h;
	Vector<String> id = GetFileIds();
	for(int i = 0; i < id.GetCount(); i++) {
		String s = id[i];
		if(s.StartsWith(q)) {
			if(IsNull(h))
				h = s;
			else {
				s.Trim(min(s.GetCount(), h.GetCount()));
				for(int j = 0; j < s.GetCount(); j++)
					if(s[j] != h[j]) {
						h.Trim(j);
						break;
					}
			}
		}
	}
	if(h.GetCount() > q.GetCount())
		Paste(h.Mid(q.GetCount()).ToWString());
}

void AssistEditor::Abbr()
{
	CloseAssist();
	int c = GetCursor();
	int ch;
	String s;
	while(IsAlpha(ch = Ch(c - 1))) {
		s.Insert(0, ch);
		--c;
	}
	int len = s.GetCount();
	s = theide->abbr.Get(s, String());
	if(IsNull(s))
		return;
	NextUndo();
	SetCursor(c);
	Remove(c, len);
	int linepos = c;
	int line = GetLinePos(linepos);
	WString h = GetWLine(line).Mid(0, linepos);
	for(int i = 0; i < s.GetCount(); i++) {
		ch = s[i];
		switch(ch) {
		case '@':
			c = GetCursor();
			break;
		case '\n':
			InsertChar('\n');
			for(int j = 0; j < h.GetCount(); j++)
				InsertChar(h[j]);
			break;
		default:
			if((byte)s[i] >= ' ' || s[i] == '\t')
				InsertChar(s[i]);
			break;
		}
	}
	SetCursor(c);
}

void AssistEditor::AssistInsert()
{
	if(assist.IsCursor()) {
		const CppItemInfo& f = ValueTo<CppItemInfo>(assist.Get(0));
		if(include_assist) {
			int ln = GetLine(GetCursor());
			int pos = GetPos(ln);
			Remove(pos, GetLineLength(ln));
			SetCursor(pos);
			String h;
			for(int i = 0; i < include_back; i++)
				h << "../";
			Paste(ToUnicode(String().Cat() << "#include " 
			                << (include_local ? "\"" : "<")
			                << h << include_path
			                << f.name
			                << (f.kind == KIND_INCLUDEFOLDER ? "/" : 
			                       include_local ? "\"" : ">")
			                , CHARSET_WIN1250));
			if(f.kind == KIND_INCLUDEFOLDER) {
				Assist();
				IgnoreMouseUp();
				return;
			} else {
				String pkg = include_path.Left(include_path.GetCount()-1);
				Vector<String> nests = SplitDirs(GetVar("UPP"));
				for(int i = 0; i < nests.GetCount(); i++){
					if(FileExists(nests[i]+"/"+include_path+GetFileName(pkg)+".upp")) {
						Ide *ide = dynamic_cast<Ide *>(TheIde());
						if(ide)
							ide->AddPackage(pkg);
						break;
					}
				}
			}
		}
		else {
			String txt = f.name;
			int l = txt.GetCount();
			int pl = txt.GetCount();
			if(!thisback && f.kind >= FUNCTION && f.kind <= INLINEFRIEND)
				txt << "()";
			int cl = GetCursor();
			int ch = cl;
			while(iscid(Ch(cl - 1)))
				cl--;
			while(iscid(Ch(ch)))
				ch++;
			Remove(cl, ch - cl);
			SetCursor(cl);
			if(thisback)
				for(;;) {
					int c = Ch(cl++);
					if(!c || Ch(cl) == ',' || Ch(cl) == ')')
						break;
					if(c != ' ') {
						if(thisbackn)
							txt << ", ";
						txt << ')';
						break;
					}
				}
			int n = Paste(ToUnicode(txt, CHARSET_WIN1250));
			if(!thisback && f.kind >= FUNCTION && f.kind <= INLINEFRIEND) {
				SetCursor(GetCursor() - 1);
				StartParamInfo(f, cl);
				int x = f.natural.ReverseFind('(');
				if(x >= 0 && f.natural[x + 1] == ')')
					SetCursor(GetCursor() + 1);
			}
			else
			if(thisback) {
				if(thisbackn)
					SetCursor(GetCursor() - 1);
			}
			else
			if(!inbody)
				SetCursor(cl + n - thisbackn);
			else
			if(pl > l)
				SetSelection(cl + l, cl + pl);
			else
				SetCursor(cl + l);
		}
	}
	CloseAssist();
	IgnoreMouseUp();
}

bool AssistEditor::InCode()
{
	int pos = GetCursor();
	int line = GetLinePos(pos);
	One<EditorSyntax> st = GetSyntax(line);
	WString l = GetWLine(line);
	st->ScanSyntax(l, ~l + pos, line, GetTabSize());
	return st->CanAssist();
}

bool AssistEditor::Key(dword key, int count)
{
	if(popup.IsOpen()) {
		int k = key & ~K_CTRL;
		ArrayCtrl& kt = key & K_CTRL ? type : assist;
		if(k == K_UP || k == K_PAGEUP || k == K_CTRL_PAGEUP || k == K_CTRL_END) {
			if(kt.IsCursor())
				return kt.Key(k, count);
			else {
				kt.SetCursor(kt.GetCount() - 1);
				return true;
			}
		}
		if(k == K_DOWN || k == K_PAGEDOWN || k == K_CTRL_PAGEDOWN || k == K_CTRL_HOME) {
			if(kt.IsCursor())
				return kt.Key(k, count);
			else {
				kt.SetCursor(0);
				return true;
			}
		}
		if(key == K_ENTER && assist.IsCursor()) {
			AssistInsert();
			return true;
		}
		if(key == K_TAB && !assist.IsCursor() && assist.GetCount()) {
			assist.GoBegin();
			AssistInsert();
			return true;
		}
	}
	int c = GetCursor();
	int cc = GetChar(c);
	int bcc = c > 0 ? GetChar(c - 1) : 0;
	bool b = CodeEditor::Key(key, count);
	if(b && search.HasFocus())
		SetFocus();
	if(assist.IsOpen()) {
		bool (*test)(int c) = include_assist ? isincludefnchar : iscid;
		if(!(*test)(key) &&
		   !((*test)(cc) && (key == K_DELETE || key == K_RIGHT)) &&
		   !((*test)(bcc) && (key == K_LEFT || key == K_BACKSPACE))) {
			if(b) {
				CloseAssist();
				if(include_assist ? (key == '/' || key == '\\') : key == '.')
					Assist();
			}
		}
		else
			SyncAssist();
	}
	else
	if(auto_assist) {
		if(InCode()) {
			if(key == '.' || key == '>' && Ch(GetCursor() - 2) == '-' ||
			   key == ':' && Ch(GetCursor() - 2) == ':')
				Assist();
			else
			if(key == '(') {
				int q = GetCursor() - 1;
				String id = IdBack(q);
				if(id == "THISBACK" || id == "THISBACK1" || id == "THISBACK2" || id == "THISBACK3" || id == "THISBACK4")
					Assist();
			}
		}
		if((key == '\"' || key == '<' || key == '/' || key == '\\') && GetUtf8Line(GetCursorLine()).StartsWith("#include"))
			Assist();
	}
	return b;
}

void AssistEditor::MouseWheel(Point p, int zdelta, dword keyflags)
{
	if(keyflags & K_CTRL)
		WhenFontScroll(sgn(zdelta));
	else
		if(assist.IsOpen())
			assist.MouseWheel(p, zdelta, keyflags);
		else
			CodeEditor::MouseWheel(p, zdelta, keyflags);
}

void AssistEditor::LeftDown(Point p, dword keyflags)
{
	CloseAssist();
	CodeEditor::LeftDown(p, keyflags);
}

void AssistEditor::LostFocus()
{
	CloseAssist();
}

String AssistEditor::RemoveDefPar(const char *s)
{
	String r;
	int lvl = 0;
	bool dp = true;
	while(*s) {
		byte c = *s++;
		if(c == '(')
			lvl++;
		if(lvl == 0) {
			if(c == '=') {
				dp = false;
				if(commentdp)
					r.Cat("/* ");
				else
					while(r.GetCount() && *r.Last() == ' ')
						r.Trim(r.GetCount() - 1);
			}
			if(c == ')') {
				if(!dp && commentdp)
					r.Cat("*/");
				r.Cat(')');
				if(CParser(s).Char('='))
					break;
				r.Cat(s);
				break;
			}
			if(c == ',') {
				if(!dp && commentdp)
					r.Cat("*/");
				dp = true;
			}
		}
		else
		if(c == ')')
			lvl--;
		if(dp || commentdp)
			r.Cat(c);
	}
	return r;
}

String AssistEditor::MakeDefinition(const String& cls, const String& _n)
{
	String n = TrimLeft(_n);
	CParser p(n);
	bool dest = false;
	const char *beg = n;
	while(!p.IsEof()) {
		const char *b = p.GetPtr();
		if(p.Id("operator"))
			return cls.GetCount() ? NormalizeSpaces(String(beg, b) + ' ' + cls + "::" + b)
			                      : NormalizeSpaces(String(beg, b) + ' ' + b);
		if(p.Char('~')) {
			beg = p.GetPtr();
			dest = true;
		}
		else
		if(p.IsId()) {
			String id = p.ReadId();
			if(p.Char('(')) {
				String rp = RemoveDefPar(p.GetPtr());
				if(cls.GetCount() == 0)
					return NormalizeSpaces(String(beg, b) + ' ' + id + '(' + rp);
				if(dest)
					return NormalizeSpaces(String(beg, b) + cls + "::~" + id + '(' + rp);
				else
					return NormalizeSpaces(String(beg, b) + ' ' + cls + "::" + id + '(' + rp);
			}
		}
		else
			p.SkipTerm();
	}
	return n;
}

void Ide::IdeGotoCodeRef(String coderef)
{
	LLOG("IdeGotoLink " << coderef);
	if(IsNull(coderef)) return;
	String scope, item;
	SplitCodeRef(coderef, scope, item);
	int q = CodeBase().Find(scope);
	if(q < 0)
		return;
	const Array<CppItem>& n = CodeBase()[q];
	q = FindItem(n, item);
	if(q >= 0)
		JumpToDefinition(n, q, scope);
}

bool AssistEditor::Esc()
{
	bool r = false;
	if(assist.IsOpen()) {
		CloseAssist();
		r = true;
	}
	if(param_info.IsOpen()) {
		for(int i = 0; i < PARAMN; i++)
			param[i].line = -1;
		param_info.Close();
		r = true;
	}
	return r;
}


void AssistEditor::Navigator(bool nav)
{
	navigator = nav;
	navigatorframe.Show(navigator && theide && !theide->IsEditorMode());
	if(IsNavigator())
		SetFocus();
	SyncNavigator();
	SyncCursor();
}

void AssistEditor::SyncNavigator()
{
	if(navigating)
		return;
	if(IsNavigator()) {
		Search();
		SyncCursor();
	}
	navigatorframe.Show(navigator && theide && !theide->IsEditorMode());
}

void AssistEditor::SelectionChanged()
{
	CodeEditor::SelectionChanged();
	SyncCursor();
	SyncParamInfo();
}

void AssistEditor::SerializeNavigator(Stream& s)
{
	int version = 4;
	s / version;
	s % navigatorframe;
	s % navigator;
	if(version == 1 || version == 3) {
		Splitter dummy;
		s % dummy;
	}
	if(version >= 4)
		s % navigator_splitter;
	Navigator(navigator);
}
