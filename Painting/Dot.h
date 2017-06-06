#ifndef _Dot_h
#define _Dot_h

#include "stdafx.h"
using namespace std;

class Dot : public CObject
{
  public:

    Dot();
    Dot(int x_coordinate, int y_coordinate);
    virtual ~Dot();
 	Dot(const Dot& p); 
	Dot& operator =(const Dot &);

	int x() const;
    int y() const;
	virtual void Serialize(CArchive &ar);
	DECLARE_SERIAL(Dot)

  private:

	int x_coordinate;
    int y_coordinate;

};
#endif
