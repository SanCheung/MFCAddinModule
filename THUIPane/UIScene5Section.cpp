// UIScenePage5.cpp : 实现文件
//

#include "stdafx.h"
#include "THUIPane.h"
#include "UIScene5Section.h"
#include "afxdialogex.h"
#include "JsonCommand.h"


// UIScenePage5 对话框

IMPLEMENT_DYNAMIC(UIScene5Section, THSDialog)

UIScene5Section::UIScene5Section(CWnd* pParent /*=NULL*/)
	: THSDialog(UIScene5Section::IDD, FALSE)
{

}

UIScene5Section::~UIScene5Section()
{
}

void UIScene5Section::DoDataExchange(CDataExchange* pDX)
{
	THSDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(UIScene5Section, THSDialog)
	ON_BN_CLICKED(IDC_GRP26_BTN2, &UIScene5Section::OnBnClickedGrp26Btn2)
END_MESSAGE_MAP()

void UIScene5Section::TH_InitData()
{

}


// UIScenePage5 消息处理程序
void UIScene5Section::OnBnClickedGrp26Btn2()
{
	JC::JsonCommand jc;
	jc.SetFunctoin( "section_manager" );
	jc.AddParam( "from", "ui" );
	jc.Notify();
}
