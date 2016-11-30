// UISplineSectionEdit.cpp : 实现文件
//

#include "stdafx.h"
#include "THUIPane.h"
#include "UISplineSectionEdit.h"
#include "afxdialogex.h"


// UISplineSectionEdit 对话框

IMPLEMENT_DYNAMIC(UISplineSectionEdit, THSDialog)

UISplineSectionEdit::UISplineSectionEdit(CWnd* pParent /*=NULL*/)
	: THSDialog(UISplineSectionEdit::IDD, FALSE)
{

}

UISplineSectionEdit::~UISplineSectionEdit()
{
}

void UISplineSectionEdit::DoDataExchange(CDataExchange* pDX)
{
	THSDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(UISplineSectionEdit, THSDialog)
END_MESSAGE_MAP()

void UISplineSectionEdit::TH_InitData()
{

}


// UISplineSectionEdit 消息处理程序
