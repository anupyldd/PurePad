#include "MainFrame.h"

MainFrame::MainFrame(const wxString& title, const wxSize& size,	long style)
	:
	wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* genSizer;
	genSizer = new wxBoxSizer(wxVERTICAL);

	genNotebook = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);
	defaultPage = new wxPanel(genNotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	genNotebook->AddPage(defaultPage, wxT("Page 1"), false);

	genSizer->Add(genNotebook, 1, wxEXPAND | wxALL, 0);

	wxBoxSizer* bottomPanelSizer;
	bottomPanelSizer = new wxBoxSizer(wxHORIZONTAL);

	addBtn = new wxBitmapButton(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | wxBORDER_NONE);

	//addBtn->SetBitmap(wxBitmap(wxT("Icons/phAdd.png"), wxBITMAP_TYPE_ANY));
	bottomPanelSizer->Add(addBtn, 0, wxALL, 0);

	removeBtn = new wxBitmapButton(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | wxBORDER_NONE);

	//removeBtn->SetBitmap(wxBitmap(wxT("Icons/phRemove.png"), wxBITMAP_TYPE_ANY));
	bottomPanelSizer->Add(removeBtn, 0, wxLEFT, 5);

	bottomFillerLabel = new wxStaticText(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	bottomFillerLabel->Wrap(-1);
	bottomPanelSizer->Add(bottomFillerLabel, 1, wxALL | wxEXPAND, 5);

	themeBtn = new wxBitmapButton(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | wxBORDER_NONE);

	//themeBtn->SetBitmap(wxBitmap(wxT("Icons/phDark.png"), wxBITMAP_TYPE_ANY));
	bottomPanelSizer->Add(themeBtn, 0, wxALL, 0);


	genSizer->Add(bottomPanelSizer, 0, wxEXPAND, 0);


	this->SetSizer(genSizer);
	this->Layout();

	this->Centre(wxBOTH);
}
