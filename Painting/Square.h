#ifndef _Square_h
#define _Square_h

#include "stdafx.h"
#include "Dot.h"
#include "Shape.h" 

class Square : public Shape 
{
  public:
    Square(Dot lu, Dot ru, Dot ro, Dot lo);
    Square();
	virtual ~Square();
 	Square(const Square& rhs); 
	Square& operator =(const Square &rhs);

    double getArea();
    double getCircumference();
    void Draw(CDC* pDC);

	virtual void Serialize(CArchive& ar);
	DECLARE_SERIAL(Square)

  private:
    Dot A;
    Dot B;
    Dot C;
    Dot D;
};
#endif
