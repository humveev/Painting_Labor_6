// DlgTriangle.cpp : implementation file
//

#include "stdafx.h"
#include "PaintingDoc.h"
#include "Painting.h"
#include "DlgTriangle.h"
#include "Dot.h"
#include "Triangle.h"
#include "afxdialogex.h"


// CDlgTriangle dialog

IMPLEMENT_DYNAMIC(CDlgTriangle, CDialog)

CDlgTriangle::CDlgTriangle(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_TRIANGLE, pParent)
	, m_DOT_A_X(0)
	, m_DOT_A_Y(0)
	, m_DOT_B_X(0)
	, m_DOT_B_Y(0)
	, m_DOT_C_X(0)
	, m_DOT_C_Y(0)
{

}

CDlgTriangle::~CDlgTriangle()
{
}

void CDlgTriangle::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

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
}


BEGIN_MESSAGE_MAP(CDlgTriangle, CDialog)
	ON_BN_CLICKED(IDOK, &CDlgTriangle::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgTriangle message handlers


void CDlgTriangle::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CMDIChildWnd *pChild = ((CMDIFrameWnd *)(AfxGetApp()->m_pMainWnd))->MDIGetActive();
	CPaintingDoc *pDoc = (CPaintingDoc *) pChild->GetActiveDocument();

	pDoc->AddShape(new Triangle(Dot(m_DOT_A_X, m_DOT_A_Y),
								Dot(m_DOT_B_X, m_DOT_B_Y),
								Dot(m_DOT_C_X, m_DOT_C_Y)));
	UpdateData(FALSE);
	CDialog::OnOK();
}
