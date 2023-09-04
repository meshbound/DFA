#ifndef MAINFRAME_H
#define MAINFRAME_H

#include "state.h"
#include <wx/wx.h>

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);
	State currentState = editing;
private:
	wxBoxSizer* controlPanelSplitSizer;
	wxPanel* controlPanelEdit;
	wxPanel* controlPanelRun;
	wxButton* modeSwapButton;
	wxStaticText* stateText;
	void OnOtherModeBtn(wxCommandEvent& evt);
};

#endif
