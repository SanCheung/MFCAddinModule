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
	AddDialog< UISplineBoundary >( _T("ֽ������"), m_hWnd );
	AddDialog< UISplineType >( _T("�ı���������"), m_hWnd );
	AddDialog< UISplineSectionEdit >( _T("��������ͱ༭"), m_hWnd );
}
