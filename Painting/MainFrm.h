
// MainFrm.h: Schnittstelle der Klasse CMainFrame
//

#pragma once

class CMainFrame : public CMDIFrameWnd
{
	DECLARE_DYNAMIC(CMainFrame)
public:
	CMainFrame();

// Attribute
public:

// Vorg�nge
public:

// �berschreibungen
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementierung
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // Eingebettete Member der Steuerleiste
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;

// Generierte Funktionen f�r die Meldungstabellen
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

};


