// UISplineBoundary.cpp : 实现文件
//

#include "stdafx.h"
#include "THUIPane.h"
#include "UISplineBoundary.h"
#include "afxdialogex.h"


// UISplineBoundary 对话框

IMPLEMENT_DYNAMIC(UISplineBoundary, THSDialog)

UISplineBoundary::UISplineBoundary(CWnd* pParent /*=NULL*/)
	: THSDialog(UISplineBoundary::IDD, FALSE)
{

}

UISplineBoundary::~UISplineBoundary()
{
}

void UISplineBoundary::DoDataExchange(CDataExchange* pDX)
{
	THSDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(UISplineBoundary, THSDialog)
END_MESSAGE_MAP()

void UISplineBoundary::TH_InitData()
{

}


// UISplineBoundary 消息处理程序
