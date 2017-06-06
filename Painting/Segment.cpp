#include "stdafx.h"
#include <string>
#include "Dot.h"
#include "Segment.h"
#include <math.h>

//////////////////////////////////////////////////////////////////////
// Konstruktion/Destruktion
//////////////////////////////////////////////////////////////////////

Segment::Segment(Dot start, Dot end)
{
	Start=start;
	End=end;
}

Segment::Segment()
{
	Start=Dot(0,0);
	End=Dot(0,0);
}

Segment::~Segment()
{
}
//////////////////////////////////////////////////////////////////////
// Copy-Konstruktor
//////////////////////////////////////////////////////////////////////
Segment::Segment(const Segment& rhs)
{
	Start=rhs.Start;
	End=rhs.End;
}
//////////////////////////////////////////////////////////////////////
// Zuweisungsoperator
//////////////////////////////////////////////////////////////////////
Segment& Segment::operator =(const Segment &rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	Start=rhs.Start;
	End=rhs.End;
	
	return *this;
}
//////////////////////////////////////////////////////////////////////
// Member-Funktionen
//////////////////////////////////////////////////////////////////////	
// setter / getter
void Segment::setStart(Dot pstart)
{
	Start=pstart;
}

Dot Segment::getStart() const
{
	return Start;
}

void Segment::setEnd(Dot pend)
{
	End=pend;
}
Dot Segment::getEnd() const
{
	return End;
}

double Segment::getLength() const
{
	double dDeltax;
	double dDeltay;

	dDeltax=abs(Start.x()-End.x());
	dDeltay=abs(Start.y()-End.y());

	return sqrt(dDeltax*dDeltax+ dDeltay*dDeltay);

}
void Segment::Draw(CDC* pDC)
{
	HDC hdc=pDC->m_hDC;
	Graphics  g(hdc);
	
	Pen aPen(Color::Red);
	Pen *myPen=&aPen;
	//myPen->Width = 5;
	g.DrawLine(myPen, Start.x(), Start.y(), End.x(), End.y());
}
