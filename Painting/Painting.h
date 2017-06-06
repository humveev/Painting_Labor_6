
// Painting.h: Hauptheaderdatei f�r die Painting-Anwendung
//
#pragma once

#ifndef __AFXWIN_H__
	#error "'stdafx.h' vor dieser Datei f�r PCH einschlie�en"
#endif

#include "resource.h"       // Hauptsymbole


// CPaintingApp:
// Siehe Painting.cpp f�r die Implementierung dieser Klasse
//

class CPaintingApp : public CWinApp
{
public:
	CPaintingApp();
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
// �berschreibungen
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementierung
	afx_msg void OnAppAbout();
	void OnTriangle();
	DECLARE_MESSAGE_MAP()
};

extern CPaintingApp theApp;
