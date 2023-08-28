#ifndef MAINFRAME_H
#define MAINFRAME_H
#include "canvas.h"
#include "state.h"
#include <wx/wx.h>

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);
private:
	Canvas* canvas;
	wxBoxSizer* controlPanelSplitSizer;
	wxPanel* controlPanelEdit;
	wxPanel* controlPanelRun;
	wxButton* modeSwapButton;
	wxStaticText* stateText;
	State currentState = editing;
	void OnOtherModeBtn(wxCommandEvent& evt);
};

#endif
