
// MFCPictureDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCPicture.h"
#include "MFCPictureDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMFCPictureDlg �Ի���



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


// CMFCPictureDlg ��Ϣ�������

BOOL CMFCPictureDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	((CButton*)GetDlgItem(IDC_RIO_H))->SetCheck(BST_CHECKED);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCPictureDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCPictureDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCPictureDlg::OnBnClickedBtnChoose1()
{
	CFileDialog file(TRUE, NULL, NULL, 4 | 2, _T("����(*.*)|*.*||"), NULL, 0, TRUE);
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
	CFileDialog file(TRUE, NULL, NULL, 4 | 2, _T("����(*.*)|*.*||"), NULL, 0, TRUE);
	if (IDOK == file.DoModal())
	{
		m_strPic2 = file.GetPathName();
		UpdateData(FALSE);
	}
}


void CMFCPictureDlg::OnBnClickedBtnChoose3()
{
	CFileDialog file(TRUE, NULL, NULL, 4 | 2, _T("����(*.*)|*.*||"), NULL, 0, TRUE);
	if (IDOK == file.DoModal())
	{
		m_strPic3 = file.GetPathName();
		UpdateData(FALSE);
	}
}


void CMFCPictureDlg::OnBnClickedBtnChoose4()
{
	CFileDialog file(TRUE, NULL, NULL, 4 | 2, _T("����(*.*)|*.*||"), NULL, 0, TRUE);
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
	// lplImage����ͼ��
	char imagename[MAX_PATH];
	if (0 != m_strPic4.GetLength())
	{
		// ��4��
		memset(imagename, 0, MAX_PATH);
		WideCharToMultiByte(CP_ACP, 0, m_strPic4.GetBuffer(), -1, imagename, MAX_PATH, NULL, NULL);
		Mat img4 = imread(imagename, CV_LOAD_IMAGE_UNCHANGED);
		if (img4.empty())
		{
			MessageBox(_T("��ʾ�����ܴ�ͼ���ļ�4���˳���"));
			return;
		}
		imgs.push_back(img4);
	}
	if (0 != m_strPic3.GetLength())
	{
		// ��3��
		memset(imagename, 0, MAX_PATH);
		WideCharToMultiByte(CP_ACP, 0, m_strPic3.GetBuffer(), -1, imagename, MAX_PATH, NULL, NULL);
		Mat img3 = imread(imagename, CV_LOAD_IMAGE_UNCHANGED);
		if (img3.empty())
		{
			MessageBox(_T("��ʾ�����ܴ�ͼ���ļ�3���˳���"));
			return;
		}
		imgs.push_back(img3);
	}
	if (0 != m_strPic2.GetLength())
	{
		// ��2��
		memset(imagename, 0, MAX_PATH);
		WideCharToMultiByte(CP_ACP, 0, m_strPic2.GetBuffer(), -1, imagename, MAX_PATH, NULL, NULL);
		Mat img2 = imread(imagename, CV_LOAD_IMAGE_UNCHANGED);
		if (img2.empty())
		{
			MessageBox(_T("��ʾ�����ܴ�ͼ���ļ�2���˳���"));
			return;
		}
		imgs.push_back(img2);
	}
	if ( 0 != m_strPic1.GetLength() )
	{
		// ��1��
		memset(imagename, 0, MAX_PATH);
		WideCharToMultiByte(CP_ACP, 0, m_strPic1.GetBuffer(), -1, imagename, MAX_PATH, NULL, NULL);
		Mat img1 = imread(imagename, CV_LOAD_IMAGE_UNCHANGED);
		if (img1.empty())
		{
			MessageBox(_T("��ʾ�����ܴ�ͼ���ļ�1���˳���"));
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
		MessageBox(_T("�ϳ��ļ�ʧ�ܣ�"));
	}else{
		MessageBox(_T("�ϳ��ļ��ɹ���"));
	}
	return;
}
