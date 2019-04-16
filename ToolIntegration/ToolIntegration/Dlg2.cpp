// Dlg2.cpp : implementation file
//

#include "stdafx.h"
#include "ToolIntegration.h"
#include "Dlg2.h"
#include "afxdialogex.h"


// CDlg2 dialog

IMPLEMENT_DYNAMIC(CDlg2, CDialog)

CDlg2::CDlg2(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg2::IDD, pParent)
{

}

CDlg2::~CDlg2()
{
}

void CDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg2, CDialog)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BTN_PIC_COM, &CDlg2::OnBnClickedBtnPicCom)
END_MESSAGE_MAP()


// CDlg2 message handlers

HBRUSH CDlg2::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  Change any attributes of the DC here
	
	switch (nCtlColor)
	{
		/*
	case CTLCOLOR_DLG://对话框颜色
		{
			HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));
			return brush;
		}
	case CTLCOLOR_EDIT:  //编辑框颜色
		{
			HBRUSH brush = CreateSolidBrush(RGB(255, 255, 0));
			return brush;
		}
	case CTLCOLOR_LISTBOX://列表框颜色
		{
			HBRUSH brush = CreateSolidBrush(RGB(0, 255, 0));
			return brush;
		}
	case CTLCOLOR_BTN:    //按钮颜色,还可以绘制字体颜色
		{
			HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
			return brush;
		}
		*/
	case CTLCOLOR_STATIC:
		{
			pDC->SetTextColor(RGB(0,0,0));  //设置字体颜色
			pDC->SetBkMode(TRANSPARENT);	//设置字体背景为透明
			HBRUSH hBrush = (HBRUSH)GetStockObject(WHITE_BRUSH);// 设置背景色
			return hBrush;
		}
	default:
		HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));
		return brush;
	}
	return hbr;
}

void CDlg2::OnBnClickedBtnPicCom()
{
	ShellExecute(this->GetSafeHwnd(), _T("open"), _T(".\\MFCPicture.exe"), NULL, NULL, SW_SHOW);
}
