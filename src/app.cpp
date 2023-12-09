#include "app.h"
#include "mainframe.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
	MainFrame* mainframe = new MainFrame("DFA simulator");
	//mainframe->SetClientSize(800, 800);
	mainframe->Center();
	mainframe->Show();
	return true;
}
