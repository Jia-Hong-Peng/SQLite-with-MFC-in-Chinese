
// MFCwithSQLiteSample.h : PROJECT_NAME ���ε{�����D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"		// �D�n�Ÿ�


// CMFCwithSQLiteSampleApp: 
// �аѾ\��@�����O�� MFCwithSQLiteSample.cpp
//

class CMFCwithSQLiteSampleApp : public CWinApp
{
public:
	CMFCwithSQLiteSampleApp();

// �мg
public:
	virtual BOOL InitInstance();

// �{���X��@

	DECLARE_MESSAGE_MAP()
};

extern CMFCwithSQLiteSampleApp theApp;