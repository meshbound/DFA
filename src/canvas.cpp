#include "graphicsobject.h"
#include "canvas.h"
#include <wx/graphics.h>
#include <wx/dcbuffer.h>
#include <string>

Canvas::Canvas(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size): wxWindow(parent, id, pos, size){
	this->graphicCircles = new std::list<GraphicCircle>();
	this->SetBackgroundStyle(wxBG_STYLE_PAINT);
	this->Bind(wxEVT_PAINT, &Canvas::OnPaint, this);

	AddCircle(this->FromDIP(50), this->FromDIP(100), this->FromDIP(100), *wxRED, "Test");
};

void Canvas::AddCircle(int radius, int cenX, int cenY, wxColor color, const std::string& text)
{
	GraphicCircle circle{
		radius,
		color,
		text,
		{}
	};
	circle.transform.Translate(static_cast<double>(cenX), static_cast<double>(cenY));
	graphicCircles->push_back(circle);
	this->Refresh();
}

void Canvas::OnPaint(wxPaintEvent& evt){
	wxAutoBufferedPaintDC dc(this);
	dc.Clear();
	
	wxGraphicsContext* gc = wxGraphicsContext::Create(dc);
	if (gc){
		for (const GraphicCircle& circle : *graphicCircles)
		{
			gc->SetTransform(gc->CreateMatrix(circle.transform));
			gc->SetBrush(wxBrush(circle.color));
			gc->DrawEllipse(-circle.radius, -circle.radius, circle.radius * 2.0, circle.radius * 2.0);
			gc->SetFont(*wxNORMAL_FONT, *wxWHITE);
			double textWidth, textHeight;
			gc->GetTextExtent(circle.text, &textWidth, &textHeight);
			gc->DrawText(circle.text, -textWidth / 2.0, -textHeight / 2.0);
		}
		delete gc;
	}
};

