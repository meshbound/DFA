#ifndef GRAPHICSOBJECT_H
#define GRAPHICSOBJECT_H

#include <wx/wx.h>

struct GraphicCircle{
	int radius;
	wxColor color;
	wxString text;
	wxAffineMatrix2D transform;
};

#endif
