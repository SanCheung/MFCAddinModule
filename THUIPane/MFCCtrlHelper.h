#pragma once

// 通用MFC界面控件的助手
class CMFCCtrlHelper
{
public:
	CMFCCtrlHelper(void);
	virtual ~CMFCCtrlHelper(void);


public:
	static void ListCtrl_SelectItem( CListCtrl *pListCtrl, int nIndex );

	static CMFCPropertyGridProperty*		PropertyGridCtrl_NewOption( DWORD_PTR dwData, const CString& strName, const COleVariant& varValue, LPCTSTR lpszDescr = NULL );
	static CMFCPropertyGridProperty*		PropertyGridCtrl_NewOption2( DWORD_PTR dwData, const CString& strName, const COleVariant& varValue, const vector<CString> &asList, LPCTSTR lpszDescr = NULL );
	static CMFCPropertyGridColorProperty*	PropertyGridCtrl_NewColor( COLORREF crDefault, COLORREF crAutomatic, DWORD_PTR dwData, const CString& strName, LPCTSTR lpszDescr = NULL );

	static void	PropertyGridCtrl_SetPGPValue( CMFCPropertyGridCtrl *pCtrlPG, DWORD_PTR dwData, COleVariant val );
	static void	PropertyGridCtrl_SetPGPColor( CMFCPropertyGridCtrl *pCtrlPG, DWORD_PTR dwData, int val );


	static CString GetModulePath();
	static CString GetUpperPath( CString strPath );
};

