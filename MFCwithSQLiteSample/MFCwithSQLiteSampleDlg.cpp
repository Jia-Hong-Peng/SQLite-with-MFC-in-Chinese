
// MFCwithSQLiteSampleDlg.cpp : 實作檔
//

#include "stdafx.h"
#include "MFCwithSQLiteSample.h"
#include "MFCwithSQLiteSampleDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CString strFormatTemp = NULL;
// 對 App About 使用 CAboutDlg 對話方塊

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 對話方塊資料
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

// 程式碼實作
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCwithSQLiteSampleDlg 對話方塊



CMFCwithSQLiteSampleDlg::CMFCwithSQLiteSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCwithSQLiteSampleDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCwithSQLiteSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCwithSQLiteSampleDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCwithSQLiteSampleDlg::OnBnClickedButton1)
END_MESSAGE_MAP()



// CMFCwithSQLiteSampleDlg 訊息處理常式

BOOL CMFCwithSQLiteSampleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 將 [關於...] 功能表加入系統功能表。

	// IDM_ABOUTBOX 必須在系統命令範圍之中。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 設定此對話方塊的圖示。當應用程式的主視窗不是對話方塊時，
	// 框架會自動從事此作業
	SetIcon(m_hIcon, TRUE);			// 設定大圖示
	SetIcon(m_hIcon, FALSE);		// 設定小圖示

	// TODO:  在此加入額外的初始設定


	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
}

void CMFCwithSQLiteSampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果將最小化按鈕加入您的對話方塊，您需要下列的程式碼，
// 以便繪製圖示。對於使用文件/檢視模式的 MFC 應用程式，
// 框架會自動完成此作業。

void CMFCwithSQLiteSampleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 繪製的裝置內容

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 將圖示置中於用戶端矩形
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 描繪圖示
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 當使用者拖曳最小化視窗時，
// 系統呼叫這個功能取得游標顯示。
HCURSOR CMFCwithSQLiteSampleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


sqlite3 *db = NULL;
sqlite3_stmt *stmt = NULL;
char *sql = 0;
char *zErrMsg = 0;
char **azResult;
int nrow = 0, ncolumn = 0;

long _CrtSetBreakAlloc(long nAllocID);

void CMFCwithSQLiteSampleDlg::OnBnClickedButton1()
{
	OpenDb(_T("中文.db"));
	
	m_db.ExecuteSQL(_T("CREATE TABLE 學生信息(學號 INTEGER PRIMARY KEY,年齡 INTEGER,班級 INTEGER,姓名 VARCHAR(12));"));
	
	Insert(L"學生信息", L"NULL , 11, 1 , '明'");
	Insert(L"學生信息", L"NULL , 12, 3 , '王'");

	Update(L"學生信息", L"姓名='王大明'", L"姓名='明'");

	Delete(L"學生信息", L"姓名='王'");

	Table student = Select(L"學生信息", L"*"); 

	//for (int i = 0; i < student.GetRowCount(); i++)
	for (int i = 0; i < 1; i++)
	{
		student.GoRow(i);
		//for (int j = 0; j < student.GetColCount(); j++)
		//{
			//CString  aa = student.GetValue(j);
		CString temp;
		temp.Format(L"azResult[%d][姓名] = %s\n", i, student.GetValue(L"姓名"));
		AfxMessageBox(temp);
		//}
	}
	
}


BOOL CMFCwithSQLiteSampleDlg::OpenDb(CString dbName)
{
	if (m_db.IsOpen())
	{
		return TRUE;		
	}
	else
	{
		if (m_db.Open(dbName) == SQLITE_OK)
		{
			return TRUE;
		}		
		return FALSE;	
	}
}




Table CMFCwithSQLiteSampleDlg::Select(CString strTable, CString strSelect)
{	
	strFormatTemp.Format(_T("SELECT %s FROM %s; "), strSelect, strTable);
	Table tb = m_db.QuerySQL(strFormatTemp);
	return tb;
}

Table CMFCwithSQLiteSampleDlg::Select(CString strTable, CString strSelect, CString strWhere)
{
	strFormatTemp.Format(_T("SELECT %s FROM %s WHERE %s; "), strSelect, strTable, strWhere);
	Table tb = m_db.QuerySQL(strFormatTemp);
	return tb;
}


BOOL CMFCwithSQLiteSampleDlg::Update(CString strTable, CString strSet, CString strWhere)
{
	strFormatTemp.Format(_T("UPDATE '%s' SET %s WHERE %s; "), strTable, strSet, strWhere);
	if (m_db.IsOpen())
	{
		if (m_db.ExecuteSQL(strFormatTemp) == SQLITE_OK) return TRUE;
		else return FALSE;
	}
}


BOOL CMFCwithSQLiteSampleDlg::Update(CString strTable, CString strSet)
{
	strFormatTemp.Format(_T("UPDATE '%s' SET %s;"), strTable, strSet);
	if (m_db.IsOpen())
	{
		if (m_db.ExecuteSQL(strFormatTemp) == SQLITE_OK) return TRUE;
		else return FALSE;
	}
}

BOOL CMFCwithSQLiteSampleDlg::Insert(CString strTable, CString strValue)
{
	
	strFormatTemp.Format(_T("INSERT INTO '%s' VALUES(%s);"), strTable, strValue);
	if (m_db.IsOpen())
	{
		if (m_db.ExecuteSQL(strFormatTemp) == SQLITE_OK) return TRUE;
		else return FALSE;
	}
}


BOOL CMFCwithSQLiteSampleDlg::Delete(CString strTable, CString strWhere)
{
	
	strFormatTemp.Format(_T("DELETE FROM '%s' WHERE %s;"), strTable, strWhere);
	if (m_db.IsOpen())
	{
		if (m_db.ExecuteSQL(strFormatTemp) == SQLITE_OK) return TRUE;
		else return FALSE;
	}
}

void CMFCwithSQLiteSampleDlg::CloseDb()
{
	if (m_db.IsOpen())
	{
		m_db.Close();
	}
}

BOOL CMFCwithSQLiteSampleDlg::DestroyWindow()
{
	
	CloseDb();
	return CDialogEx::DestroyWindow();
}
