#include "StdAfx.h"
#include "UIPropertySceneMesh.h"
#include "UIMeshMaterial.h"
#include "UIMeshSimulation.h"
#include "UIMeshTexture.h"



UIPropertySceneMesh::UIPropertySceneMesh( CString strTitle )
	: THWndDialogsGroup( strTitle )
{
}


UIPropertySceneMesh::~UIPropertySceneMesh(void)
{
}

void UIPropertySceneMesh::InitSubDialogs()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	AddDialog< UIMeshTexture >( _T("��������"), m_hWnd );
	AddDialog< UIMeshMaterial >( _T("��������"), m_hWnd );
	AddDialog< UIMeshSimulation >( _T("ֽ��ģ��"),m_hWnd);
}
