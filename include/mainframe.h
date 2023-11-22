#ifndef MAINFRAME_H
#define MAINFRAME_H

#include "canvas.h"
#include "state.h"
#include <wx/wx.h>

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);
	State state = State::editing;
private:
	Canvas* canvas;
	wxBoxSizer* controlPanelSplitSizer;
	wxPanel* controlPanelEdit;
	wxPanel* controlPanelRun;
	wxButton* modeSwapButton;
	wxButton* editModeButton;
	wxStaticText* stateText;
	void OnOtherModeBtn(wxCommandEvent& evt);
	void OnEditModeBtn(wxCommandEvent& evt);
	void OnClearBtn(wxCommandEvent& evt);
};

#endif
