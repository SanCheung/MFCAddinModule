#include "StdAfx.h"
#include "UIPropertySceneSpline.h"
#include "Resource.h"
#include "UISplineBoundary.h"
#include "UISplineType.h"
#include "UISplineSectionEdit.h"

UIPropertySceneSpline::UIPropertySceneSpline( CString strTitle )
	: THWndDialogsGroup( strTitle )
{
}


UIPropertySceneSpline::~UIPropertySceneSpline(void)
{
}

void UIPropertySceneSpline::InitSubDialogs()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	AddDialog< UISplineBoundary >( _T("纸样边线"), m_hWnd );
	AddDialog< UISplineType >( _T("改变线条类型"), m_hWnd );
	AddDialog< UISplineSectionEdit >( _T("横截面造型编辑"), m_hWnd );
}
