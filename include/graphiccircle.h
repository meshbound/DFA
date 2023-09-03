#ifndef GRAPHICCIRCLE_H
#define GRAPHICCIRCLE_H

#include <wx/wx.h>

struct GraphicCircle{
	int radius;
	wxColor color;
	wxString text;
	wxAffineMatrix2D transform;
};

#endif
