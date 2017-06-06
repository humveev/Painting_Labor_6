#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
#include <math.h>
#include "Segment.h"
#include "Triangle.h"



//////////////////////////////////////////////////////////////////////
// Konstruktion/Destruktion
//////////////////////////////////////////////////////////////////////

Triangle::Triangle(Dot a, Dot b, Dot c)
{
	A=a;
	B=b;
	C=c;
}
Triangle::Triangle()
{
	A=Dot(0,0);
	B=Dot(0,0);
	C=Dot(0,0);
}

Triangle::~Triangle()
{
}
//////////////////////////////////////////////////////////////////////
// Copy-Konstruktor
//////////////////////////////////////////////////////////////////////
Triangle::Triangle(const Triangle& rhs) 
{
	A=rhs.A;
	B=rhs.B;
	C=rhs.C;

}
//////////////////////////////////////////////////////////////////////
// Zuweisungsoperator
//////////////////////////////////////////////////////////////////////
Triangle& Triangle::operator=(const Triangle &rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	A=rhs.A;
	B=rhs.B;
	C=rhs.C;
	
	return *this;
}
//////////////////////////////////////////////////////////////////////
// Member-Funktionen
//////////////////////////////////////////////////////////////////////	
double Triangle::getArea() 
{
	Segment c=Segment(A,B);
	Segment b=Segment(A,B);
	Segment a=Segment(B,C);

	double s;
	double A;
	// Satz von Heron
	s=(a.getLength()+b.getLength()+c.getLength())/2;
	A=sqrt(s*(s-a.getLength())*(s-b.getLength())*(s-c.getLength()));

	return A;
}

double Triangle::getCircumference() 
{

	Segment c=Segment(A,B);
	Segment b=Segment(A,B);
	Segment a=Segment(B,C);

	return a.getLength()+b.getLength()+c.getLength();
}

void Triangle::Draw(CDC* pDC) 
{

	Segment a=Segment(B,C);
	Segment b=Segment(A,C);
	Segment c=Segment(A,B);

	a.Draw(pDC);
	b.Draw(pDC);
	c.Draw(pDC);
}
IMPLEMENT_SERIAL(Triangle,CObject,1)
void Triangle::Serialize(CArchive & ar)
{
	CObject::Serialize(ar);
	A.Serialize(ar);
	B.Serialize(ar);
	C.Serialize(ar);
}
