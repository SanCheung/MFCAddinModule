// UIMeshSimulation.cpp : 实现文件
//

#include "stdafx.h"
#include "THUIPane.h"
#include "UIMeshSimulation.h"
#include "afxdialogex.h"

#include "JsonCommand.h"
#include "MFCCtrlHelper.h"


// UIMeshSimulation 对话框

IMPLEMENT_DYNAMIC(UIMeshSimulation, THSDialog)

UIMeshSimulation::UIMeshSimulation(CWnd* pParent /*=NULL*/)
	: THSDialog(UIMeshSimulation::IDD, FALSE)
{

}

UIMeshSimulation::~UIMeshSimulation()
{
}

void UIMeshSimulation::DoDataExchange(CDataExchange* pDX)
{
	THSDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_GRP14_COMBO, m_ctlCB);
	DDX_Control(pDX, IDC_GRP14_GRID, m_ctlPG);
}

BOOL UIMeshSimulation::OnInitDialog()
{
	THSDialog::OnInitDialog();

	// init PropertyGrid Header
	CMFCHeaderCtrl	&ctlHeader = m_ctlPG.GetHeaderCtrl();

	HDITEM			hi = {0};
	hi.mask = HDI_WIDTH|HDI_TEXT;

	CRect			rt;
	ctlHeader.GetClientRect( &rt );

	hi.cxy = 120;
	hi.pszText = _T("模拟属性");
	ctlHeader.SetItem( 0, &hi );

	hi.cxy = rt.Width() - hi.cxy;
	hi.pszText = _T("值");
	ctlHeader.SetItem( 1, &hi );

	m_ctlPG.AddProperty( new CMFCPropertyGridProperty( _T("时间步长"), (_variant_t)0.f, _T(""), 1 ) );
	m_ctlPG.AddProperty( new CMFCPropertyGridProperty( _T("布料弯曲强度"), (_variant_t)0.f, _T(""), 2 ) );
	m_ctlPG.AddProperty( new CMFCPropertyGridProperty( _T("布料拉伸强度"), (_variant_t)0.f, _T(""), 3 ) );
	m_ctlPG.AddProperty( new CMFCPropertyGridProperty( _T("布料密度"), (_variant_t)0.f, _T(""), 4 ) );
	m_ctlPG.AddProperty( new CMFCPropertyGridProperty( _T("缝合线弯曲强度"), (_variant_t)0.f, _T(""), 5 ) );
	m_ctlPG.AddProperty( new CMFCPropertyGridProperty( _T("阻尼系数"), (_variant_t)0.98f, _T(""), 6 ) );
	m_ctlPG.AddProperty( new CMFCPropertyGridProperty( _T("重力加速度"), (_variant_t)-9.8f, _T(""), 7 ) );

	vector< CString >		as;
	as.push_back( _T("Hinge-based") );
	as.push_back( _T("Quadratic") );
	as.push_back( _T("Cubic") );
	as.push_back( _T("Rigid") );
	m_ctlPG.AddProperty( CMFCCtrlHelper::PropertyGridCtrl_NewOption2( 8, _T("Bending Model"), (_variant_t)_T("Hinge-based"), as ) );

	return TRUE;
}


void UIMeshSimulation::TH_InitData()
{
	m_ctlCB.ResetContent();

	JC::JsonCommand jc;
	jc.SetFunctoin( "texture_simulation_getdata" );
	jc.AddParam( "from", "ui" );
	jc.Notify();

	vector< string >	as;
	if( jc.GetValue( "return_values", as ) )
	{
		int n = (int)as.size();
		for( int i = 0; i < n; i++ )
		{
			string		str = as[i];
			m_ctlCB.AddString( str.c_str() );
		}
	}
}


BEGIN_MESSAGE_MAP(UIMeshSimulation, THSDialog)
	ON_CBN_SELCHANGE(IDC_GRP14_COMBO, &UIMeshSimulation::OnSelchangeGrp14Combo)
END_MESSAGE_MAP()


// UIMeshSimulation 消息处理程序


void UIMeshSimulation::OnSelchangeGrp14Combo()
{
	int		nIndex = m_ctlCB.GetCurSel();
	if( -1 == nIndex )
		return;

	CString		strText;
	m_ctlCB.GetLBText( nIndex, strText );

	JC::JsonCommand jc;
	jc.SetFunctoin( "texture_simulation_materialproperty" );
	jc.AddParam( "from", "ui" );
	jc.AddParam( "material", strText );
	jc.Notify();

	string		strValue;
	float		fValue;
	if( !jc.GetValue( "Time Step", strValue ) )
		return;
	fValue = atof( strValue.c_str() );
	CMFCCtrlHelper::PropertyGridCtrl_SetPGPValue( &m_ctlPG, 1, (_variant_t)fValue );

	if( !jc.GetValue( "Bending Stiffness", strValue ) )
		return;
	fValue = atof( strValue.c_str() );
	CMFCCtrlHelper::PropertyGridCtrl_SetPGPValue( &m_ctlPG, 2, (_variant_t)fValue );

	if( !jc.GetValue( "Stretch Stiffness", strValue ) )
		return;
	fValue = atof( strValue.c_str() );
	CMFCCtrlHelper::PropertyGridCtrl_SetPGPValue( &m_ctlPG, 3, (_variant_t)fValue );
	
	if( !jc.GetValue( "Cloth Density", strValue ) )
		return;
	fValue = atof( strValue.c_str() );
	CMFCCtrlHelper::PropertyGridCtrl_SetPGPValue( &m_ctlPG, 4, (_variant_t)fValue );
	
	if( !jc.GetValue( "Sewline Bending Stiffness", strValue ) )
		return;
	fValue = atof( strValue.c_str() );
	CMFCCtrlHelper::PropertyGridCtrl_SetPGPValue( &m_ctlPG, 5, (_variant_t)fValue );

	if( !jc.GetValue( "Damping", strValue ) )
		return;
	fValue = atof( strValue.c_str() );
	CMFCCtrlHelper::PropertyGridCtrl_SetPGPValue( &m_ctlPG, 6, (_variant_t)fValue );

	if( !jc.GetValue( "Gravity", strValue ) )
		return;
	fValue = atof( strValue.c_str() );
	CMFCCtrlHelper::PropertyGridCtrl_SetPGPValue( &m_ctlPG, 7, (_variant_t)fValue );

	if( !jc.GetValue( "Bending Model", strValue ) )
		return;
	CMFCCtrlHelper::PropertyGridCtrl_SetPGPValue( &m_ctlPG, 8, (_variant_t)strValue.c_str() );
	
	//OnMaterialPropertyChangeData();
}


