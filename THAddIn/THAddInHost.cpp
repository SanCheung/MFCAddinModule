#include "StdAfx.h"
#include "THAddInHost.h"
#include "THAddInBase.h"


THAddInHost::THAddInHost(void)
{
}


THAddInHost::~THAddInHost(void)
{
	int n = (int)m_arModule.size();
	for( int i = 0; i < n; i++ )
	{
		HINSTANCE	hInst = m_arModule[i];
		FreeLibrary( hInst );
		hInst = NULL;
	}

	m_arModule.clear();
}

void THAddInHost::Init()
{
	CString		strPath;
	GetModuleFileName(NULL, strPath.GetBuffer(MAX_PATH+4), MAX_PATH );
	strPath.ReleaseBuffer(-1);

	int npos = strPath.ReverseFind( '\\' );
	if( -1 == npos )
		return;

	strPath.Delete( npos, strPath.GetLength() );

	CFileFind		ff;
	CString		strFilter = strPath + "\\*.dll";
	BOOL		bFound = ff.FindFile( strFilter, 0 );
	while( bFound )
	{
		bFound = ff.FindNextFile();

		CString		strFullName = ff.GetFilePath();
		HINSTANCE	hInst = LoadLibrary( strFullName );
		if( NULL == hInst )
			continue;

		m_arModule.push_back( hInst );
	}
}

void THAddInHost::RegisterAddIn( THAddInBase *p )
{
	m_aoAddInDlgs.push_back( p );
}

bool THAddInHost::CreateAddIn( CString strName, void *pParam )
{
	int n = (int)m_aoAddInDlgs.size();
	for( int i = 0; i < n; i++ )
	{
		THAddInBase	*pAddIn = m_aoAddInDlgs[i];
		if( pAddIn->m_strId == strName )
		{
			pAddIn->Create( pParam, 0 );
			return true;
		}
	}

	return false;
}
