#include "Page.h"

PagePanel::PagePanel(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxPanel(parent, id, pos, size, style, name)
{
	wxBoxSizer* pageTextSizer;
	pageTextSizer = new wxBoxSizer(wxVERTICAL);

	pageTextCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
	pageTextSizer->Add(pageTextCtrl, 1, wxEXPAND, 5);


	this->SetSizer(pageTextSizer);
	this->Layout();
}

PagePanel::~PagePanel()
{
}