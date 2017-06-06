#pragma once
#include "PaintingDoc.h"

// CDlgTriangle dialog

class CDlgTriangle : public CDialog
{
	DECLARE_DYNAMIC(CDlgTriangle)

public:
	CDlgTriangle(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgTriangle();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TRIANGLE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	UINT m_DOT_A_X;
	UINT m_DOT_A_Y;
	UINT m_DOT_B_X;
	UINT m_DOT_B_Y;
	UINT m_DOT_C_X;
	UINT m_DOT_C_Y;
	afx_msg void OnBnClickedOk();
};
