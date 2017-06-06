
// PaintingDoc.h: Schnittstelle der Klasse CPaintingDoc
//


#pragma once
#include "Shape.h"
#include "DlgTriangle.h"


class CPaintingDoc : public CDocument
{
private:
	CTypedPtrArray <CObArray, Shape*> *myShapes;
public:
	void AddShape(Shape *);
	void DrawAll(CDC *pDC);
protected: // Nur aus Serialisierung erstellen
	CPaintingDoc();
	DECLARE_DYNCREATE(CPaintingDoc)

// Attribute
public:

// Vorgänge
public:

// Überschreibungen
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementierung
public:
	virtual ~CPaintingDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generierte Funktionen für die Meldungstabellen
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Hilfsfunktion, die Suchinhalt für Suchhandler festlegt
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
