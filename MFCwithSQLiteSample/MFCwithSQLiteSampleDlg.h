
// MFCwithSQLiteSampleDlg.h : ���Y��
//

#pragma once
#include "SQLite.h"  
#pragma comment(lib,"sqlite.lib")   
using namespace SQLite;

// CMFCwithSQLiteSampleDlg ��ܤ��
class CMFCwithSQLiteSampleDlg : public CDialogEx
{
// �غc
public:
	CMFCwithSQLiteSampleDlg(CWnd* pParent = NULL);	// �зǫغc�禡

// ��ܤ�����
	enum { IDD = IDD_MFCWITHSQLITESAMPLE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �䴩
	char CStringToChar();

// �{���X��@
protected:
	HICON m_hIcon;

	// ���ͪ��T�������禡
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();

	BOOL CMFCwithSQLiteSampleDlg::OpenDb(CString dbName);
	void CMFCwithSQLiteSampleDlg::CloseDb();
	void CMFCwithSQLiteSampleDlg::CreateTable();
	Table CMFCwithSQLiteSampleDlg::Select(CString strTable, CString strSelect);
	Table CMFCwithSQLiteSampleDlg::Select(CString strTable, CString strSelect, CString strWhere);
	BOOL CMFCwithSQLiteSampleDlg::Insert(CString strTable, CString strValue);
	BOOL CMFCwithSQLiteSampleDlg::Update(CString strTable, CString strSet, CString strWhere);
	BOOL CMFCwithSQLiteSampleDlg::Update(CString strTable, CString strSet);
	BOOL CMFCwithSQLiteSampleDlg::Delete(CString strTable, CString strWhere);
	
	virtual BOOL DestroyWindow();

private:
	Database m_db;
};
