#include "MainFrame.h"

MainFrame::MainFrame(const wxString& title, const wxSize& size,	long style)
	:
	wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, size, style),
	pageCounter(0)
{
	wxInitAllImageHandlers();
	wxString pathToIcons = wxGetCwd() + "\\Icons\\";

	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* genSizer;
	genSizer = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* noteSizer;
	noteSizer = new wxBoxSizer(wxVERTICAL);

	genNotebook = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);

	noteSizer->Add(genNotebook, 1, wxEXPAND | wxALL, 0);


	genSizer->Add(noteSizer, 1, wxEXPAND, 0);

	wxBoxSizer* menuSizer;
	menuSizer = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* buttonsSizer;
	buttonsSizer = new wxBoxSizer(wxHORIZONTAL);

	addBtn = new wxBitmapButton(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | wxBORDER_NONE | wxBORDER_NONE);

	addBtn->SetBitmap(wxBitmap(pathToIcons + "addBtn.png", wxBITMAP_TYPE_ANY));
	addBtn->SetBitmapPressed(wxBitmap(pathToIcons + "addBtnPressed.png", wxBITMAP_TYPE_ANY));
	addBtn->SetToolTip(wxT("Add page"));

	buttonsSizer->Add(addBtn, 0, wxLEFT, 5);

	codeBtn = new wxBitmapButton(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | wxBORDER_NONE | wxBORDER_NONE);

	codeBtn->SetBitmap(wxBitmap(pathToIcons + "codeBtn.png", wxBITMAP_TYPE_ANY));
	codeBtn->SetBitmapPressed(wxBitmap(pathToIcons + "codeBtnPressed.png", wxBITMAP_TYPE_ANY));
	codeBtn->SetToolTip(wxT("Add code page"));

	buttonsSizer->Add(codeBtn, 0, wxLEFT, 5);

	delBtn = new wxBitmapButton(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | wxBORDER_NONE | wxBORDER_NONE);

	delBtn->SetBitmap(wxBitmap(pathToIcons + "delBtn.png", wxBITMAP_TYPE_ANY));
	delBtn->SetBitmapPressed(wxBitmap(pathToIcons + "delBtnPressed.png", wxBITMAP_TYPE_ANY));
	delBtn->SetToolTip(wxT("Delete page"));

	buttonsSizer->Add(delBtn, 0, wxLEFT, 5);

	wrapBtn = new wxBitmapButton(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | wxBORDER_NONE);

	wrapBtn->SetBitmap(wxBitmap(pathToIcons + "wrapBtn.png", wxBITMAP_TYPE_ANY));
	wrapBtn->SetBitmapPressed(wxBitmap(pathToIcons + "wrapBtnPressed.png", wxBITMAP_TYPE_ANY));
	wrapBtn->SetToolTip(wxT("Word wrap"));

	buttonsSizer->Add(wrapBtn, 0, wxLEFT, 5);

	onTopBtn = new wxBitmapButton(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | wxBORDER_NONE);

	onTopBtn->SetBitmap(wxBitmap(pathToIcons + "onTopBtn.png", wxBITMAP_TYPE_ANY));
	onTopBtn->SetBitmapPressed(wxBitmap(pathToIcons + "onTopBtnPressed.png", wxBITMAP_TYPE_ANY));
	onTopBtn->SetToolTip(wxT("Always on top"));

	buttonsSizer->Add(onTopBtn, 0, wxLEFT, 5);

	tabFillerLabel = new wxStaticText(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	tabFillerLabel->Wrap(-1);
	buttonsSizer->Add(tabFillerLabel, 12, 0, 5);

	fontSizeTextCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(32, 16), 0);
#ifdef __WXGTK__
	if (!fontSizeTextCtrl->HasFlag(wxTE_MULTILINE))
	{
		fontSizeTextCtrl->SetMaxLength(3);
	}
#else
	fontSizeTextCtrl->SetMaxLength(3);
#endif
	fontSizeTextCtrl->SetToolTip(wxT("Font size"));

	buttonsSizer->Add(fontSizeTextCtrl, 0, wxALIGN_CENTER | wxRIGHT, 5);


	menuSizer->Add(buttonsSizer, 1, wxLEFT, 0);

	wxBoxSizer* tabSizer;
	tabSizer = new wxBoxSizer(wxVERTICAL);


	menuSizer->Add(tabSizer, 1, wxEXPAND, 0);


	genSizer->Add(menuSizer, 0, wxEXPAND, 0);


	this->SetSizer(genSizer);
	this->Layout();
	this->Centre(wxBOTH);

	BindEvents();
}

MainFrame::~MainFrame()
{
}

void MainFrame::BindEvents()
{
	addBtn->Bind(wxEVT_BUTTON, &MainFrame::AddPage, this);
	codeBtn->Bind(wxEVT_BUTTON, &MainFrame::AddCodePage, this);
}

void MainFrame::AddPage(wxCommandEvent& event)
{
	pageCounter++;

	wxPanel* newPage = new wxPanel(genNotebook);
	wxBoxSizer* pageTextSizer = new wxBoxSizer(wxVERTICAL);
	wxTextCtrl* pageTextCtrl = new wxTextCtrl(newPage, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
	pageTextSizer->Add(pageTextCtrl, 1, wxEXPAND, 5);
	newPage->SetSizer(pageTextSizer);
	newPage->Layout();

	genNotebook->AddPage(newPage, wxString("page"), true);
}

void MainFrame::AddCodePage(wxCommandEvent& event)
{
	pageCounter++;

	wxPanel* newCodePage = new wxPanel(genNotebook);
	wxBoxSizer* codePageTextSizer = new wxBoxSizer(wxVERTICAL);
	
	wxStyledTextCtrl* codeStyledText = new wxStyledTextCtrl(newCodePage, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE, wxEmptyString);
	
	{
		wxFont font = wxFont(wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Consolas"));
		codeStyledText->StyleSetFont(wxSTC_STYLE_DEFAULT, font);
	}

	codeStyledText->StyleClearAll();
	codeStyledText->SetLexer(wxSTC_LEX_CPP);

	codeStyledText->SetMarginWidth(0, codeStyledText->TextWidth(wxSTC_STYLE_LINENUMBER, wxT("_99999")));
	codeStyledText->StyleSetForeground(wxSTC_STYLE_LINENUMBER, wxColour(75, 75, 75));
	codeStyledText->StyleSetBackground(wxSTC_STYLE_LINENUMBER, wxColour(220, 220, 220));
	codeStyledText->SetMarginType(0, wxSTC_MARGIN_NUMBER);


	// ---- Enable code folding
	codeStyledText->SetMarginType(wxSTC_MARGIN_NUMBER, wxSTC_MARGIN_SYMBOL);
	codeStyledText->SetMarginWidth(wxSTC_MARGIN_NUMBER, 15);
	codeStyledText->SetMarginMask(wxSTC_MARGIN_NUMBER, wxSTC_MASK_FOLDERS);
	codeStyledText->StyleSetBackground(wxSTC_MARGIN_NUMBER, wxColor(200, 200, 200));
	codeStyledText->SetMarginSensitive(wxSTC_MARGIN_NUMBER, true);

	// Properties found from http://www.scintilla.org/SciTEDoc.html
	codeStyledText->SetProperty(wxT("fold"), wxT("1"));
	codeStyledText->SetProperty(wxT("fold.comment"), wxT("1"));
	codeStyledText->SetProperty(wxT("fold.compact"), wxT("1"));

	wxColor grey(100, 100, 100);
	codeStyledText->MarkerDefine(wxSTC_MARKNUM_FOLDER, wxSTC_MARK_ARROW);
	codeStyledText->MarkerSetForeground(wxSTC_MARKNUM_FOLDER, grey);
	codeStyledText->MarkerSetBackground(wxSTC_MARKNUM_FOLDER, grey);

	codeStyledText->MarkerDefine(wxSTC_MARKNUM_FOLDEROPEN, wxSTC_MARK_ARROWDOWN);
	codeStyledText->MarkerSetForeground(wxSTC_MARKNUM_FOLDEROPEN, grey);
	codeStyledText->MarkerSetBackground(wxSTC_MARKNUM_FOLDEROPEN, grey);

	codeStyledText->MarkerDefine(wxSTC_MARKNUM_FOLDERSUB, wxSTC_MARK_EMPTY);
	codeStyledText->MarkerSetForeground(wxSTC_MARKNUM_FOLDERSUB, grey);
	codeStyledText->MarkerSetBackground(wxSTC_MARKNUM_FOLDERSUB, grey);

	codeStyledText->MarkerDefine(wxSTC_MARKNUM_FOLDEREND, wxSTC_MARK_ARROW);
	codeStyledText->MarkerSetForeground(wxSTC_MARKNUM_FOLDEREND, grey);
	codeStyledText->MarkerSetBackground(wxSTC_MARKNUM_FOLDEREND, _T("WHITE"));

	codeStyledText->MarkerDefine(wxSTC_MARKNUM_FOLDEROPENMID, wxSTC_MARK_ARROWDOWN);
	codeStyledText->MarkerSetForeground(wxSTC_MARKNUM_FOLDEROPENMID, grey);
	codeStyledText->MarkerSetBackground(wxSTC_MARKNUM_FOLDEROPENMID, _T("WHITE"));

	codeStyledText->MarkerDefine(wxSTC_MARKNUM_FOLDERMIDTAIL, wxSTC_MARK_EMPTY);
	codeStyledText->MarkerSetForeground(wxSTC_MARKNUM_FOLDERMIDTAIL, grey);
	codeStyledText->MarkerSetBackground(wxSTC_MARKNUM_FOLDERMIDTAIL, grey);

	codeStyledText->MarkerDefine(wxSTC_MARKNUM_FOLDERTAIL, wxSTC_MARK_EMPTY);
	codeStyledText->MarkerSetForeground(wxSTC_MARKNUM_FOLDERTAIL, grey);
	codeStyledText->MarkerSetBackground(wxSTC_MARKNUM_FOLDERTAIL, grey);
	// ---- End of code folding part

	codeStyledText->SetWrapMode(wxSTC_WRAP_WORD); // other choice is wxSCI_WRAP_NONE


	codeStyledText->StyleSetForeground(wxSTC_C_STRING, wxColour(150, 0, 0));
	codeStyledText->StyleSetForeground(wxSTC_C_PREPROCESSOR, wxColour(165, 105, 0));
	codeStyledText->StyleSetForeground(wxSTC_C_IDENTIFIER, wxColour(40, 0, 60));
	codeStyledText->StyleSetForeground(wxSTC_C_NUMBER, wxColour(0, 150, 0));
	codeStyledText->StyleSetForeground(wxSTC_C_CHARACTER, wxColour(150, 0, 0));
	codeStyledText->StyleSetForeground(wxSTC_C_WORD, wxColour(0, 0, 150));
	codeStyledText->StyleSetForeground(wxSTC_C_WORD2, wxColour(0, 150, 0));
	codeStyledText->StyleSetForeground(wxSTC_C_COMMENT, wxColour(150, 150, 150));
	codeStyledText->StyleSetForeground(wxSTC_C_COMMENTLINE, wxColour(150, 150, 150));
	codeStyledText->StyleSetForeground(wxSTC_C_COMMENTDOC, wxColour(150, 150, 150));
	codeStyledText->StyleSetForeground(wxSTC_C_COMMENTDOCKEYWORD, wxColour(0, 0, 200));
	codeStyledText->StyleSetForeground(wxSTC_C_COMMENTDOCKEYWORDERROR, wxColour(0, 0, 200));
	codeStyledText->StyleSetBold(wxSTC_C_WORD, true);
	codeStyledText->StyleSetBold(wxSTC_C_WORD2, true);
	codeStyledText->StyleSetBold(wxSTC_C_COMMENTDOCKEYWORD, true);

	// a sample list of keywords, I haven't included them all to keep it short...
	codeStyledText->SetKeyWords(0, wxT("return for while break continue"));
	codeStyledText->SetKeyWords(1, wxT("const int float void char double"));

	codePageTextSizer->Add(codeStyledText, 1, wxEXPAND, 5);

	newCodePage->SetSizer(codePageTextSizer);
	newCodePage->Layout();

	genNotebook->AddPage(newCodePage, wxString("code page"), true);
}
