
// PaintingView.cpp: Implementierung der Klasse CPaintingView
//

#include "stdafx.h"
// SHARED_HANDLERS können in einem ATL-Projekt definiert werden, in dem Vorschau-, Miniaturansichts- 
// und Suchfilterhandler implementiert werden, und die Freigabe von Dokumentcode für das Projekt wird ermöglicht.
#ifndef SHARED_HANDLERS
#include "Painting.h"
#endif

#include "PaintingDoc.h"
#include "PaintingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPaintingView

IMPLEMENT_DYNCREATE(CPaintingView, CView)

BEGIN_MESSAGE_MAP(CPaintingView, CView)
	// Standarddruckbefehle
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CPaintingView-Erstellung/Zerstörung

CPaintingView::CPaintingView()
{
	// TODO: Hier Code zur Konstruktion einfügen

}

CPaintingView::~CPaintingView()
{
}

BOOL CPaintingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Ändern Sie hier die Fensterklasse oder die Darstellung, indem Sie
	//  CREATESTRUCT cs modifizieren.

	return CView::PreCreateWindow(cs);
}

// CPaintingView-Zeichnung

void CPaintingView::OnDraw(CDC* pDC)
{
	CPaintingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: Code zum Zeichnen der nativen Daten hinzufügen
	pDoc->DrawAll(pDC);
}


// CPaintingView drucken

BOOL CPaintingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Standardvorbereitung
	return DoPreparePrinting(pInfo);
}

void CPaintingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: Zusätzliche Initialisierung vor dem Drucken hier einfügen
}

void CPaintingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: Bereinigung nach dem Drucken einfügen
}


// CPaintingView-Diagnose

#ifdef _DEBUG
void CPaintingView::AssertValid() const
{
	CView::AssertValid();
}

void CPaintingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPaintingDoc* CPaintingView::GetDocument() const // Nichtdebugversion ist inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPaintingDoc)));
	return (CPaintingDoc*)m_pDocument;
}
#endif //_DEBUG


// CPaintingView-Meldungshandler
