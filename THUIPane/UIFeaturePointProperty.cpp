// UIFeaturePointProperty.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "THUIPane.h"
#include "UIFeaturePointProperty.h"
#include "afxdialogex.h"


// UIFeaturePointProperty �Ի���

IMPLEMENT_DYNAMIC(UIFeaturePointProperty, THSDialog)

UIFeaturePointProperty::UIFeaturePointProperty(CWnd* pParent /*=NULL*/)
	: THSDialog(UIFeaturePointProperty::IDD, FALSE)
{

}

UIFeaturePointProperty::~UIFeaturePointProperty()
{
}

void UIFeaturePointProperty::DoDataExchange(CDataExchange* pDX)
{
	THSDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(UIFeaturePointProperty, THSDialog)
END_MESSAGE_MAP()

void UIFeaturePointProperty::TH_InitData()
{

}


// UIFeaturePointProperty ��Ϣ�������
