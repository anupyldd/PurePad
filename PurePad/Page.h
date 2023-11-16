#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/panel.h>

class PagePanel : public wxPanel
{
private:

protected:
	wxTextCtrl* pageTextCtrl;

public:

	PagePanel(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(300, 500), long style = wxBORDER_NONE, const wxString& name = wxEmptyString);

	~PagePanel();

};

