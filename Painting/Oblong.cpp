#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <string>
#include "Segment.h"
#include "Oblong.h"

//////////////////////////////////////////////////////////////////////
// Konstruktion/Destruktion
//////////////////////////////////////////////////////////////////////

Oblong::Oblong()
{
	A=Dot(0,0);
	B=Dot(0,0);
	C=Dot(0,0);
	D=Dot(0,0);
}

Oblong::Oblong(Dot lu, Dot ru, Dot ro, Dot lo)
{
	A=lu;
	B=ru;
	C=ro;
	D=lo;
}
Oblong::~Oblong()
{
}


//////////////////////////////////////////////////////////////////////
// Copy-Konstruktor
//////////////////////////////////////////////////////////////////////
Oblong::Oblong(const Oblong& rhs) 
{
	A=rhs.A;
	B=rhs.B;
	C=rhs.C;
	D=rhs.D;
}
//////////////////////////////////////////////////////////////////////
// Zuweisungsoperator
//////////////////////////////////////////////////////////////////////
Oblong& Oblong::operator =(const Oblong &rhs)
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
double Oblong::getArea() 
{
	Segment a=Segment(A,B);
	Segment b=Segment(B,C);

return a.getLength()*b.getLength();
}

double Oblong::getCircumference() 
{
	Segment a=Segment(A,B);
	Segment b=Segment(B,C);

	return 2*(a.getLength()+b.getLength());
}

void Oblong::Draw(CDC* pDC) 
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
