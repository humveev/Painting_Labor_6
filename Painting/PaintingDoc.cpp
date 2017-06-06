
// PaintingDoc.cpp: Implementierung der Klasse CPaintingDoc
//

#include "stdafx.h"
// SHARED_HANDLERS k�nnen in einem ATL-Projekt definiert werden, in dem Vorschau-, Miniaturansichts- 
// und Suchfilterhandler implementiert werden, und die Freigabe von Dokumentcode f�r das Projekt wird erm�glicht.
#ifndef SHARED_HANDLERS
#include "Painting.h"
#endif

#include "PaintingDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CPaintingDoc

IMPLEMENT_DYNCREATE(CPaintingDoc, CDocument)

BEGIN_MESSAGE_MAP(CPaintingDoc, CDocument)
END_MESSAGE_MAP()


// CPaintingDoc-Erstellung/Zerst�rung

void CPaintingDoc::AddShape(Shape *s)
{
	myShapes->Add(s);			//Add Shape s
	SetModifiedFlag();			//Document Data has changed
	UpdateAllViews(NULL);		//Changes shall be visible
}

void CPaintingDoc::DrawAll(CDC * pDC)
{
	for (int i = 0; i < myShapes->GetSize(); i++)
		myShapes->GetAt(i)->Draw(pDC);
}

CPaintingDoc::CPaintingDoc()
{
	// TODO: Hier Code f�r One-Time-Konstruktion einf�gen
	myShapes = new CTypedPtrArray <CObArray, Shape*>;
}

CPaintingDoc::~CPaintingDoc()
{
	for (int i = 0; i < myShapes->GetSize(); i++)
		delete myShapes->GetAt(i);
	myShapes->RemoveAll();
	delete myShapes;
}

BOOL CPaintingDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: Hier Code zur Reinitialisierung einf�gen
	// (SDI-Dokumente verwenden dieses Dokument)

	return TRUE;
}




// CPaintingDoc-Serialisierung

void CPaintingDoc::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	myShapes->Serialize(ar);
}

#ifdef SHARED_HANDLERS

// Unterst�tzung f�r Miniaturansichten
void CPaintingDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �ndern Sie diesen Code, um die Dokumentdaten zu zeichnen.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Unterst�tzung f�r Suchhandler
void CPaintingDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Suchinhalte aus Dokumentdaten festlegen. 
	// Die Inhaltsteile sollten durch ";" getrennt werden.

	// Beispiel:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CPaintingDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CPaintingDoc-Diagnose

#ifdef _DEBUG
void CPaintingDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPaintingDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CPaintingDoc-Befehle
