#include "StdAfx.h"
#include "THSDialog.h"
#include "THSDialogMgr.h"

namespace THUI
{

THSDialogMgr::THSDialogMgr(void)
{
}


THSDialogMgr::~THSDialogMgr(void)
{
	m_asName.clear();
	m_arDlgs.clear();
}

void THSDialogMgr::AddDialogIndirect( string str, THSDialog *p )
{
	m_asName.push_back( str );
	m_arDlgs.push_back( p );
}

int THSDialogMgr::GetCount()
{
	return (int)m_asName.size();
}

THSDialog * THSDialogMgr::GetSubDialog( string str )
{
	int n = (int)m_asName.size();
	for( int i = 0; i < n; i++ )
	{
		string	strName = m_asName[i];
		if( strName == str )
			return m_arDlgs[i];
	}

	return NULL;
}

};