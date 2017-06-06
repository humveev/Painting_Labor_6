#ifndef _Text_h
#define _Text_h

#include "stdafx.h"

class Text  
{
  public:
    Text(CString sText);
	Text& operator=(CString sText);
	~Text();
    void Print(CDC* pDC, int x, int y);

  private:
    int len;
    WCHAR *szText;
};
#endif
