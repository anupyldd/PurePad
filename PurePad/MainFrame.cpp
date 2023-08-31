#include "MainFrame.h"

MainFrame::MainFrame(const wxString& title, const wxSize& size,	long style)
	:
	wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* genSizer;
	genSizer = new wxBoxSizer(wxVERTICAL);

	genNotebook = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);

	genSizer->Add(genNotebook, 1, wxEXPAND | wxALL, 0);


	this->SetSizer(genSizer);
	this->Layout();

	this->Centre(wxBOTH);
}
