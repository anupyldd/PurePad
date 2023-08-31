#include "App.h"
#include "MainFrame.h"

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
	MainFrame* mainFrame = new MainFrame("PurePad");
	mainFrame->SetClientSize(300, 500);
	mainFrame->Center();
	mainFrame->Show();

	return true;
}
