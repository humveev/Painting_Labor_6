#include "stdafx.h"
#include <string>
#include "Dot.h"

using namespace std;

int Dot::y() const 
{
	return y_coordinate;
}


int Dot::x() const
{
	return x_coordinate;
}

Dot::Dot(int x, int y)
{
	x_coordinate=x;
	y_coordinate=y;
}

//////////////////////////////////////////////////////////////////////
// Konstruktion/Destruktion
//////////////////////////////////////////////////////////////////////

Dot::Dot()
{
	x_coordinate=0;
	y_coordinate=0;
}

Dot::~Dot()
{


}
//////////////////////////////////////////////////////////////////////
// Copy-Konstruktor
//////////////////////////////////////////////////////////////////////
Dot::Dot(const Dot& rhs) 
{
    x_coordinate = rhs.x();
    y_coordinate = rhs.y();
}
//////////////////////////////////////////////////////////////////////
// Zuweisungsoperator
//////////////////////////////////////////////////////////////////////
Dot& Dot::operator =(const Dot &rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	x_coordinate = rhs.x();
    y_coordinate = rhs.y();
	
	return *this;
}

//////////////////////////////////////////////////////////////////////
// Speicherungsfunktionen
//////////////////////////////////////////////////////////////////////
IMPLEMENT_SERIAL(Dot, CObject, 1)
void Dot::Serialize(CArchive& ar)
{
	// call base class function first
	// base class is CObject in this case
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << x_coordinate;
		ar << y_coordinate;
	}
	else
	{
		ar >> x_coordinate;
		ar >> y_coordinate;
	}
}