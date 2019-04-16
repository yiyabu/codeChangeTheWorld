
// ToolIntegrationDlg.h : header file
//

#pragma once
#include "afxcmn.h"
#include "Dlg1.h"
#include "Dlg2.h"

// CToolIntegrationDlg dialog
class CToolIntegrationDlg : public CDialogEx
{
// Construction
public:
	CToolIntegrationDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_TOOLINTEGRATION_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tabCtl;
	CDlg1 m_dlg1;
	CDlg2 m_dlg2;
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
