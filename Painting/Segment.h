#ifndef _Segment_h
#define _Segment_h
#include "stdafx.h"
#include "Dot.h"

class Segment  
{
  public:
    // Konstruktoren
    Segment();   
	Segment(Dot sStart, Dot sEnd);
    virtual ~Segment();
 	Segment(const Segment& ); 
	Segment& operator=(const Segment &);

    void Draw(CDC* pDC);
	// setter / getter
    void setStart(Dot start);
    Dot getStart() const;

    void setEnd(Dot end);
	Dot getEnd() const;

	double getLength() const;

  private:
    Dot Start;
    Dot End;

};
#endif

