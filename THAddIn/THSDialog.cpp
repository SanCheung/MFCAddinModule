#include "StdAfx.h"
#include "THSDialog.h"


namespace THUI
{


/////////////////////////////////////////////////////////////////////////////
// CHJAutoDialog dialog


THSDialog::THSDialog( UINT id, BOOL bModal )
	: CDialogEx( id, NULL)
	, m_bModal( bModal )
	, m_pOwner( NULL )
{
	//{{AFX_DATA_INIT(CHJAutoDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


BEGIN_MESSAGE_MAP(THSDialog, CDialogEx)
	//{{AFX_MSG_MAP(CHJAutoDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHJAutoDialog message handlers

void THSDialog::PreSubclassWindow() 
{
	if( !m_bModal )
	{
		ModifyStyle( WS_POPUP|WS_CAPTION|WS_DLGFRAME, WS_CHILD );
		ModifyStyleEx( WS_EX_DLGMODALFRAME, 0 );
	}
	
	CDialogEx::PreSubclassWindow();
}

void THSDialog::PostNcDestroy()
{
	if( !m_bModal )
		delete this;
}


void THSDialog::OnOK() 
{
	if( !m_bModal )
	{
		MessageBox( _T("子窗口里面OnOK，想死机啊。。") );
		return;
	}
	
	CDialogEx::OnOK();
}

void THSDialog::OnCancel() 
{
	if( !m_bModal )
	{
		MessageBox( _T("子窗口里面OnCancel，想死机啊。。") );
		return;
	}
	
	CDialogEx::OnOK();
}

BOOL THSDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	GetClientRect( m_rt );
	GetWindowText( m_strTitle );

	return TRUE;
}

void THSDialog::SetGS( THWDGroupSwitcher *p )
{
	m_pOwner = p;
	TH_InitData();
}

void THSDialog::TH_InitData()
{

}


};
