#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/radiobox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/dialog.h>
#include <wx/notebook.h>
#include <wx/stc/stc.h>

class CodeOptionsDialog : public wxDialog
{
private:
	void ChangeCurrentLang(wxCommandEvent& event);
	void UpdateHighlight(wxString& inWords, wxString& inWords2);
	void CloseOnLoseFocus(wxActivateEvent& event);

protected:
	wxRadioBox* syntaxRadioBox;

public:

	CodeOptionsDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxSTAY_ON_TOP);

	~CodeOptionsDialog();

};
