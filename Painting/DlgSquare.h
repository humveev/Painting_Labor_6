#pragma once
#include "PaintingDoc.h"
#include "Square.h"


// CDlgSquare dialog

class CDlgSquare : public CDialog
{
	DECLARE_DYNAMIC(CDlgSquare)

public:
	CDlgSquare(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgSquare();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SQUARE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
//	UINT m_DOT_A_X;
	UINT m_DOT_A_X;
	UINT m_DOT_A_Y;
	UINT m_DOT_B_X;
	UINT m_DOT_B_Y;
	UINT m_DOT_C_X;
	UINT m_DOT_C_Y;
	UINT m_DOT_D_X;
	UINT m_DOT_D_Y;
};
