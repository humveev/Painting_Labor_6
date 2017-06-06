#pragma once
#include "PaintingDoc.h"
#include "Oblong.h"


// CDlgOblong dialog

class CDlgOblong : public CDialog
{
	DECLARE_DYNAMIC(CDlgOblong)

public:
	CDlgOblong(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgOblong();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OBLONG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	UINT m_DOT_A_X;
	UINT m_DOT_A_Y;
	UINT m_DOT_B_X;
	UINT m_DOT_B_Y;
	UINT m_DOT_C_X;
	UINT m_DOT_C_Y;
	UINT m_DOT_D_X;
	UINT m_DOT_D_Y;
};
