#include "stdafx.h"
#include <iostream>
using namespace std;
#include <string>
const double PI=3.141592653;
#include "Dot.h"
#include "Shape.h"
#include "Circle.h"


//////////////////////////////////////////////////////////////////////
// Konstruktion/Destruktion
//////////////////////////////////////////////////////////////////////

Circle::Circle()
{
	center=Dot(0,0);
	radius=0;
}

Circle::Circle(Dot dCenter, int dRadius)
{
	center=dCenter;
	radius=dRadius;
}

Circle::~Circle()
{
}
//////////////////////////////////////////////////////////////////////
// Copy-Konstruktor
//////////////////////////////////////////////////////////////////////
Circle::Circle(const Circle& rhs) 
{
	center=rhs.center;
	radius=rhs.radius;
}
//////////////////////////////////////////////////////////////////////
// Zuweisungsoperator
//////////////////////////////////////////////////////////////////////
Circle& Circle::operator =(const Circle &rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	center=rhs.center;
	radius=rhs.radius;
	
	return *this;
}
//////////////////////////////////////////////////////////////////////
// Memberfunktionen
//////////////////////////////////////////////////////////////////////
double Circle::getArea() 
{
	return radius*radius*PI;
}

double Circle::getCircumference() 
{
	return 2.*radius*PI;
}

void Circle::Draw(CDC* pDC) 
{
	HDC hdc=pDC->m_hDC;
	Graphics  g(hdc);
	
	Pen aPen(Color::Red);
	Pen *myPen=&aPen;

	Dot ReferencePoint(center.x()-radius,center.y()-radius);
	
	g.DrawEllipse(myPen, ReferencePoint.x(),ReferencePoint.y(),2*radius,2*radius);
}


//////////////////////////////////////////////////////////////////////
// Speicherungsfunktionen
//////////////////////////////////////////////////////////////////////
IMPLEMENT_SERIAL(Circle, CObject, 1)
void Circle::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	center.Serialize(ar);
	
	if (ar.IsStoring())
		ar << radius;
	else
		ar >> radius;
}
