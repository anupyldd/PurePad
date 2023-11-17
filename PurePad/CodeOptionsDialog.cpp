#include "CodeOptionsDialog.h"
#include "SyntaxHighlighting.h"


CodeOptionsDialog::CodeOptionsDialog(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxDialog(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* codeOptionsSizer;
	codeOptionsSizer = new wxBoxSizer(wxVERTICAL);

	wxString syntaxRadioBoxChoices[] = { wxT("C/C++"), wxT("Python"), wxT("Java"), wxT("JavaScript") };
	int syntaxRadioBoxNChoices = sizeof(syntaxRadioBoxChoices) / sizeof(wxString);
	syntaxRadioBox = new wxRadioBox(this, wxID_ANY, wxT("Syntax highlighting"), wxDefaultPosition, wxDefaultSize, syntaxRadioBoxNChoices, syntaxRadioBoxChoices, 3, wxRA_SPECIFY_COLS);
	syntaxRadioBox->SetSelection(Keywords::currentLang);
	Bind(wxEVT_RADIOBOX, &CodeOptionsDialog::ChangeCurrentLang, this);
	codeOptionsSizer->Add(syntaxRadioBox, 0, 0, 5);


	this->SetSizer(codeOptionsSizer);
	this->Layout();
	codeOptionsSizer->Fit(this);

	this->Centre(wxBOTH);
}

CodeOptionsDialog::~CodeOptionsDialog()
{
}

void CodeOptionsDialog::ChangeCurrentLang(wxCommandEvent& event)
{
	switch (syntaxRadioBox->GetSelection())
	{
	case Lang::CPP:
		UpdateHighlight(Keywords::cpp, Keywords::cpp2);
		Keywords::currentLang = CPP;
		break;

	case Lang::PYTHON:
		UpdateHighlight(Keywords::python, Keywords::python);
		Keywords::currentLang = PYTHON;
		break;

	case Lang::JAVA:
		UpdateHighlight(Keywords::java, Keywords::java2);
		Keywords::currentLang = JAVA;
		break;

	case Lang::JS:
		UpdateHighlight(Keywords::javaScript, Keywords::javaScript2);
		Keywords::currentLang = JS;
		break;

	default:
		break;
	}

	Close();
}

void CodeOptionsDialog::UpdateHighlight(wxString& inWords, wxString& inWords2)
{
	wxWindow* noteWindow = this->GetParent();
	wxNotebook* notebook = dynamic_cast<wxNotebook*>(noteWindow);
	if (notebook)
	{
		wxWindow* pagePanel = notebook->GetPage(notebook->GetSelection());
		wxWindowList pageChildren = pagePanel->GetChildren();
		wxStyledTextCtrl* pageTextCtrl = dynamic_cast<wxStyledTextCtrl*>(pageChildren[0]);

		pageTextCtrl->ClearDocumentStyle();

		pageTextCtrl->SetKeyWords(0, inWords);
		pageTextCtrl->SetKeyWords(1, inWords2);
	}
}
