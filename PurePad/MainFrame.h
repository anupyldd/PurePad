#pragma once
#include "wx/wx.h"
#include <wx/notebook.h>

class MainFrame : public wxFrame
{
private:
	wxNotebook* genNotebook;
	wxPanel* defaultPage;
	wxBitmapButton* addBtn;
	wxBitmapButton* removeBtn;
	wxStaticText* bottomFillerLabel;
	wxBitmapButton* themeBtn;

public:
	MainFrame(const wxString& title = "PurePad", const wxSize& size = wxSize(500, 300),
		long style = wxFRAME_TOOL_WINDOW | wxSTAY_ON_TOP | wxBORDER_NONE | wxTAB_TRAVERSAL);
};