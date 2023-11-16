#include "CodePage.h"

CodePagePanel::CodePagePanel(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxPanel(parent, id, pos, size, style, name)
{
	wxBoxSizer* codePageTextSizer;
	codePageTextSizer = new wxBoxSizer(wxVERTICAL);

	codeStyledText = new wxStyledTextCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE, wxEmptyString);
	codeStyledText->SetUseTabs(true);
	codeStyledText->SetTabWidth(4);
	codeStyledText->SetIndent(4);
	codeStyledText->SetTabIndents(true);
	codeStyledText->SetBackSpaceUnIndents(true);
	codeStyledText->SetViewEOL(false);
	codeStyledText->SetViewWhiteSpace(false);
	codeStyledText->SetMarginWidth(2, 0);
	codeStyledText->SetIndentationGuides(true);
	codeStyledText->SetReadOnly(false);
	codeStyledText->SetMarginType(1, wxSTC_MARGIN_SYMBOL);
	codeStyledText->SetMarginMask(1, wxSTC_MASK_FOLDERS);
	codeStyledText->SetMarginWidth(1, 16);
	codeStyledText->SetMarginSensitive(1, true);
	codeStyledText->SetProperty(wxT("fold"), wxT("1"));
	codeStyledText->SetFoldFlags(wxSTC_FOLDFLAG_LINEBEFORE_CONTRACTED | wxSTC_FOLDFLAG_LINEAFTER_CONTRACTED);
	codeStyledText->SetMarginType(0, wxSTC_MARGIN_NUMBER);
	codeStyledText->SetMarginWidth(0, codeStyledText->TextWidth(wxSTC_STYLE_LINENUMBER, wxT("_99999")));
	codeStyledText->MarkerDefine(wxSTC_MARKNUM_FOLDER, wxSTC_MARK_BOXPLUS);
	codeStyledText->MarkerSetBackground(wxSTC_MARKNUM_FOLDER, wxColour(wxT("BLACK")));
	codeStyledText->MarkerSetForeground(wxSTC_MARKNUM_FOLDER, wxColour(wxT("WHITE")));
	codeStyledText->MarkerDefine(wxSTC_MARKNUM_FOLDEROPEN, wxSTC_MARK_BOXMINUS);
	codeStyledText->MarkerSetBackground(wxSTC_MARKNUM_FOLDEROPEN, wxColour(wxT("BLACK")));
	codeStyledText->MarkerSetForeground(wxSTC_MARKNUM_FOLDEROPEN, wxColour(wxT("WHITE")));
	codeStyledText->MarkerDefine(wxSTC_MARKNUM_FOLDERSUB, wxSTC_MARK_EMPTY);
	codeStyledText->MarkerDefine(wxSTC_MARKNUM_FOLDEREND, wxSTC_MARK_BOXPLUS);
	codeStyledText->MarkerSetBackground(wxSTC_MARKNUM_FOLDEREND, wxColour(wxT("BLACK")));
	codeStyledText->MarkerSetForeground(wxSTC_MARKNUM_FOLDEREND, wxColour(wxT("WHITE")));
	codeStyledText->MarkerDefine(wxSTC_MARKNUM_FOLDEROPENMID, wxSTC_MARK_BOXMINUS);
	codeStyledText->MarkerSetBackground(wxSTC_MARKNUM_FOLDEROPENMID, wxColour(wxT("BLACK")));
	codeStyledText->MarkerSetForeground(wxSTC_MARKNUM_FOLDEROPENMID, wxColour(wxT("WHITE")));
	codeStyledText->MarkerDefine(wxSTC_MARKNUM_FOLDERMIDTAIL, wxSTC_MARK_EMPTY);
	codeStyledText->MarkerDefine(wxSTC_MARKNUM_FOLDERTAIL, wxSTC_MARK_EMPTY);
	codeStyledText->SetSelBackground(true, wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
	codeStyledText->SetSelForeground(true, wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHTTEXT));
	codePageTextSizer->Add(codeStyledText, 1, wxEXPAND, 5);


	this->SetSizer(codePageTextSizer);
	this->Layout();
}

CodePagePanel::~CodePagePanel()
{
}