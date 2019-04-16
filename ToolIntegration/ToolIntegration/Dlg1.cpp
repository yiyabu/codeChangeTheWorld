// Dlg1.cpp : implementation file
//

#include "stdafx.h"
#include "ToolIntegration.h"
#include "Dlg1.h"
#include "afxdialogex.h"


// CDlg1 dialog

IMPLEMENT_DYNAMIC(CDlg1, CDialog)

CDlg1::CDlg1(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg1::IDD, pParent)
{

}

CDlg1::~CDlg1()
{
}

void CDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg1, CDialog)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BTN_CHAR2HEX, &CDlg1::OnBnClickedBtnChar2hex)
	ON_BN_CLICKED(IDC_BTN_HEX2CHAR, &CDlg1::OnBnClickedBtnHex2char)
	ON_BN_CLICKED(IDC_BTN_EXCHANGE, &CDlg1::OnBnClickedBtnExchange)
	ON_BN_CLICKED(IDC_BTN_UPPER, &CDlg1::OnBnClickedBtnUpper)
	ON_BN_CLICKED(IDC_BTN_LOWER, &CDlg1::OnBnClickedBtnLower)
	ON_BN_CLICKED(IDC_BTN_BASE64EN, &CDlg1::OnBnClickedBtnBase64en)
	ON_BN_CLICKED(IDC_BTN_BASE64DE, &CDlg1::OnBnClickedBtnBase64de)
	ON_BN_CLICKED(IDC_BTN_NOSPACE, &CDlg1::OnBnClickedBtnNospace)
	ON_BN_CLICKED(IDC_BTN_NORETURN, &CDlg1::OnBnClickedBtnNoreturn)
	ON_BN_CLICKED(IDC_BTN_CLEAR, &CDlg1::OnBnClickedBtnClear)
	ON_BN_CLICKED(IDC_BTN_BINARYFILE, &CDlg1::OnBnClickedBtnBinaryfile)
	ON_BN_CLICKED(IDC_BTN_REVDATA, &CDlg1::OnBnClickedBtnRevdata)
END_MESSAGE_MAP()


// CDlg1 message handlers

BOOL CDlg1::OnInitDialog()
{
	CDialog::OnInitDialog();
	CRect rect;
	GetClientRect(&rect);
	rect.left = 0;
	rect.top = 0;
	rect.right = 750;
	rect.bottom = 500;
	MoveWindow(rect);
	return TRUE;
}

HBRUSH CDlg1::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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

void CDlg1::OnBnClickedBtnChar2hex()
{
	CString str;
	((CEdit*)GetDlgItem(IDC_EDT_SRCDATA))->GetWindowText(str);

	char* pszData = NULL;
	int nSize = 0;
	WideString2Hex(str.GetBuffer(0), NULL, &nSize);
	pszData = new char[nSize];
	if ( !pszData )
	{
		return;
	}
	WideString2Hex(str.GetBuffer(0), pszData, &nSize);
	((CEdit*)GetDlgItem(IDC_EDT_DSTDATA))->SetWindowText(CString(pszData));
	delete []pszData;
	pszData = NULL;
}


void CDlg1::OnBnClickedBtnHex2char()
{
	DWORD dwRet = 0;
	CString str;
	((CEdit*)GetDlgItem(IDC_EDT_SRCDATA))->GetWindowText(str);

	char* pszData = NULL;
	int nSize = 0;
	WideHex2String(str.GetBuffer(0), NULL, &nSize);
	pszData = new char[nSize];
	if ( !pszData )
	{
		return;
	}
	dwRet = WideHex2String(str.GetBuffer(0), pszData, &nSize);
	if ( ERR_OK != dwRet )
	{
		MessageBox(_T("数据格式不对"), _T("提示"), MB_OK);
		return;
	}
	((CEdit*)GetDlgItem(IDC_EDT_DSTDATA))->SetWindowText(CString(pszData));
	delete []pszData;
	pszData = NULL;
}


void CDlg1::OnBnClickedBtnExchange()
{
	CString strSrc;
	CString strDst;
	((CEdit*)GetDlgItem(IDC_EDT_SRCDATA))->GetWindowText(strSrc);
	((CEdit*)GetDlgItem(IDC_EDT_DSTDATA))->GetWindowText(strDst);

	((CEdit*)GetDlgItem(IDC_EDT_SRCDATA))->SetWindowText(strDst);
	((CEdit*)GetDlgItem(IDC_EDT_DSTDATA))->SetWindowText(strSrc);
}


void CDlg1::OnBnClickedBtnUpper()
{
	CString strSrc;
	((CEdit*)GetDlgItem(IDC_EDT_SRCDATA))->GetWindowText(strSrc);

	ToUpper(strSrc.GetBuffer(0));

	((CEdit*)GetDlgItem(IDC_EDT_DSTDATA))->SetWindowText(strSrc);
}


void CDlg1::OnBnClickedBtnLower()
{
	CString strSrc;
	((CEdit*)GetDlgItem(IDC_EDT_SRCDATA))->GetWindowText(strSrc);

	ToLower(strSrc.GetBuffer(0));

	((CEdit*)GetDlgItem(IDC_EDT_DSTDATA))->SetWindowText(strSrc);
}

/************************************************************************/
/*                         
base64编码的好处						
1.传输的数据如果有特殊字符，某些情景下传输会导致编码混乱无法显示，通过base64编码后，然后解码会保证传输的准确性
2.base64编码的数据具有不可读性
*/
/************************************************************************/
void CDlg1::OnBnClickedBtnBase64en()
{
	CString strSrc;
	((CEdit*)GetDlgItem(IDC_EDT_SRCDATA))->GetWindowText(strSrc);

	char* pszData = NULL;
	int nSize = 0;
	Base64_Encode(strSrc.GetBuffer(0), NULL, &nSize);
	strSrc.ReleaseBuffer();
	pszData = new char[nSize+1];
	if ( !pszData )
	{
		return;
	}
	Base64_Encode(strSrc.GetBuffer(0), pszData, &nSize);
	strSrc.ReleaseBuffer();
	pszData[nSize] = '\0';

	((CEdit*)GetDlgItem(IDC_EDT_DSTDATA))->SetWindowText(CString(pszData));
	delete []pszData;
	pszData = NULL;
}


void CDlg1::OnBnClickedBtnBase64de()
{
	CString strSrc;
	((CEdit*)GetDlgItem(IDC_EDT_SRCDATA))->GetWindowText(strSrc);

	char* pszData = NULL;
	int nSize = 0;
	Base64_Decode(strSrc.GetBuffer(0), NULL, &nSize);
	strSrc.ReleaseBuffer();
	pszData = new char[nSize+1];
	if ( !pszData )
	{
		return;
	}
	Base64_Decode(strSrc.GetBuffer(0), pszData, &nSize);
	strSrc.ReleaseBuffer();
	pszData[nSize] = '\0';

	((CEdit*)GetDlgItem(IDC_EDT_DSTDATA))->SetWindowText(CString(pszData));
	delete []pszData;
	pszData = NULL;
}


void CDlg1::OnBnClickedBtnNospace()
{
	CString strSrc;
	((CEdit*)GetDlgItem(IDC_EDT_SRCDATA))->GetWindowText(strSrc);
	strSrc.Replace(_T(" "),_T(""));
	strSrc.Replace(_T("\t"),_T(""));
	((CEdit*)GetDlgItem(IDC_EDT_DSTDATA))->SetWindowText(strSrc);
}


void CDlg1::OnBnClickedBtnNoreturn()
{
	CString strSrc;
	((CEdit*)GetDlgItem(IDC_EDT_SRCDATA))->GetWindowText(strSrc);
	strSrc.Replace(_T("\n"),_T(""));
	((CEdit*)GetDlgItem(IDC_EDT_DSTDATA))->SetWindowText(strSrc);
}


void CDlg1::OnBnClickedBtnClear()
{
	((CEdit*)GetDlgItem(IDC_EDT_DSTDATA))->SetWindowText(_T(""));
}


void CDlg1::OnBnClickedBtnBinaryfile()
{
	DWORD dwRet = 0;
	CString strSrc;
	((CEdit*)GetDlgItem(IDC_EDT_DSTDATA))->GetWindowText(strSrc);
	CFileDialog fileObj(FALSE, _T("dat"), 0, 6UL, _T("DAT文件(*.dat)|*.dat||"), NULL,0,1);
	if ( IDOK == fileObj.DoModal() )
	{
		CString strPath = fileObj.GetPathName();
		dwRet = SaveToBinaryFile(strSrc.GetBuffer(0), strPath.GetBuffer(0));
		if ( ERR_DATA_FORMAT == dwRet )
		{
			MessageBox(_T("数据格式不对"), _T("提示"), MB_OK);
		}else if ( ERR_OK != dwRet )
		{
			MessageBox(_T("保存失败"), _T("提示"), MB_OK);
		}else
		{
			MessageBox(_T("保存成功"), _T("提示"), MB_OK);
		}
	}
}


void CDlg1::OnBnClickedBtnRevdata()
{
	CString strSrc;
	((CEdit*)GetDlgItem(IDC_EDT_SRCDATA))->GetWindowText(strSrc);
	strSrc.MakeReverse();
	((CEdit*)GetDlgItem(IDC_EDT_DSTDATA))->SetWindowText(strSrc);
}
