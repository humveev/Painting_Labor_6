// DlgCircle.cpp : implementation file
//

#include "stdafx.h"
#include "Painting.h"
#include "DlgCircle.h"
#include "Dot.h"
#include "Circle.h"
#include "afxdialogex.h"


// CDlgCircle dialog

IMPLEMENT_DYNAMIC(CDlgCircle, CDialog)

CDlgCircle::CDlgCircle(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_CIRCLE, pParent)
	, m_DOT_M_X(0)
	, m_DOT_M_Y(0)
	, m_RADIUS(0)
{

}

CDlgCircle::~CDlgCircle()
{
}

void CDlgCircle::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_DOT_M_X, m_DOT_M_X);
	DDV_MinMaxUInt(pDX, m_DOT_M_X, 0, 30000);
	DDX_Text(pDX, IDC_DOT_M_Y, m_DOT_M_Y);
	DDV_MinMaxUInt(pDX, m_DOT_M_Y, 0, 30000);
	DDX_Text(pDX, IDC_RADIUS, m_RADIUS);
	DDV_MinMaxUInt(pDX, m_RADIUS, 0, 30000);
}


BEGIN_MESSAGE_MAP(CDlgCircle, CDialog)
	ON_BN_CLICKED(IDOK, &CDlgCircle::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgCircle message handlers


void CDlgCircle::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	CMDIChildWnd *pChild = ((CMDIFrameWnd *)(AfxGetApp()->m_pMainWnd))->MDIGetActive();
	CPaintingDoc *pDoc = (CPaintingDoc *)pChild->GetActiveDocument();

	pDoc->AddShape(new Circle(Dot(	m_DOT_M_X, m_DOT_M_Y),
									m_RADIUS));
	UpdateData(FALSE);
	CDialog::OnOK();
}
