#ifndef _Shape_h
#define _Shape_h

#include "stdafx.h"

class Shape : public CObject
{

public:
	Shape(){}
	virtual ~Shape(){}
    virtual double getCircumference() = 0;
    virtual double getArea() = 0;
    virtual void Draw(CDC* pDC) = 0;
};
#endif

