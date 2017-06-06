#ifndef _Triangle_h
#define _Triangle_h

#include "DlgTriangle.h"
#include "stdafx.h"
#include "Shape.h"
#include "Dot.h"

class Triangle : public Shape 
{
  public:
    Triangle();
    Triangle(Dot A, Dot B, Dot C);
	virtual ~Triangle();
 	Triangle(const Triangle& rhs); 
	Triangle& operator =(const Triangle &rhs);

    double getArea();
    double getCircumference();
    void Draw(CDC* pDC);
	virtual void Serialize(CArchive& ar);
	DECLARE_SERIAL(Triangle)
  private:
    Dot A;
    Dot B;
    Dot C;
};
#endif
