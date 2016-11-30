// UISplineType.cpp : 实现文件
//

#include "stdafx.h"
#include "THUIPane.h"
#include "UISplineType.h"
#include "afxdialogex.h"


// UISplineType 对话框

IMPLEMENT_DYNAMIC(UISplineType, THSDialog)

UISplineType::UISplineType(CWnd* pParent /*=NULL*/)
	: THSDialog(UISplineType::IDD, FALSE)
{

}

UISplineType::~UISplineType()
{
}

void UISplineType::DoDataExchange(CDataExchange* pDX)
{
	THSDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(UISplineType, THSDialog)
END_MESSAGE_MAP()

void UISplineType::TH_InitData()
{

}


// UISplineType 消息处理程序
