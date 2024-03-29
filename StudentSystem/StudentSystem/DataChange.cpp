// DataChange.cpp: 实现文件
//

#include "stdafx.h"
#include "StudentSystem.h"
#include "DataChange.h"
#include "afxdialogex.h"


// DataChange 对话框

IMPLEMENT_DYNAMIC(DataChange, CDialogEx)

DataChange::DataChange(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHANGE, pParent)
	, name(_T(""))
	, num(_T(""))
	, age(_T(""))
{
	//sex_index.SetCurSel(0);
}

DataChange::~DataChange()
{
}

void DataChange::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, name);
	DDX_Text(pDX, IDC_EDIT2, num);
	DDX_Control(pDX, IDC_COMBO1, sex_index);
	DDX_Text(pDX, IDC_EDIT4, age);
}


BEGIN_MESSAGE_MAP(DataChange, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DataChange::OnBnClickedButton1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &DataChange::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDCANCEL2, &DataChange::OnBnClickedCancel2)
END_MESSAGE_MAP()


// DataChange 消息处理程序


void DataChange::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	//更新数据，拿到最新的数据

	if (name.IsEmpty())
	{
		MessageBox(TEXT("输入的学生姓名不能为空"));
		return;
	}
	else if (num.IsEmpty())
	{
		MessageBox(TEXT("输入的学生学号不能为空"));
		return;
	}
	else if (age.IsEmpty())
	{
		MessageBox(TEXT("输入的学生年龄不能为空"));
		return;
	}
	else if (sex != "男" && sex != "女")
	{
		MessageBox(TEXT("请正确选择性别"));
	}
	else
	{
		OnOK();
		change = true;
	}
}


void DataChange::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	int index = sex_index.GetCurSel();

	//CString sex;
	sex_index.GetLBText(index, sex);
}


void DataChange::OnBnClickedCancel2()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


BOOL DataChange::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	if (sex == "男")
		sex_index.SetCurSel(0);
	else
		sex_index.SetCurSel(1);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
