#include "StdAfx.h"
#include "MFCCtrlHelper.h"


CMFCCtrlHelper::CMFCCtrlHelper(void)
{
}


CMFCCtrlHelper::~CMFCCtrlHelper(void)
{
}

void CMFCCtrlHelper::ListCtrl_SelectItem( CListCtrl *pListCtrl, int nIndex )
{
	if( NULL == pListCtrl || !::IsWindow( pListCtrl->m_hWnd ) )
		return;

	pListCtrl->SetItemState( nIndex, LVIS_FOCUSED | LVIS_SELECTED,LVIS_FOCUSED | LVIS_SELECTED );
	pListCtrl->SetSelectionMark( nIndex  );
}

CMFCPropertyGridProperty* CMFCCtrlHelper::PropertyGridCtrl_NewOption( DWORD_PTR dwData, const CString& strName, const COleVariant& varValue, LPCTSTR lpszDescr /*= NULL */ )
{
	CMFCPropertyGridProperty *pItem = new CMFCPropertyGridProperty( strName, varValue, lpszDescr, dwData );
	pItem->AddOption( _T("是") );
	pItem->AddOption( _T("否") );
	pItem->AllowEdit( FALSE );

	return pItem;
}


CMFCPropertyGridProperty* CMFCCtrlHelper::PropertyGridCtrl_NewOption2( DWORD_PTR dwData, const CString& strName, const COleVariant& varValue, const vector<CString> &asList, LPCTSTR lpszDescr /*= NULL */ )
{
	CMFCPropertyGridProperty *pItem = new CMFCPropertyGridProperty( strName, varValue, lpszDescr, dwData );
	pItem->AllowEdit( FALSE );

	int n = (int)asList.size();
	for( int i = 0; i < n; i++ )
	{
		CString		str = asList[i];
		pItem->AddOption( str );
	}

	return pItem;
}


CMFCPropertyGridColorProperty* CMFCCtrlHelper::PropertyGridCtrl_NewColor( COLORREF crDefault, COLORREF crAutomatic, DWORD_PTR dwData, const CString& strName, LPCTSTR lpszDescr /*= NULL */ )
{
	CMFCPropertyGridColorProperty *pItem = new  CMFCPropertyGridColorProperty( strName, crDefault, NULL, lpszDescr, dwData );
	pItem->EnableOtherButton( _T("其他...") );
	pItem->EnableAutomaticButton(_T("默认"), crAutomatic );

	return pItem;
}

void CMFCCtrlHelper::PropertyGridCtrl_SetPGPValue( CMFCPropertyGridCtrl *pCtrlPG, DWORD_PTR dwData, COleVariant val )
{
	CMFCPropertyGridProperty* pPro = pCtrlPG->FindItemByData( dwData );
	if( NULL == pPro )
		return;

	pPro->SetValue( val );
}

void CMFCCtrlHelper::PropertyGridCtrl_SetPGPColor( CMFCPropertyGridCtrl *pCtrlPG, DWORD_PTR dwData, int val )
{
	CMFCPropertyGridColorProperty* pPro = (CMFCPropertyGridColorProperty *)pCtrlPG->FindItemByData( dwData );
	if( NULL == pPro )
		return;

	pPro->SetColor( val );
}

CString CMFCCtrlHelper::GetModulePath()
{
	CString		str;
	GetModuleFileName( NULL, str.GetBuffer(1024), 1024 );
	str.ReleaseBuffer();

	int npos = str.ReverseFind( '\\' );
	if( -1 == npos )
		return "";

	str.Delete( npos, str.GetLength() - npos );
	return str;
}

CString CMFCCtrlHelper::GetUpperPath( CString str )
{
	int npos = str.ReverseFind( '\\' );
	if( -1 == npos )
		return "";

	str.Delete( npos, str.GetLength() - npos );
	return str;
}


