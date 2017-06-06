#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>
#include "Segment.h"
#include "Square.h"

Square::Square(Dot lu, Dot ru, Dot ro, Dot lo)
{
	A=lu;
	B=ru;
	C=ro;
	D=lo;
}

//////////////////////////////////////////////////////////////////////
// Konstruktion/Destruktion
//////////////////////////////////////////////////////////////////////

Square::Square()
{
A=Dot(0,0);
B=Dot(0,0);
C=Dot(0,0);
D=Dot(0,0);
}

Square::~Square()
{
}
//////////////////////////////////////////////////////////////////////
// Copy-Konstruktor
//////////////////////////////////////////////////////////////////////
Square::Square(const Square& rhs) 
{
	A=rhs.A;
	B=rhs.B;
	C=rhs.C;
	D=rhs.D;
}
//////////////////////////////////////////////////////////////////////
// Zuweisungsoperator
//////////////////////////////////////////////////////////////////////
Square& Square::operator =(const Square &rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	A=rhs.A;
	B=rhs.B;
	C=rhs.C;
	D=rhs.D;
	
	return *this;
}
//////////////////////////////////////////////////////////////////////
// Member-Funktionen
//////////////////////////////////////////////////////////////////////	

double Square::getArea()
{
	Segment a=Segment(A,B);

	return a.getLength()*a.getLength();
}

double Square::getCircumference() 
{
	Segment a=Segment(A,B);

	return 4*a.getLength();
}

void Square::Draw(CDC* pDC) 
{

	Segment a=Segment(A,B);
	Segment b=Segment(B,C);
	Segment c=Segment(C,D);
	Segment d=Segment(D,A);

	a.Draw(pDC);
	b.Draw(pDC);
	c.Draw(pDC);
	d.Draw(pDC);
}

//////////////////////////////////////////////////////////////////////
// Speicherungsfunktionen
//////////////////////////////////////////////////////////////////////
IMPLEMENT_SERIAL(Square, CObject, 1)
void Square::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	A.Serialize(ar);
	B.Serialize(ar);
	C.Serialize(ar);
	D.Serialize(ar);
}