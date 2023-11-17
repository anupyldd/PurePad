#include "RenamePageDialog.h"

RenamePageDialog::RenamePageDialog(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxDialog(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* pageNameSizer;
	pageNameSizer = new wxBoxSizer(wxVERTICAL);

	pageNameLabel = new wxStaticText(this, wxID_ANY, wxT("Choose page name:"), wxDefaultPosition, wxDefaultSize, 0);
	pageNameLabel->Wrap(-1);
	pageNameSizer->Add(pageNameLabel, 0, wxALL, 5);

	pageNameTextCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	pageNameSizer->Add(pageNameTextCtrl, 0, wxALL | wxEXPAND, 5);

	wxBoxSizer* nameDialogBtnSizer;
	nameDialogBtnSizer = new wxBoxSizer(wxHORIZONTAL);

	okDialogBtn = new wxBitmapButton(this, wxID_OK, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | wxBORDER_NONE);

	okDialogBtn->SetBitmap(wxBitmap(wxT("Icons/okBtn.png"), wxBITMAP_TYPE_ANY));
	okDialogBtn->SetBitmapPressed(wxBitmap(wxT("Icons/okBtnPressed.png"), wxBITMAP_TYPE_ANY));
	nameDialogBtnSizer->Add(okDialogBtn, 1, wxALL, 5);

	cancelDialogBtn = new wxBitmapButton(this, wxID_CANCEL, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | wxBORDER_NONE);

	cancelDialogBtn->SetBitmap(wxBitmap(wxT("Icons/cancelBtn.png"), wxBITMAP_TYPE_ANY));
	cancelDialogBtn->SetBitmapPressed(wxBitmap(wxT("Icons/cancelBtnPressed.png"), wxBITMAP_TYPE_ANY));
	nameDialogBtnSizer->Add(cancelDialogBtn, 1, wxALL, 5);


	pageNameSizer->Add(nameDialogBtnSizer, 0, wxEXPAND, 5);


	this->SetSizer(pageNameSizer);
	this->Layout();
	pageNameSizer->Fit(this);

	this->Centre(wxBOTH);
}

RenamePageDialog::~RenamePageDialog()
{
}

wxString RenamePageDialog::GetNameText()
{
	wxString nameText;
	nameText = pageNameTextCtrl->GetValue();
	return nameText;
}
