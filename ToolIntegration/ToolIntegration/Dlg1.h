#pragma once


// CDlg1 dialog

class CDlg1 : public CDialog
{
	DECLARE_DYNAMIC(CDlg1)

public:
	CDlg1(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlg1();

// Dialog Data
	enum { IDD = IDD_DLG_1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnChar2hex();
	afx_msg void OnBnClickedBtnHex2char();
	afx_msg void OnBnClickedBtnExchange();
	afx_msg void OnBnClickedBtnUpper();
	afx_msg void OnBnClickedBtnLower();
	afx_msg void OnBnClickedBtnBase64en();
	afx_msg void OnBnClickedBtnBase64de();
	afx_msg void OnBnClickedBtnNospace();
	afx_msg void OnBnClickedBtnNoreturn();
	afx_msg void OnBnClickedBtnClear();
	afx_msg void OnBnClickedBtnBinaryfile();
	afx_msg void OnBnClickedBtnRevdata();
};
