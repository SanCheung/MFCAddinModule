// UISplineBoundary.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "THUIPane.h"
#include "UISplineBoundary.h"
#include "afxdialogex.h"


// UISplineBoundary �Ի���

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


// UISplineBoundary ��Ϣ�������
