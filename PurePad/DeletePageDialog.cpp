#include "DeletePageDialog.h"

DeletePageDialog::DeletePageDialog(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxDialog(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* delDialogSizer;
	delDialogSizer = new wxBoxSizer(wxVERTICAL);

	delDialogLabel = new wxStaticText(this, wxID_ANY, wxT("Delete this page?"), wxDefaultPosition, wxDefaultSize, 0);
	delDialogLabel->Wrap(-1);
	delDialogSizer->Add(delDialogLabel, 0, wxALL, 5);

	wxBoxSizer* delDialogBtnSizer;
	delDialogBtnSizer = new wxBoxSizer(wxHORIZONTAL);

	delOkBtn = new wxBitmapButton(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | wxBORDER_NONE);

	delOkBtn->SetBitmap(wxBitmap(wxT("Icons/okBtn.png"), wxBITMAP_TYPE_ANY));
	delOkBtn->SetBitmapPressed(wxBitmap(wxT("Icons/okBtnPressed.png"), wxBITMAP_TYPE_ANY));
	delOkBtn->SetToolTip(wxT("OK"));

	delDialogBtnSizer->Add(delOkBtn, 1, wxALL, 5);

	delCancelBtn = new wxBitmapButton(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | wxBORDER_NONE);

	delCancelBtn->SetBitmap(wxBitmap(wxT("Icons/cancelBtn.png"), wxBITMAP_TYPE_ANY));
	delCancelBtn->SetBitmapPressed(wxBitmap(wxT("Icons/cancelBtnPressed.png"), wxBITMAP_TYPE_ANY));
	delCancelBtn->SetToolTip(wxT("Cancel"));

	delDialogBtnSizer->Add(delCancelBtn, 1, wxALL, 5);


	delDialogSizer->Add(delDialogBtnSizer, 1, wxEXPAND, 0);


	this->SetSizer(delDialogSizer);
	this->Layout();
	delDialogSizer->Fit(this);

	this->Centre(wxBOTH);
}

DeletePageDialog::~DeletePageDialog()
{
}