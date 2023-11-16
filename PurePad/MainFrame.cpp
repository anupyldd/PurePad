#include "MainFrame.h"

MainFrame::MainFrame(const wxString& title, const wxSize& size,	long style)
	:
	wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, size, style)
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
}
