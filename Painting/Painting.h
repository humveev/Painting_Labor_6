
// Painting.h: Hauptheaderdatei für die Painting-Anwendung
//
#pragma once

#ifndef __AFXWIN_H__
	#error "'stdafx.h' vor dieser Datei für PCH einschließen"
#endif

#include "resource.h"       // Hauptsymbole


// CPaintingApp:
// Siehe Painting.cpp für die Implementierung dieser Klasse
//

class CPaintingApp : public CWinApp
{
public:
	CPaintingApp();
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
// Überschreibungen
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementierung
	afx_msg void OnAppAbout();
	void OnTriangle();
	DECLARE_MESSAGE_MAP()
};

extern CPaintingApp theApp;
