
// MFCPicture.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCPictureApp: 
// �йش����ʵ�֣������ MFCPicture.cpp
//

class CMFCPictureApp : public CWinApp
{
public:
	CMFCPictureApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCPictureApp theApp;