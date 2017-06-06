#include "stdafx.h"
#include <math.h>
#include "Text.h"
//////////////////////////////////////////////////////////////////////
// Konstruktion/Destruktion
//////////////////////////////////////////////////////////////////////

Text::Text(CString sText)
{
	len=sText.GetLength(); 
	szText=(WCHAR *) (LPCTSTR) sText;
}
void Text::Print(CDC* pDC, int x, int y)
{   
	const REAL x_tracking=15;
    const REAL y_tracking=25;

	REAL x_coord=(REAL) x;
	REAL y_coord=(REAL) y;
	REAL width=len*x_tracking; 
	REAL height=y_tracking;
	
 
	HDC hdc=pDC->m_hDC;
	Graphics graphics(hdc);

    // Initialize arguments.
    Gdiplus::Font myFont(L"Arial", 12);
    
    RectF layoutRect( x_coord, y_coord, width, height);
    StringFormat format;
    format.SetAlignment(StringAlignmentNear);
    SolidBrush blackBrush(Color(255, 0, 0, 0));

	graphics.DrawString(
     szText,
     len,
     &myFont,
     layoutRect,
     &format,
     &blackBrush);
}

Text::~Text()
{
	len=0;
	szText=NULL;

	}
Text& Text::operator=(CString sText)
{
	len=sText.GetLength(); 
	szText=(WCHAR *) (LPCTSTR) sText;
	return (*this);
}
