#include "CodeOptionsDialog.h"



CodeOptionsDialog::CodeOptionsDialog(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxDialog(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* codeOptionsSizer;
	codeOptionsSizer = new wxBoxSizer(wxVERTICAL);

	wxString syntaxRadioBoxChoices[] = { wxT("C/C++"), wxT("Python"), wxT("Java"), wxT("JavaScript") };
	int syntaxRadioBoxNChoices = sizeof(syntaxRadioBoxChoices) / sizeof(wxString);
	syntaxRadioBox = new wxRadioBox(this, wxID_ANY, wxT("Syntax highlighting"), wxDefaultPosition, wxDefaultSize, syntaxRadioBoxNChoices, syntaxRadioBoxChoices, 3, wxRA_SPECIFY_COLS);
	
	switch (Keywords::currentCodeLang)
	{
	case CPP:
		syntaxRadioBox->SetSelection(0);
		break;

	case PYTHON:
		syntaxRadioBox->SetSelection(1);
		break;

	case JAVA:
		syntaxRadioBox->SetSelection(2);
		break;

	case JS:
		syntaxRadioBox->SetSelection(3);
		break;

	default:
		break;
	}
	
	Bind(wxEVT_RADIOBOX, &CodeOptionsDialog::ChangeCurrentCodeLang, this);
	codeOptionsSizer->Add(syntaxRadioBox, 0, 0, 5);

	
	this->SetSizer(codeOptionsSizer);
	this->Layout();
	codeOptionsSizer->Fit(this);

	this->SetPosition(wxGetMousePosition() - this->GetSize());
	//this->Centre(wxBOTH);
	Bind(wxEVT_ACTIVATE, &CodeOptionsDialog::CloseOnLoseFocus, this);
}

CodeOptionsDialog::~CodeOptionsDialog()
{
}

void CodeOptionsDialog::ChangeCurrentCodeLang(wxCommandEvent& event)
{
	switch (syntaxRadioBox->GetSelection())
	{
	case CodeLang::CPP:
		Keywords::currentCodeLang = CPP;
		UpdateHighlight(Keywords::cpp, Keywords::cpp2, Keywords::currentCodeLang);
		break;

	case CodeLang::PYTHON:
		Keywords::currentCodeLang = PYTHON;
		UpdateHighlight(Keywords::python, Keywords::python, Keywords::currentCodeLang);
		break;

	case CodeLang::JAVA:
		Keywords::currentCodeLang = JAVA;
		UpdateHighlight(Keywords::java, Keywords::java2, Keywords::currentCodeLang);
		break;

	case CodeLang::JS:
		Keywords::currentCodeLang = JS;
		UpdateHighlight(Keywords::javaScript, Keywords::javaScript2, Keywords::currentCodeLang);
		break;

	default:
		break;
	}

	Close();
}

void CodeOptionsDialog::UpdateHighlight(wxString& inWords, wxString& inWords2, CodeLang inLang)
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

		std::string pageTitle = notebook->GetPageText(notebook->GetSelection()).ToStdString();
		pageTitle = pageTitle.substr(0, pageTitle.find_last_of("."));
		switch (inLang)
		{
		case CPP:
			pageTitle += ".cpp";
			break;
		case PYTHON:
			pageTitle += ".py";
			break;
		case JAVA:
			pageTitle += ".java";
			break;
		case JS:
			pageTitle += ".js";
			break;
		default:
			break;
		}
		notebook->SetPageText(notebook->GetSelection(), pageTitle);
	}
}

void CodeOptionsDialog::CloseOnLoseFocus(wxActivateEvent& event)
{
	if (!event.GetActive())
	{
		Destroy();
	}
}
