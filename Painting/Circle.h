#ifndef _Circle_h
#define _Circle_h

#include "stdafx.h"
#include "Dot.h"
#include "Shape.h"

class Circle : public Shape 
{
  public:
    Circle();
	Circle(Dot center, int radius);
    virtual ~Circle();

	Circle(const Circle& rhs);
	virtual Circle& operator=(const Circle &rhs);

    virtual double getArea();
    virtual double getCircumference();
    virtual void Draw(CDC* pDC);


private:
    int radius;
	Dot center;
};
#endif
