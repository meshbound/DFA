#ifndef CANVAS_H
#define CANVAS_H

#include "graphicsobject.h"
#include <wx/wx.h>
#include <list>
#include <string>

class Canvas: public wxWindow {
public:
	Canvas(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size);
	virtual ~Canvas(){delete graphicCircles;}
	void AddCircle(int radius, int cenX, int cenY, wxColor color, const std::string& text);
private:
	void OnPaint(wxPaintEvent& evt);
	std::list<GraphicCircle>* graphicCircles;
};
#endif
