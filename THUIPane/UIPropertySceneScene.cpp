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
	AddDialog< UIScene1Shader >( _T("ȫ����Ⱦ"), m_hWnd );
	AddDialog< UIScene2Light >( _T("��Դ"), m_hWnd );
	AddDialog< UIScene3Script >( _T("�ű�"), m_hWnd );
	AddDialog< UIScene4Simulation >( _T("ģ��ֽ��"), m_hWnd );
	AddDialog< UIScene5Section >( _T("���͹���"), m_hWnd );
}