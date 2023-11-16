#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/stc/stc.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/panel.h>

class CodePagePanel : public wxPanel
{
private:

protected:
	wxStyledTextCtrl* codeStyledText;

public:

	CodePagePanel(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(300, 500), long style = wxBORDER_NONE, const wxString& name = wxEmptyString);

	~CodePagePanel();

};
