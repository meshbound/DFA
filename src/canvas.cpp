#include "canvas.h"
#include "graphiccircle.h"
#include "state.h"
#include <ostream>
#include <wx/graphics.h>
#include <wx/dcbuffer.h>
#include <string>

Canvas::Canvas(State* state, wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size): wxWindow(parent, id, pos, size){
	this->state = state;
	this->graphicCircles = new std::list<GraphicCircle>();
	this->lastSelected = nullptr;
	this->isDragging = false;	
	this->SetBackgroundStyle(wxBG_STYLE_PAINT);

	this->Bind(wxEVT_PAINT, &Canvas::OnPaint, this);
	this->Bind(wxEVT_LEFT_DOWN, &Canvas::OnMouseDown, this);
	this->Bind(wxEVT_MOTION, &Canvas::OnMouseMove, this);
	this->Bind(wxEVT_LEFT_UP, &Canvas::OnMouseUp, this);
	this->Bind(wxEVT_LEAVE_WINDOW, &Canvas::OnMouseLeave, this);

	AddCircle(this->FromDIP(50), this->FromDIP(100), this->FromDIP(100), *wxRED, "Node 1");
	AddCircle(this->FromDIP(50), this->FromDIP(200), this->FromDIP(200), *wxBLUE, "Node 2");
	AddCircle(this->FromDIP(50), this->FromDIP(300), this->FromDIP(300), *wxGREEN, "Node 3");
};

bool CircleContainsPoint(const GraphicCircle& circle, const wxPoint2DDouble& point){
	// x^2 + y^2 <= r^2
	return point.GetVectorLength() <= circle.radius;
}

void Canvas::AddCircle(int radius, int cenX, int cenY, wxColor color, const std::string& text){
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
		for (const GraphicCircle& circle : *graphicCircles) {
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

void Canvas::OnMouseDown(wxMouseEvent& evt){
	std::cout << "OnMouseDown: " << evt.m_x << " " << evt.m_y << std::endl;
	
	isDragging = *state != State::adding;
	lastMousePos = evt.GetPosition();

	std::list<GraphicCircle>::reverse_iterator it = std::find_if(graphicCircles->rbegin(), graphicCircles->rend(), [evt](const GraphicCircle& circle){
		wxPoint2DDouble clickPos = evt.GetPosition();
		wxAffineMatrix2D inv = circle.transform;
		inv.Invert();
		clickPos = inv.TransformPoint(clickPos);
		return CircleContainsPoint(circle, clickPos);	
	});
	
	if (it == graphicCircles->rend()){
		std::cout << "Did not hit any circles" << std::endl;
		if (*state == State::adding){
			wxPoint2DDouble clickPos = evt.GetPosition();
			AddCircle(this->FromDIP(50), clickPos.m_x, clickPos.m_y, *wxRED, "New Node");
		}
	}
	else{
		std::cout << "Hit circle: " << it->text << std::endl;
		std::list<GraphicCircle>::iterator fwdIt = graphicCircles->begin();
	       	while (&*fwdIt != &*it) fwdIt++;
		//std::cout << fwdIt->text << std::endl; 
		if (*state == State::removing){
			graphicCircles->erase(fwdIt);
		}
		else{
			graphicCircles->push_back(*fwdIt);
			graphicCircles->erase(fwdIt);
			lastSelected = &graphicCircles->back();
		}
		this->Refresh();
		lastMousePos = evt.GetPosition();
	}
	// once we have the selected node:
	// ALWAYS show info in inspector
	// IF in edit mode, allow to be moved when dragging
}

void Canvas::OnMouseUp(wxMouseEvent& evt){
	std::cout << "OnMouseUp: " << evt.m_x << " " << evt.m_y << std::endl;
	FinishDrag();
}

void Canvas::OnMouseMove(wxMouseEvent& evt){
	//std::cout << "OnMouseMove: " << evt.m_x << " " << evt.m_y << std::endl;
	
	if (isDragging)
	{
		if (lastSelected != nullptr){
			wxPoint2DDouble delta = evt.GetPosition() - lastMousePos;
			wxAffineMatrix2D inv = lastSelected->transform;
			inv.Invert();
			delta = inv.TransformDistance(delta);
			lastSelected->transform.Translate(delta.m_x, delta.m_y);
			this->Refresh();
			lastMousePos = evt.GetPosition();
		}
		else
		{
			// move everything together
			std::list<GraphicCircle>::iterator it;
			for (it = graphicCircles->begin(); it != graphicCircles->end(); ++it){	
				wxPoint2DDouble delta = evt.GetPosition() - lastMousePos;
				wxAffineMatrix2D inv = it->transform;
				inv.Invert();
				delta = inv.TransformDistance(delta);
				it->transform.Translate(delta.m_x, delta.m_y);
				//std::cout << delta.m_x << "," << delta.m_y << std::endl;
			}
			this->Refresh();
			lastMousePos = evt.GetPosition();
	
		}
	}
}

void Canvas::OnMouseLeave(wxMouseEvent& evt){
	std::cout << "OnMouseLeave: " << evt.m_x << " " << evt.m_y << std::endl;
	FinishDrag();
}

void Canvas::FinishDrag(){
	isDragging = false;
	lastSelected = nullptr;
}

void Canvas::Clear(){
	graphicCircles->clear();
	this->Refresh();
	std::cout << "Cleared canvas!" << std::endl;
}
