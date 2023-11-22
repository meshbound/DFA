#ifndef CANVAS_H
#define CANVAS_H

#include "graphiccircle.h"
#include "state.h"
#include <wx/wx.h>
#include <list>
#include <string>

class Canvas: public wxWindow {
public:
	Canvas(State* state, wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size);
	virtual ~Canvas(){delete graphicCircles;}
	void Clear();
private:
	State* state;
	std::list<GraphicCircle>* graphicCircles;
	GraphicCircle* selected;
	wxPoint2DDouble lastMousePos;
	void AddCircle(int radius, int cenX, int cenY, wxColor color, const std::string& text);
	void OnPaint(wxPaintEvent& evt);
	void OnMouseDown(wxMouseEvent& evt);
	void OnMouseMove(wxMouseEvent& evt);
	void OnMouseUp(wxMouseEvent& evt);
	void OnMouseLeave(wxMouseEvent& evt);
	void FinishDrag();
};

#endif
