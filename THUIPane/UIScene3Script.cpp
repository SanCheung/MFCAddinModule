// UIScenePage3.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "THUIPane.h"
#include "UIScene3Script.h"
#include "afxdialogex.h"


// UIScenePage3 �Ի���

IMPLEMENT_DYNAMIC(UIScene3Script, THSDialog)

UIScene3Script::UIScene3Script(CWnd* pParent /*=NULL*/)
	: THSDialog(UIScene3Script::IDD, FALSE)
{

}

UIScene3Script::~UIScene3Script()
{
}

void UIScene3Script::DoDataExchange(CDataExchange* pDX)
{
	THSDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(UIScene3Script, THSDialog)
END_MESSAGE_MAP()


void UIScene3Script::TH_InitData()
{

}


// UIScenePage3 ��Ϣ�������


BOOL UIScene3Script::OnInitDialog()
{
	THSDialog::OnInitDialog();


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
