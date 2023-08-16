#include "mainframe.h"
#include <wx/wx.h>
#include <wx/menu.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {

	wxPanel* mainPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(800, 400));
	mainPanel->SetBackgroundColour(wxColor(200, 0, 0));

	wxPanel* controlPanelAlways = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(-1, 50));
	controlPanelAlways->SetBackgroundColour(wxColor(0, 200, 0));

	wxPanel* controlPanelEdit = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(-1, 50));
	controlPanelEdit->SetBackgroundColour(wxColor(0, 100, 0));

	wxPanel* controlPanelRun = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(-1, 50));
	controlPanelRun->SetBackgroundColour(wxColor(0, 50, 0));

	wxPanel* inspectorPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(100, -1));
	inspectorPanel->SetBackgroundColour(wxColor(0, 0, 200));

	wxBoxSizer* mainVerticalSizer = new wxBoxSizer(wxVERTICAL);
	mainVerticalSizer->Add(mainPanel, 1, wxEXPAND);
	wxBoxSizer* controlPanelSplitSizer = new wxBoxSizer(wxHORIZONTAL);
	controlPanelSplitSizer->Add(controlPanelAlways, 0, wxEXPAND);
	controlPanelSplitSizer->Add(controlPanelEdit, 1, wxEXPAND); //controlPanelEdit->Hide();
	controlPanelSplitSizer->Add(controlPanelRun, 1, wxEXPAND); controlPanelRun->Hide();
	mainVerticalSizer->Add(controlPanelSplitSizer, 0, wxEXPAND);

	wxBoxSizer* mainHorizontalSizer = new wxBoxSizer(wxHORIZONTAL);
	mainHorizontalSizer->Add(mainVerticalSizer, 1, wxEXPAND);
	mainHorizontalSizer->Add(inspectorPanel, 0, wxEXPAND);

	this->SetSizerAndFit(mainHorizontalSizer);

	// mainPanel
	wxBoxSizer* mainPanelSizer = new wxBoxSizer(wxVERTICAL);

	wxStaticText* modeText = new wxStaticText(mainPanel, wxID_ANY, "modeText");
	wxFont modeTextFont = wxFont(wxFontInfo(20));
	modeText->SetFont(modeTextFont);
	mainPanelSizer->Add(modeText, 1, wxALIGN_CENTER_HORIZONTAL);

	mainPanel->SetSizerAndFit(mainPanelSizer);

	// inspectorPanel
	wxBoxSizer* inspectorPanelSizer = new wxBoxSizer(wxVERTICAL);

	wxStaticText* inspectingText = new wxStaticText(inspectorPanel, wxID_ANY, "Inspector");
	wxFont inspectingTextFont = wxFont(wxFontInfo(16));
	inspectingText->SetFont(inspectingTextFont);
	inspectorPanelSizer->Add(inspectingText, 1, wxALIGN_CENTER_HORIZONTAL | wxLEFT | wxRIGHT, 10);

	inspectorPanel->SetSizerAndFit(inspectorPanelSizer);

	// controlPanelAlways
	
	wxBoxSizer* controlPanelAlwaysSizer = new wxBoxSizer(wxHORIZONTAL);

	wxButton* modeSwapButton = new wxButton(controlPanelAlways, wxID_ANY, "otherMode", wxDefaultPosition, wxSize(80, 20));
	//wxFont inspectingTextFont = wxFont(wxFontInfo(16));
	//inspectingText->SetFont(inspectingTextFont);
	controlPanelAlwaysSizer->Add(modeSwapButton, 0, wxALIGN_CENTER_VERTICAL | wxALL, 10);

	controlPanelAlways->SetSizerAndFit(controlPanelAlwaysSizer);
	
	// controlPanelEdit

	wxBoxSizer* controlPanelEditSizer = new wxBoxSizer(wxHORIZONTAL);

	wxButton* clearButton = new wxButton(controlPanelEdit, wxID_ANY, "Clear", wxDefaultPosition, wxSize(80, 20));
	//wxFont inspectingTextFont = wxFont(wxFontInfo(16));
	//inspectingText->SetFont(inspectingTextFont);
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