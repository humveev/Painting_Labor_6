#ifndef _Oblong_h
#define _Oblong_h

#include "stdafx.h"
#include "Shape.h"
#include "Dot.h"

class Oblong : public Shape 
{ 
  public:
    Oblong();    
	Oblong(Dot lu, Dot ru, Dot ro, Dot lo);
    virtual ~Oblong();
 	Oblong(const Oblong& rhs); 
	virtual Oblong& operator =(const Oblong &rhs);

    virtual double getArea();
    virtual double getCircumference();
    virtual void Draw(CDC* pDC);

	virtual void Serialize(CArchive& ar);
	DECLARE_SERIAL(Oblong)

  private:
    Dot A;
    Dot B;
    Dot C;
    Dot D;
};
#endif
