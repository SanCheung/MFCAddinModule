// UISplineSectionEdit.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "THUIPane.h"
#include "UISplineSectionEdit.h"
#include "afxdialogex.h"


// UISplineSectionEdit �Ի���

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


// UISplineSectionEdit ��Ϣ�������
