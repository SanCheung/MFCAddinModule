#include "StdAfx.h"
#include "Resource.h"
#include "UIPropertySceneScene.h"
#include "UIScene1Shader.h"
#include "UIScene2Light.h"
#include "UIScene3Script.h"
#include "UIScene4Simulation.h"
#include "UIScene5Section.h"


UIPropertySceneScene::UIPropertySceneScene( CString strTitle )
	: THWndDialogsGroup( strTitle )
{
}


UIPropertySceneScene::~UIPropertySceneScene(void)
{
}

void UIPropertySceneScene::InitSubDialogs()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	AddDialog< UIScene1Shader >( _T("全局渲染"), m_hWnd );
	AddDialog< UIScene2Light >( _T("光源"), m_hWnd );
	AddDialog< UIScene3Script >( _T("脚本"), m_hWnd );
	AddDialog< UIScene4Simulation >( _T("模拟纸样"), m_hWnd );
	AddDialog< UIScene5Section >( _T("造型管理"), m_hWnd );
}