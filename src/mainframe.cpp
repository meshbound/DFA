#include "mainframe.h"
#include "canvas.h"
#include "state.h"
#include <wx/wx.h>
#include <wx/menu.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {

	//wxPanel* mainPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(800, 400));
	//mainPanel->SetBackgroundColour(wxColor(200, 0, 0));
	
	canvas = new Canvas(&state, this, wxID_ANY, wxDefaultPosition, wxSize(800, 400));	

	wxPanel* controlPanelAlways = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(-1, 50));
	controlPanelAlways->SetBackgroundColour(wxColor(0, 200, 0));

	controlPanelEdit = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(-1, 50));
	controlPanelEdit->SetBackgroundColour(wxColor(0, 100, 0));

	controlPanelRun = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(-1, 50));
	controlPanelRun->SetBackgroundColour(wxColor(0, 50, 0));

	wxPanel* inspectorPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(100, -1));
	inspectorPanel->SetBackgroundColour(wxColor(0, 0, 200));
	
	wxPanel* canvasInfoPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(100, -1));
	canvasInfoPanel->SetBackgroundColour(wxColor(0, 0, 200));

	wxBoxSizer* mainVerticalSizer = new wxBoxSizer(wxVERTICAL);
	mainVerticalSizer->Add(canvasInfoPanel, 0, wxEXPAND);
	mainVerticalSizer->Add(canvas, 1, wxEXPAND);
	controlPanelSplitSizer = new wxBoxSizer(wxHORIZONTAL);
	controlPanelSplitSizer->Add(controlPanelAlways, 0, wxEXPAND);
	controlPanelSplitSizer->Add(controlPanelEdit, 1, wxEXPAND); // controlPanelEdit->Hide();
	controlPanelSplitSizer->Add(controlPanelRun, 1, wxEXPAND); controlPanelRun->Hide();
	mainVerticalSizer->Add(controlPanelSplitSizer, 0, wxEXPAND);

	wxBoxSizer* mainHorizontalSizer = new wxBoxSizer(wxHORIZONTAL);
	mainHorizontalSizer->Add(mainVerticalSizer, 1, wxEXPAND);
	mainHorizontalSizer->Add(inspectorPanel, 0, wxEXPAND);

	this->SetSizerAndFit(mainHorizontalSizer);
	
	// canvasInfoPanel
	wxBoxSizer* canvasInfoPanelSizer = new wxBoxSizer(wxHORIZONTAL);

	stateText = new wxStaticText(canvasInfoPanel, wxID_ANY, "Editing"); 
	wxFont modeTextFont = wxFont(wxFontInfo(15));
	stateText->SetFont(modeTextFont);
	canvasInfoPanelSizer->Add(stateText, 1, wxALIGN_CENTER_VERTICAL | wxBOTTOM, 10);

	canvasInfoPanel->SetSizerAndFit(canvasInfoPanelSizer);

	// inspectorPanel
	wxBoxSizer* inspectorPanelSizer = new wxBoxSizer(wxVERTICAL);

	wxStaticText* inspectingText = new wxStaticText(inspectorPanel, wxID_ANY, "Inspector");
	wxFont inspectingTextFont = wxFont(wxFontInfo(10));
	inspectingText->SetFont(inspectingTextFont);
	inspectorPanelSizer->Add(inspectingText, 1, wxALIGN_CENTER_HORIZONTAL | wxLEFT | wxRIGHT, 10);

	inspectorPanel->SetSizerAndFit(inspectorPanelSizer);
	
	// topPanel

	// controlPanelAlways
	
	wxBoxSizer* controlPanelAlwaysSizer = new wxBoxSizer(wxHORIZONTAL);

	modeSwapButton = new wxButton(controlPanelAlways, wxID_ANY, "Run", wxDefaultPosition, wxSize(80, 20));
	modeSwapButton->Bind(wxEVT_BUTTON, &MainFrame::OnOtherModeBtn, this);
	//wxFont inspectingTextFont = wxFont(wxFontInfo(16));
	//inspectingText->SetFont(inspectingTextFont);
	controlPanelAlwaysSizer->Add(modeSwapButton, 0, wxALIGN_CENTER_VERTICAL | wxALL, 10);

	controlPanelAlways->SetSizerAndFit(controlPanelAlwaysSizer);
	
	// controlPanelEdit

	wxBoxSizer* controlPanelEditSizer = new wxBoxSizer(wxHORIZONTAL);

	editModeButton = new wxButton(controlPanelEdit, wxID_ANY, "Add", wxDefaultPosition, wxSize(80, 20));
	wxButton* clearButton = new wxButton(controlPanelEdit, wxID_ANY, "Clear", wxDefaultPosition, wxSize(80, 20));
	editModeButton->Bind(wxEVT_BUTTON, &MainFrame::OnEditModeBtn, this);
	clearButton->Bind(wxEVT_BUTTON, &MainFrame::OnClearBtn, this);
	//wxFont inspectingTextFont = wxFont(wxFontInfo(16));
	//inspectingText->SetFont(inspectingTextFont);
	controlPanelEditSizer->Add(editModeButton, 0, wxALIGN_CENTER_VERTICAL | wxALL, 10); // use checkboxes instead?
	controlPanelEditSizer->Add(clearButton, 0, wxALIGN_CENTER_VERTICAL | wxALL, 10);

	controlPanelEdit->SetSizerAndFit(controlPanelEditSizer);

	/*
	wxButton* button = new wxButton(panel, wxID_ANY, "Click Me!", wxPoint(150, 50), wxSize(100, 35));

	wxCheckBox* checkBox = new wxCheckBox(panel, wxID_ANY, "Checkbox BIYATCH!", wxPoint(150, 100));

	wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "StaticText", wxPoint(150, 150));

	wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "Edit Me!", wxPoint(150, 200), wxSize(200, -1));
	//textCtrl->SetValue("test");

	wxSlider* slider = new wxSlider(panel, wxID_ANY, 25, 0, 100, wxPoint(150, 250), wxSize(200, -1));

	wxGauge* gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(150, 300), wxSize(200, -1));
	gauge->SetValue(50);

	wxString choices[3]{"Item A", "Item B", "Item C"};
	wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(150, 350), wxSize(100, -1), 3, choices);
	choice->Select(0);

	wxListBox* listBox = new wxListBox(panel, wxID_ANY, wxPoint(150, 400), wxSize(100, -1), 3, choices);

	wxRadioBox* radioBox = new wxRadioBox(panel, wxID_ANY, "RadioBox", wxPoint(150, 450), wxDefaultSize, 3, choices);
	*/
}

void MainFrame::OnOtherModeBtn(wxCommandEvent& evt){
	std::cout << "Clicked OtherMode button!" << std::endl;
	
	if (state >= State::editing && state < State::running){ // editing
		state = State::running;
		controlPanelEdit->Hide();
		controlPanelRun->Show();
		controlPanelSplitSizer->Layout();
		stateText->SetLabelText("Running");
		modeSwapButton->SetLabelText("Edit");
	}else if (state >= State::running){ // running
		state = State::editing;
		controlPanelEdit->Show();
		controlPanelRun->Hide();
		controlPanelSplitSizer->Layout();
		stateText->SetLabelText("Editing");
		modeSwapButton->SetLabelText("Run");
	}
}

void MainFrame::OnEditModeBtn(wxCommandEvent& evt){
	std::cout << "Clicked EditMode button!" << std::endl;
	if (state == State::editing){
		state = State::adding;
		stateText->SetLabelText("Adding");
		editModeButton->SetLabelText("Remove");
	}else if (state == State::adding){
		state = State::removing;
		stateText->SetLabelText("Removing");
		editModeButton->SetLabelText("Edit");
	}else if (state == State::removing){
		state = State::editing;
		stateText->SetLabelText("Editing");
		editModeButton->SetLabelText("Add");
	}
}

void MainFrame::OnClearBtn(wxCommandEvent& evt){
	std::cout << "Clicked Clear button!" << std::endl;
	canvas->Clear();
}

/* 
 * once we enter the running state we request the contents of the canvas
 * and reconstruct as the DFA representation
 */
