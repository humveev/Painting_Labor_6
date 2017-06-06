
// Painting.cpp: Definiert das Klassenverhalten für die Anwendung.
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "Painting.h"
#include "MainFrm.h"
#include "DlgTriangle.h"
#include "DlgCircle.h"
#include "DlgOblong.h"
#include "DlgSquare.h"
#include "ChildFrm.h"
#include "PaintingDoc.h"
#include "PaintingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPaintingApp

BEGIN_MESSAGE_MAP(CPaintingApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CPaintingApp::OnAppAbout)
	// Dateibasierte Standarddokumentbefehle
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
	// Standarddruckbefehl "Seite einrichten"
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinApp::OnFilePrintSetup)
	ON_COMMAND(ID_EINF32771, &CPaintingApp::OnTriangle)
	ON_COMMAND(ID_EINF32772, &CPaintingApp::OnCircle)
	ON_COMMAND(ID_Menu, &CPaintingApp::OnOblong)
	ON_COMMAND(ID_EINF32774, &CPaintingApp::OnSquare)
END_MESSAGE_MAP()


// CPaintingApp-Erstellung

CPaintingApp::CPaintingApp()
{
	// TODO: Ersetzen Sie die Anwendungs-ID-Zeichenfolge unten durch eine eindeutige ID-Zeichenfolge; empfohlen
	// Das Format für die Zeichenfolge ist: CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("Painting.AppID.NoVersion"));

	// TODO: Hier Code zur Konstruktion einfügen
	// Alle wichtigen Initialisierungen in InitInstance positionieren
}

// Das einzige CPaintingApp-Objekt

CPaintingApp theApp;


// CPaintingApp-Initialisierung

BOOL CPaintingApp::InitInstance()
{
	// InitCommonControlsEx() ist für Windows XP erforderlich, wenn ein Anwendungsmanifest
	// die Verwendung von ComCtl32.dll Version 6 oder höher zum Aktivieren
	// von visuellen Stilen angibt.  Ansonsten treten beim Erstellen von Fenstern Fehler auf.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Legen Sie dies fest, um alle allgemeinen Steuerelementklassen einzubeziehen,
	// die Sie in Ihrer Anwendung verwenden möchten.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	CWinApp::InitInstance();


	// OLE-Bibliotheken initialisieren
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// AfxInitRichEdit2() ist für die Verwendung des RichEdit-Steuerelements erforderlich.	
	// AfxInitRichEdit2();

	// Standardinitialisierung
	// Wenn Sie diese Funktionen nicht verwenden und die Größe
	// der ausführbaren Datei verringern möchten, entfernen Sie
	// die nicht erforderlichen Initialisierungsroutinen.
	// Ändern Sie den Registrierungsschlüssel, unter dem Ihre Einstellungen gespeichert sind.
	// TODO: Ändern Sie diese Zeichenfolge entsprechend,
	// z.B. zum Namen Ihrer Firma oder Organisation.
	SetRegistryKey(_T("Vom lokalen Anwendungs-Assistenten generierte Anwendungen"));
	LoadStdProfileSettings(4);  // Standard INI-Dateioptionen laden (einschließlich MRU)


	// Dokumentvorlagen der Anwendung registrieren.  Dokumentvorlagen
	//  dienen als Verbindung zwischen Dokumenten, Rahmenfenstern und Ansichten.
	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(IDR_PaintingTYPE,
		RUNTIME_CLASS(CPaintingDoc),
		RUNTIME_CLASS(CChildFrame), // Benutzerspezifischer MDI-Child-Rahmen
		RUNTIME_CLASS(CPaintingView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	// Haupt-MDI-Rahmenfenster erstellen
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;

	// Rufen Sie DragAcceptFiles nur auf, wenn eine Suffix vorhanden ist.
	//  In einer MDI-Anwendung ist dies unmittelbar nach dem Festlegen von m_pMainWnd erforderlich
	// Öffnen mit Drag Drop aktivieren
	m_pMainWnd->DragAcceptFiles();

	// Befehlszeile auf Standardumgebungsbefehle überprüfen, DDE, Datei öffnen
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// DDE-Execute-Open aktivieren
	EnableShellOpen();
	RegisterShellFileTypes(TRUE);


	// Verteilung der in der Befehlszeile angegebenen Befehle.  Gibt FALSE zurück, wenn
	// die Anwendung mit /RegServer, /Register, /Unregserver oder /Unregister gestartet wurde.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// Das Hauptfenster ist initialisiert und kann jetzt angezeigt und aktualisiert werden.
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}

int CPaintingApp::ExitInstance()
{
	//TODO: Zusätzliche Ressourcen behandeln, die Sie möglicherweise hinzugefügt haben
	AfxOleTerm(FALSE);

	return CWinApp::ExitInstance();
}

// CPaintingApp-Meldungshandler


// CAboutDlg-Dialogfeld für Anwendungsbefehl "Info"

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung

// Implementierung
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// Anwendungsbefehl zum Ausführen des Dialogfelds
void CPaintingApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CPaintingApp-Meldungshandler





void CPaintingApp::OnTriangle()
{
	// TODO: Add your command handler code here
	CDlgTriangle triangleDlg;
	triangleDlg.DoModal();
}


void CPaintingApp::OnCircle()
{
	// TODO: Add your command handler code here
	CDlgCircle circleDlg;
	circleDlg.DoModal();
}


void CPaintingApp::OnOblong()
{
	// TODO: Add your command handler code here
	CDlgOblong oblongDlg;
	oblongDlg.DoModal();
}


void CPaintingApp::OnSquare()
{
	// TODO: Add your command handler code here
	CDlgSquare squareDlg;
	squareDlg.DoModal();
}
