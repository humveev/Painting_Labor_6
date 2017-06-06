#pragma once
#include "PaintingDoc.h"
#include "Circle.h"


// CDlgCircle dialog

class CDlgCircle : public CDialog
{
	DECLARE_DYNAMIC(CDlgCircle)

public:
	CDlgCircle(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgCircle();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CIRCLE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	UINT m_DOT_M_X;
	UINT m_DOT_M_Y;
	UINT m_RADIUS;
};
