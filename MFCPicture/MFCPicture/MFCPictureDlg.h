
// MFCPictureDlg.h : 头文件
//

#pragma once
#include "resource.h"
#include <cv.h>
#include <highgui.h>
#include <cxcore.h>
#include <cv.hpp>
#include <opencv.hpp>
//#include <lnimage.h>
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
#include <iostream>
#include <opencv2/stitching.hpp>
using namespace  cv;
using namespace  std;

// CMFCPictureDlg 对话框
class CMFCPictureDlg : public CDialogEx
{
// 构造
public:
	CMFCPictureDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFCPICTURE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_strPic1;
	CString m_strPic2;
	CString m_strPic3;
	CString m_strPic4;
	CString m_strFileTitle;
	CString m_strFileExt;
	CString m_strFileFolder;
	afx_msg void OnBnClickedBtnChoose1();
	afx_msg void OnBnClickedBtnChoose2();
	afx_msg void OnBnClickedBtnChoose3();
	afx_msg void OnBnClickedBtnChoose4();
	afx_msg void OnBnClickedOk();
private:
	vector<Mat> imgs;
	Mat pano;
	int flg[3];
	BOOL WritePic(const char* pszFileName, const char* pchData, int nDataSize);
};
