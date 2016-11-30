// UIScenePage1.cpp : 实现文件
//

#include "stdafx.h"
#include "THUIPane.h"
#include "UIScene1Shader.h"
#include "afxdialogex.h"

#include "UIPropertyPane.h"
#include "IUIDataExchange.h"

#include "JsonCommand.h"

#define		FRAGMENT_ID		1
#define		VERTEX_ID		2


// UIScenePage1 对话框

IMPLEMENT_DYNAMIC(UIScene1Shader, THSDialog )

UIScene1Shader::UIScene1Shader(CWnd* pParent /*=NULL*/)
	: THSDialog( UIScene1Shader::IDD, FALSE )
{

}

UIScene1Shader::~UIScene1Shader()
{
}

void UIScene1Shader::DoDataExchange(CDataExchange* pDX)
{
	THSDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_GRP22_LIST, m_ctlLB);
	DDX_Control(pDX, IDC_GRP22_GRID, m_ctlPG);
	DDX_Control(pDX, IDC_GRP22_COM, m_ctlCB);
	DDX_Control(pDX, IDC_GRP22_CHECK, m_ctlBnCheck);
}

BEGIN_MESSAGE_MAP(UIScene1Shader, THSDialog)
	ON_REGISTERED_MESSAGE(AFX_WM_PROPERTY_CHANGED, OnPropertyChanged)
	ON_LBN_SELCHANGE(IDC_GRP22_LIST, &UIScene1Shader::OnSelchangeList)
	ON_BN_CLICKED(IDC_GRP22_CHECK2, &UIScene1Shader::OnBnClickedGrp22Check2)
	ON_BN_CLICKED(IDC_GRP22_CHECK3, &UIScene1Shader::OnBnClickedGrp22Check3)
	ON_BN_CLICKED(IDC_GRP22_CHECK, &UIScene1Shader::OnBnClickedGrp22Check)
	ON_BN_CLICKED(IDC_GRP22_BTN5, &UIScene1Shader::OnBnClickedGrp22Btn5)
	ON_BN_CLICKED(IDC_GRP22_BTN6, &UIScene1Shader::OnBnClickedGrp22Btn6)
	ON_BN_CLICKED(IDC_GRP22_BTN7, &UIScene1Shader::OnBnClickedGrp22Btn7)
END_MESSAGE_MAP()


// UIScenePage1 消息处理程序
BOOL UIScene1Shader::OnInitDialog()
{
	THSDialog::OnInitDialog();

	CMFCHeaderCtrl	&ctlHeader = m_ctlPG.GetHeaderCtrl();

	HDITEM			hi = {0};
	hi.mask = HDI_WIDTH;

	CRect			rt;
	ctlHeader.GetClientRect( &rt );

	hi.cxy = 60;
	ctlHeader.SetItem( 0, &hi );

	hi.cxy = rt.Width() - hi.cxy;
	ctlHeader.SetItem( 1, &hi );

	CMFCPropertyGridProperty* pGroup = NULL;
	pGroup = new CMFCPropertyGridProperty("片段渲染器 FragmentShader");
	{
		pGroup->AddSubItem( new CMFCPropertyGridFileProperty(_T("路径"), TRUE, "", _T("frag"), 0, 
			_T("FragmentShader脚本文件(*.frag)|*.frag|所有文件(*.*)|*.*||"), _T("指定FragmentShader脚本文件"), FRAGMENT_ID ) );
	}
	m_ctlPG.AddProperty(pGroup);

	pGroup = new CMFCPropertyGridProperty("顶点渲染器 VertexShader");
	{
		pGroup->AddSubItem( new CMFCPropertyGridFileProperty(_T("路径"), TRUE, "", _T("vert"), 0, 
			_T("VertexShader脚本文件(*.vert)|*.vert|所有文件(*.*)|*.*||"), _T("指定VertexShader脚本文件"), VERTEX_ID ) );
	}
	m_ctlPG.AddProperty(pGroup);

	//SetBackgroundColor( RGB(218,218,240) );

	((CButton *)GetDlgItem(IDC_GRP22_CHECK2))->SetCheck( 1 );
	((CButton *)GetDlgItem(IDC_GRP22_CHECK3))->SetCheck( 1 );

	return TRUE;
}

LRESULT UIScene1Shader::OnPropertyChanged (WPARAM wParam ,LPARAM lParam)
{
	int		nIndex = m_ctlLB.GetCurSel();
	if( nIndex < 0 )
		return 0;

	CMFCPropertyGridProperty *pPro = (CMFCPropertyGridProperty*)lParam;
	if( NULL == pPro )
		return 0;

	int		nDataId;
	nDataId = (int)pPro->GetData();

	//CString strName, strValue, strOldValue;
	//strName		= pPro->GetName();
	//strValue	= pPro->GetValue();
	//strOldValue	= pPro->GetOriginalValue();

	//IUIDataExchange	 *pPE = GetDataExchange();
	//if( pPE != NULL )
	//	pPE->Shader_setItem( nIndex, nDataId, strName, strValue );

	if( FRAGMENT_ID == nDataId )
		m_strFragmentPath	= pPro->GetValue();
	else if( VERTEX_ID == nDataId )
		m_strVertexPath		= pPro->GetValue();
	else
		return 0;

	JC::JsonCommand jc;
	jc.SetFunctoin( "shader_setitem" );
	jc.AddParam( "from", "ui" );
	jc.AddParam( "index", nIndex );
	jc.AddParam( "fragment", m_strFragmentPath );
	jc.AddParam( "vertax", m_strVertexPath );
	jc.Notify();

	return 0;
}


void UIScene1Shader::OnSelchangeList()
{
	int i = m_ctlLB.GetCurSel();
	
	//IUIDataExchange *p = GetDataExchange();

	//CString	str1, str2;
	//p->Shader_getItem( i, str1, str2 );

	JC::JsonCommand jc;
	jc.SetFunctoin( "shader_getitem" );
	jc.AddParam( "index", i );
	jc.AddParam( "from", "ui" );
	jc.Notify();

	string strFragment, strVertax;
	jc.GetValue( "fragment", strFragment );
	jc.GetValue( "vertax", strVertax );

	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_ctlPG.FindItemByData(1)->SetValue( strFragment.c_str() );
	m_ctlPG.FindItemByData(2)->SetValue( strVertax.c_str() );

	m_strFragmentPath = strFragment.c_str();
	m_strVertexPath = strVertax.c_str();
	
}

//IUIDataExchange * UIScene1Shader::GetDataExchange()
//{
//	if( NULL == m_pOwner )
//		return NULL;
//
//	UIPropertyPane	*pPane = (UIPropertyPane *)m_pOwner;
//	return pPane->GetDataExchange();
//}

void UIScene1Shader::TH_InitData()
{
	//IUIDataExchange		*pe = GetDataExchange();
	//if( NULL == pe )
	//	return;

	////pe->ShaderDataToUI( m_ctlLB, m_ctlBnCheck );
	//vector< CString >	as;
	//bool				bValue;
	//int n = pe->Shader_getInitData( as, bValue );
	//for( int i = 0; i < n; i++ )
	//	m_ctlLB.AddString( as[i] );

	//m_ctlLB.SetCurSel( 0 );
	//m_ctlBnCheck.SetCheck( bValue );
	//OnSelchangeList();

	m_ctlLB.ResetContent();

	JC::JsonCommand jc;
	jc.SetFunctoin( "shader_getdata" );
	jc.AddParam( "from", "ui" );
	jc.Notify();

	vector< string >	as;
	jc.GetValue( "programelist", as );

	int n = (int)as.size();
	for( int i = 0; i < n; i++ )
		m_ctlLB.AddString( as[i].c_str() );

	m_ctlLB.SetCurSel( 0 );
	OnSelchangeList();
	
	bool	bValue;
	jc.GetValue( "usingbodyglos", bValue );
	m_ctlBnCheck.SetCheck( bValue );
}

// 全部使用高级渲染模式
void UIScene1Shader::OnBnClickedGrp22Check2()
{
	CButton	*pButton = (CButton*)GetDlgItem( IDC_GRP22_CHECK2 );
	BOOL	bCheck = pButton->GetCheck();

	//IUIDataExchange		*pe = GetDataExchange();
	//pe->ShaderEnable_beingused( 1 == bCheck );

	JC::JsonCommand jc;
	jc.SetFunctoin( "shader_enable_beingused" );
	jc.AddParam( "from", "ui" );
	jc.AddParam( "enable", bCheck==1 );
	jc.Notify();
}

// 全部使用Shader
void UIScene1Shader::OnBnClickedGrp22Check3()
{
	CButton	*pButton = (CButton*)GetDlgItem( IDC_GRP22_CHECK3 );
	BOOL	bCheck = pButton->GetCheck();

	//IUIDataExchange		*pe = GetDataExchange();
	//pe->ShaderEnable_usingshader( 1 == bCheck );
	JC::JsonCommand jc;
	jc.SetFunctoin( "shader_enable_usingshader" );
	jc.AddParam( "from", "ui" );
	jc.AddParam( "enable", bCheck==1 );
	jc.Notify();
}

// 高级渲染人体
void UIScene1Shader::OnBnClickedGrp22Check()
{
	CButton	*pButton = (CButton*)GetDlgItem( IDC_GRP22_CHECK );
	BOOL	bCheck = pButton->GetCheck();

	//IUIDataExchange		*pe = GetDataExchange();
	//if( pe )
	//	pe->ShaderEnable_usingBodyGLOs( 1 == bCheck );

	JC::JsonCommand jc;
	jc.SetFunctoin( "shader_enable_usingbodyglos" );
	jc.AddParam( "from", "ui" );
	jc.AddParam( "enable", bCheck==1 );
	jc.Notify();
}

// 加载渲染器
void UIScene1Shader::OnBnClickedGrp22Btn5()
{
	//IUIDataExchange		*pe = GetDataExchange();
	//if( pe )
	//	pe->Shader_load();

	JC::JsonCommand jc;
	jc.SetFunctoin( "shader_load" );
	jc.AddParam( "from", "ui" );
	jc.Notify();
}

// 新建渲染器
void UIScene1Shader::OnBnClickedGrp22Btn6()
{
	//IUIDataExchange		*pe = GetDataExchange();
	//if( pe )
	//{
	//	CString str = pe->Shader_new();
	//	if( !str.IsEmpty() )
	//	{
	//		int nItem = m_ctlLB.AddString( str );
	//		m_ctlLB.SetCurSel( nItem );
	//	}
	//}
	JC::JsonCommand jc;
	jc.SetFunctoin( "shader_new" );
	jc.AddParam( "from", "ui" );
	jc.Notify();

	string str;
	if( jc.GetValue( "return_value", str ) )
	{
		//int nItem = m_ctlLB.AddString( str.c_str() );
		//m_ctlLB.SetCurSel( nItem );
		UIAddProgram( str );
	}

}

// 删除渲染器
void UIScene1Shader::OnBnClickedGrp22Btn7()
{
	int nIndex = m_ctlLB.GetCurSel();

	//IUIDataExchange		*pe = GetDataExchange();
	//if( pe )
	//	pe->Shader_delete( nIndex );

	JC::JsonCommand jc;
	jc.SetFunctoin( "shader_delete" );
	jc.AddParam( "index", nIndex );
	jc.AddParam( "from", "ui" );
	jc.Notify();

	UIDelProgram( nIndex );
}

void UIScene1Shader::UISetCtrlEnable( UINT uId, bool bEnable )
{
	CButton *pBtn = ((CButton *)GetDlgItem( uId ));
	if( NULL != pBtn && ::IsWindow( pBtn->m_hWnd ) )
		pBtn->SetCheck( bEnable );
}

void UIScene1Shader::UIAddProgram( string strProgram )
{
	int nItem = m_ctlLB.AddString( strProgram.c_str() );
	m_ctlLB.SetCurSel( nItem );
}

void UIScene1Shader::UIDelProgram( int nIndex )
{
	m_ctlLB.DeleteString( nIndex );

	int n = m_ctlLB.GetCount();
	if( n > 0 )
		m_ctlLB.SetCurSel( n-1 );
}
