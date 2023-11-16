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
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/stc/stc.h>
#include <wx/notebook.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/frame.h>

class MainFrame : public wxFrame
{
private:
	wxNotebook* genNotebook;
	wxPanel* pagePanel;
	wxTextCtrl* pageTextCtrl;
	wxPanel* codePagePanel;
	wxStyledTextCtrl* codeText;
	wxBitmapButton* addBtn;
	wxBitmapButton* delBtn;
	wxBitmapButton* codeBtn;
	wxBitmapButton* wrapBtn;
	wxBitmapButton* onTopBtn;
	wxStaticText* tabFillerLabel;
	wxTextCtrl* fontSizeTextCtrl;

public:
	MainFrame(const wxString& title = "PurePad", const wxSize& size = wxSize(500, 300),
		long style = wxDEFAULT_FRAME_STYLE | wxSTAY_ON_TOP | wxBORDER_NONE);
};
