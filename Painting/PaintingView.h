
// PaintingView.h: Schnittstelle der Klasse CPaintingView
//

#pragma once


class CPaintingView : public CView
{
protected: // Nur aus Serialisierung erstellen
	CPaintingView();
	DECLARE_DYNCREATE(CPaintingView)

// Attribute
public:
	CPaintingDoc* GetDocument() const;

// Vorg�nge
public:

// �berschreibungen
public:
	virtual void OnDraw(CDC* pDC);  // �berschrieben, um diese Ansicht darzustellen
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementierung
public:
	virtual ~CPaintingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generierte Funktionen f�r die Meldungstabellen
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Debugversion in PaintingView.cpp
inline CPaintingDoc* CPaintingView::GetDocument() const
   { return reinterpret_cast<CPaintingDoc*>(m_pDocument); }
#endif

