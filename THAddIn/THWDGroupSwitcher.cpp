#include "StdAfx.h"
#include "THWDGroupSwitcher.h"
#include "THWndDialogsGroup.h"
#include "THSDialog.h"

namespace THUI
{


THWDGroupSwitcher::THWDGroupSwitcher(void)
	: m_pWndHost( NULL )
	, m_nCurSel( -1 )
{
}


THWDGroupSwitcher::~THWDGroupSwitcher(void)
{
	//int n = (int)m_arGroup.size();
	//for( int i = 0; i < n; i++ )
	//{
	//	THWndDialogsGroup *pGroup = m_arGroup[i];
	//	DEL( pGroup );
	//}

	m_arGroup.clear();
}

bool THWDGroupSwitcher::AddGroup( const CRect &rt, CWnd *pWndParent, UINT id, THWndDialogsGroup *pGroup )
{	
	pGroup->SetGS( this );

	m_pWndHost = pWndParent;
	pGroup->WndCreate( rt, pWndParent, id );
	m_arGroup.push_back( pGroup );
	return true;
}

void THWDGroupSwitcher::DoSize()
{
	CRect	rt;
	m_pWndHost->GetClientRect( rt );

	int n = (int)m_arGroup.size();
	for( int i = 0; i < n; i++ )
	{
		THWndDialogsGroup *pGroup = m_arGroup[i];
		pGroup->MoveWindow( rt );
	}
}

void THWDGroupSwitcher::SwitchTo( int nIndex )
{
	if( m_nCurSel == nIndex )
		return;

	int n = (int)m_arGroup.size();
	for( int i = 0; i < n; i++ )
	{
		THWndDialogsGroup *pGroup = m_arGroup[i];

		if( i==nIndex )
		{
			pGroup->ShowWindow( SW_SHOW );
			m_pWndHost->SetWindowText( pGroup->m_strName );
			pGroup->OnSwitch();

			m_nCurSel = nIndex;
		}
		else
			pGroup->ShowWindow( SW_HIDE );
	}
}

THWndDialogsGroup* THWDGroupSwitcher::GetGroup( int nIndex )
{
	if( nIndex < 0 || nIndex >= (int)m_arGroup.size() )
		return NULL;

	return m_arGroup[nIndex];
}

THSDialog* THWDGroupSwitcher::GetDialog( int nIndex, int nSubIndex )
{
	THWndDialogsGroup *pGroup = GetGroup( nIndex );
	if( NULL == pGroup )
		return NULL;

	if( nSubIndex < 0 || nSubIndex >= (int)pGroup->m_arDlgs.size() )
		return NULL;

	return pGroup->m_arDlgs[nSubIndex];
}


};
