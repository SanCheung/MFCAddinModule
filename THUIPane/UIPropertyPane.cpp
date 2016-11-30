// UIPropertyPane.cpp : 实现文件
//

#include "stdafx.h"
#include "THUIPane.h"
#include "UIPropertyPane.h"
#include "UIPropertySceneScene.h"
#include "UIPropertySceneMesh.h"
#include "UIPropertySceneSpline.h"

#include "UIScene1Shader.h"

// UIPropertyPane

IMPLEMENT_DYNAMIC(UIPropertyPane, CDockablePane)

UIPropertyPane::UIPropertyPane()
// : m_pPE( NULL )
: m_nMeshId( -1 )
{

}

UIPropertyPane::~UIPropertyPane()
{
}


BEGIN_MESSAGE_MAP(UIPropertyPane, CDockablePane)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_CREATE()
END_MESSAGE_MAP()



// UIPropertyPane 消息处理程序




void UIPropertyPane::OnPaint()
{
	CPaintDC dc(this); // device context for painting


	CRect	rt;
	GetClientRect( &rt );
	dc.FillRect( &rt, &CBrush(RGB(255,255,255)));

	dc.LineTo( rt.right, rt.bottom );
}

BOOL UIPropertyPane::dllCreate( LPCTSTR lpszCaption, HWND hWnd, const RECT& rect, BOOL bHasGripper, UINT nID, DWORD dwStyle )
{
	// 没有资源不需要切换
	//AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// 无法直接传递CWnd
	CWnd		*pParentWnd = CWnd::FromHandle( hWnd );
	// DWORD dwTabbedStyle = AFX_CBRS_REGULAR_TABS, DWORD dwControlBarStyle = AFX_DEFAULT_DOCKING_PANE_STYLE, CCreateContext* pContext = NULL
	CDockablePane::CreateEx(0, lpszCaption, pParentWnd, rect, bHasGripper, nID, dwStyle, AFX_CBRS_REGULAR_TABS, AFX_DEFAULT_DOCKING_PANE_STYLE, NULL);

	THUI::THWndDialogsGroup	*pGroup = GetGroup( 0 );
	if( pGroup != NULL )
		SetWindowText( pGroup->m_strName );

	return TRUE;
}

void UIPropertyPane::OnSize(UINT nType, int cx, int cy)
{
	__super::OnSize(nType, cx, cy);

	DoSize();
	Invalidate();
}

int UIPropertyPane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	//lpCreateStruct->style |= WS_VSCROLL;

	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	CRect	rt;
	GetClientRect( &rt );
	rt.DeflateRect( 10, 10 );

	AddGroup( rt, this, 1, new UIPropertySceneScene( "场景设置" ) );
	AddGroup( rt, this, 2, new UIPropertySceneMesh( "纸样设置" ) );
	AddGroup( rt, this, 3, new UIPropertySceneSpline( "纸样边线设置" ) );

	return 0;
}

//void UIPropertyPane::RegisterPropertyExchange( IUIDataExchange *pPE )
//{
//	m_pPE = pPE;
//}

void UIPropertyPane::OnSelectScence()
{
	SwitchTo( 0 );
}

void UIPropertyPane::OnSelectMesh( int nMeshId )
{
	m_nMeshId = nMeshId;
	SwitchTo( 1 );
}

void UIPropertyPane::OnSelectSpline()
{
	SwitchTo( 2 );
}

bool UIPropertyPane::Run( const std::string &str, JC::JCmdBase &value )
{
	string		strFrom;
	value.GetValue( "from", strFrom );
	if( strFrom.compare("ui") == 0 )
		return false;

	if( str.find( "shader_" ) != std::string::npos )
		return RunShader( str, value );
	
	if( str.find( "light_" ) != std::string::npos )
		return RunLight( str, value );

	return true;
}

bool UIPropertyPane::RunShader( const std::string &str, JC::JCmdBase &value )
{
	UIScene1Shader *pDlgShader1 = (UIScene1Shader *)GetDialog( 0, 0 );
	if( str.compare( "shader_enable_beingused" ) == 0 )
	{
		bool bEnable;
		if( !value.GetValue( "enable", bEnable ) )
			return false;

		pDlgShader1->UISetCtrlEnable( IDC_GRP22_CHECK2, bEnable );
	}
	else if( str.compare( "shader_enable_usingshader" ) == 0 )
	{
		bool bEnable;
		if( !value.GetValue( "enable", bEnable ) )
			return false;
		
		pDlgShader1->UISetCtrlEnable( IDC_GRP22_CHECK3, bEnable );
	}
	else if( str.compare( "shader_enable_usingbodyglos" ) == 0 )
	{
		bool bEnable;
		if( !value.GetValue( "enable", bEnable ) )
			return false;
		
		pDlgShader1->UISetCtrlEnable( IDC_GRP22_CHECK, bEnable );
	}
	else if( str.compare( "shader_new" ) == 0 )
	{
		string str;
		if( !value.GetValue( "return_value", str ) )
			return false;

		pDlgShader1->UIAddProgram( str );
	}
	else if( str.compare( "shader_delete" ) == 0 )
	{
		int nIndex;
		if( !value.GetValue( "index", nIndex ) )
			return false;

		pDlgShader1->UIDelProgram( nIndex );
	}

	return true;
}

bool UIPropertyPane::RunLight( const std::string &str, JC::JCmdBase &value )
{
	if( "light_getitem" == str )
	{
	}
	return true;
}

