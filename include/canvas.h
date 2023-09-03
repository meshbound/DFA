#ifndef CANVAS_H
#define CANVAS_H

#include "graphiccircle.h"
#include <wx/wx.h>
#include <list>
#include <string>

class Canvas: public wxWindow {
public:
	Canvas(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size);
	virtual ~Canvas(){delete graphicCircles;}
	void AddCircle(int radius, int cenX, int cenY, wxColor color, const std::string& text);
private:
	std::list<GraphicCircle>* graphicCircles;
	GraphicCircle* selected;
	wxPoint2DDouble dragInitPos;
	void OnPaint(wxPaintEvent& evt);
	void OnMouseDown(wxMouseEvent& evt);
	void OnMouseMove(wxMouseEvent& evt);
	void OnMouseUp(wxMouseEvent& evt);
	void OnMouseLeave(wxMouseEvent& evt);
	void FinishDrag();
};
#endif
