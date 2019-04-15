
// MFCPictureDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCPicture.h"
#include "MFCPictureDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMFCPictureDlg 对话框



CMFCPictureDlg::CMFCPictureDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCPictureDlg::IDD, pParent)
	, m_strPic1(_T(""))
	, m_strPic2(_T(""))
	, m_strPic3(_T(""))
	, m_strPic4(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCPictureDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strPic1);
	DDX_Text(pDX, IDC_EDIT2, m_strPic2);
	DDX_Text(pDX, IDC_EDIT3, m_strPic3);
	DDX_Text(pDX, IDC_EDIT4, m_strPic4);
}

BEGIN_MESSAGE_MAP(CMFCPictureDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_CHOOSE1, &CMFCPictureDlg::OnBnClickedBtnChoose1)
	ON_BN_CLICKED(IDC_BTN_CHOOSE2, &CMFCPictureDlg::OnBnClickedBtnChoose2)
	ON_BN_CLICKED(IDC_BTN_CHOOSE3, &CMFCPictureDlg::OnBnClickedBtnChoose3)
	ON_BN_CLICKED(IDC_BTN_CHOOSE4, &CMFCPictureDlg::OnBnClickedBtnChoose4)
	ON_BN_CLICKED(IDOK, &CMFCPictureDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMFCPictureDlg 消息处理程序

BOOL CMFCPictureDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	((CButton*)GetDlgItem(IDC_RIO_H))->SetCheck(BST_CHECKED);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCPictureDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCPictureDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCPictureDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCPictureDlg::OnBnClickedBtnChoose1()
{
	CFileDialog file(TRUE, NULL, NULL, 4 | 2, _T("所有(*.*)|*.*||"), NULL, 0, TRUE);
	if ( IDOK == file.DoModal() )
	{
		m_strPic1 = file.GetPathName();
		m_strFileExt = file.GetFileExt();
		m_strFileFolder = file.GetFolderPath();
		m_strFileTitle = file.GetFileTitle();
		UpdateData(FALSE);
	}
}


void CMFCPictureDlg::OnBnClickedBtnChoose2()
{
	CFileDialog file(TRUE, NULL, NULL, 4 | 2, _T("所有(*.*)|*.*||"), NULL, 0, TRUE);
	if (IDOK == file.DoModal())
	{
		m_strPic2 = file.GetPathName();
		UpdateData(FALSE);
	}
}


void CMFCPictureDlg::OnBnClickedBtnChoose3()
{
	CFileDialog file(TRUE, NULL, NULL, 4 | 2, _T("所有(*.*)|*.*||"), NULL, 0, TRUE);
	if (IDOK == file.DoModal())
	{
		m_strPic3 = file.GetPathName();
		UpdateData(FALSE);
	}
}


void CMFCPictureDlg::OnBnClickedBtnChoose4()
{
	CFileDialog file(TRUE, NULL, NULL, 4 | 2, _T("所有(*.*)|*.*||"), NULL, 0, TRUE);
	if (IDOK == file.DoModal())
	{
		m_strPic4 = file.GetPathName();
		UpdateData(FALSE);
	}
}

BOOL CMFCPictureDlg::WritePic(const char* pszFileName, const char* pchData, int nDataSize)
{
	CFile file;
	BOOL bRet = FALSE;
	bRet = file.Open(CString(pszFileName), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite | CFile::typeBinary);
	if ( !bRet )
	{
		return bRet;
	}
	file.Write(pchData, nDataSize);
	file.Close();

	return TRUE;
}

void CMFCPictureDlg::OnBnClickedOk()
{
	UpdateData(TRUE);
	imgs.clear();
	// lplImage操作图像
	char imagename[MAX_PATH];
	if (0 != m_strPic4.GetLength())
	{
		// 第4张
		memset(imagename, 0, MAX_PATH);
		WideCharToMultiByte(CP_ACP, 0, m_strPic4.GetBuffer(), -1, imagename, MAX_PATH, NULL, NULL);
		Mat img4 = imread(imagename, CV_LOAD_IMAGE_UNCHANGED);
		if (img4.empty())
		{
			MessageBox(_T("提示：不能打开图像文件4，退出！"));
			return;
		}
		imgs.push_back(img4);
	}
	if (0 != m_strPic3.GetLength())
	{
		// 第3张
		memset(imagename, 0, MAX_PATH);
		WideCharToMultiByte(CP_ACP, 0, m_strPic3.GetBuffer(), -1, imagename, MAX_PATH, NULL, NULL);
		Mat img3 = imread(imagename, CV_LOAD_IMAGE_UNCHANGED);
		if (img3.empty())
		{
			MessageBox(_T("提示：不能打开图像文件3，退出！"));
			return;
		}
		imgs.push_back(img3);
	}
	if (0 != m_strPic2.GetLength())
	{
		// 第2张
		memset(imagename, 0, MAX_PATH);
		WideCharToMultiByte(CP_ACP, 0, m_strPic2.GetBuffer(), -1, imagename, MAX_PATH, NULL, NULL);
		Mat img2 = imread(imagename, CV_LOAD_IMAGE_UNCHANGED);
		if (img2.empty())
		{
			MessageBox(_T("提示：不能打开图像文件2，退出！"));
			return;
		}
		imgs.push_back(img2);
	}
	if ( 0 != m_strPic1.GetLength() )
	{
		// 第1张
		memset(imagename, 0, MAX_PATH);
		WideCharToMultiByte(CP_ACP, 0, m_strPic1.GetBuffer(), -1, imagename, MAX_PATH, NULL, NULL);
		Mat img1 = imread(imagename, CV_LOAD_IMAGE_UNCHANGED);
		if (img1.empty())
		{
			MessageBox(_T("提示：不能打开图像文件1，退出！"));
			return;
		}
		imgs.push_back(img1);
	}
	
	Mat combineTemp;
	if ( BST_CHECKED == ((CButton*)GetDlgItem(IDC_RIO_H))->GetCheck() )
	{
		for (int numbers = imgs.size(); numbers > 1; numbers=imgs.size())
		{
			hconcat(imgs[numbers - 1], imgs[numbers-2], combineTemp);
			imgs.pop_back();
			imgs.pop_back();
			imgs.push_back(combineTemp);
		}
	}
	else
	{
		for (int numbers = imgs.size(); numbers > 1; numbers = imgs.size())
		{
			vconcat(imgs[numbers - 1], imgs[numbers - 2], combineTemp);
			imgs.pop_back();
			imgs.pop_back();
			imgs.push_back(combineTemp);
		}
	}

	CString str = m_strFileFolder;
	str += _T("\\");
	str += m_strFileTitle;
	str += _T("_compostion.");
	str += m_strFileExt;
	char szFileName[MAX_PATH] = { 0 };
	WideCharToMultiByte(CP_ACP, 0, str.GetBuffer(), -1, szFileName, MAX_PATH, NULL, NULL);
	
	if (!imwrite(szFileName, imgs[imgs.size() - 1])){
		MessageBox(_T("合成文件失败！"));
	}else{
		MessageBox(_T("合成文件成功！"));
	}
	return;
}
