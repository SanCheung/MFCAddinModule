// HTDialogBase.cpp : 实现文件
//

#include "stdafx.h"
#include "THAddIn.h"
#include "HTDialogBase.h"
#include "afxdialogex.h"


void HTDialogBase::work()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	HTDialogBase		dlg;
	dlg.DoModal();
}


// HTDialogBase 对话框

IMPLEMENT_DYNAMIC(HTDialogBase, CDialogEx)

HTDialogBase::HTDialogBase( CWnd* pParent /*=NULL*/)
	: CDialogEx(HTDialogBase::IDD, pParent)
{
	m_crBackColor = GetSysColor( COLOR_BTNFACE );
}

HTDialogBase::HTDialogBase( UINT nIDTemplate, CWnd* pParent )
	: CDialogEx(nIDTemplate, pParent)
{

	m_crBackColor = GetSysColor( COLOR_BTNFACE );
}

HTDialogBase::~HTDialogBase()
{
}

void HTDialogBase::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(HTDialogBase, CDialogEx)
END_MESSAGE_MAP()




// HTDialogBase 消息处理程序


BOOL HTDialogBase::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetBackgroundColor( m_crBackColor );

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
