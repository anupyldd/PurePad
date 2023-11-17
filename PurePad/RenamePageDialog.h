#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/bmpbuttn.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/dialog.h>

class RenamePageDialog : public wxDialog
{
private:

protected:
	wxStaticText* pageNameLabel;
	wxTextCtrl* pageNameTextCtrl;
	wxBitmapButton* okDialogBtn;
	wxBitmapButton* cancelDialogBtn;

public:
	RenamePageDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Choose page name"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1), long style = wxSTAY_ON_TOP);
	~RenamePageDialog();

	wxString GetNameText();
};
