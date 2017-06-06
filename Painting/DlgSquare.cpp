// DlgSquare.cpp : implementation file
//

#include "stdafx.h"
#include "Painting.h"
#include "DlgSquare.h"
#include "Dot.h"
#include "Square.h"
#include "afxdialogex.h"


// CDlgSquare dialog

IMPLEMENT_DYNAMIC(CDlgSquare, CDialog)

CDlgSquare::CDlgSquare(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_SQUARE, pParent)
	, m_DOT_A_X(0)
	, m_DOT_A_Y(0)
	, m_DOT_B_X(0)
	, m_DOT_B_Y(0)
	, m_DOT_C_X(0)
	, m_DOT_C_Y(0)
	, m_DOT_D_X(0)
	, m_DOT_D_Y(0)
{

}

CDlgSquare::~CDlgSquare()
{
}

void CDlgSquare::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_DOT_A_X, m_DOT_A_X);
	DDX_Text(pDX, IDC_DOT_A_X, m_DOT_A_X);
	DDV_MinMaxUInt(pDX, m_DOT_A_X, 0, 30000);
	DDX_Text(pDX, IDC_DOT_A_Y, m_DOT_A_Y);
	DDV_MinMaxUInt(pDX, m_DOT_A_Y, 0, 30000);
	DDX_Text(pDX, IDC_DOT_B_X, m_DOT_B_X);
	DDV_MinMaxUInt(pDX, m_DOT_B_X, 0, 30000);
	DDX_Text(pDX, IDC_DOT_B_Y, m_DOT_B_Y);
	DDV_MinMaxUInt(pDX, m_DOT_B_Y, 0, 30000);
	DDX_Text(pDX, IDC_DOT_C_X, m_DOT_C_X);
	DDV_MinMaxUInt(pDX, m_DOT_C_X, 0, 30000);
	DDX_Text(pDX, IDC_DOT_C_Y, m_DOT_C_Y);
	DDV_MinMaxUInt(pDX, m_DOT_C_Y, 0, 30000);
	DDX_Text(pDX, IDC_DOT_D_X, m_DOT_D_X);
	DDV_MinMaxUInt(pDX, m_DOT_D_X, 0, 30000);
	DDX_Text(pDX, IDC_DOT_D_Y, m_DOT_D_Y);
	DDV_MinMaxUInt(pDX, m_DOT_D_Y, 0, 30000);
}


BEGIN_MESSAGE_MAP(CDlgSquare, CDialog)
	ON_BN_CLICKED(IDOK, &CDlgSquare::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgSquare message handlers


void CDlgSquare::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	CMDIChildWnd *pChild = ((CMDIFrameWnd *)(AfxGetApp()->m_pMainWnd))->MDIGetActive();
	CPaintingDoc *pDoc = (CPaintingDoc *)pChild->GetActiveDocument();

	pDoc->AddShape(new Square(	Dot(m_DOT_A_X, m_DOT_A_Y),
								Dot(m_DOT_B_X, m_DOT_B_Y),
								Dot(m_DOT_C_X, m_DOT_C_Y),
								Dot(m_DOT_D_X, m_DOT_D_Y)));
	UpdateData(FALSE);
	CDialog::OnOK();
}



