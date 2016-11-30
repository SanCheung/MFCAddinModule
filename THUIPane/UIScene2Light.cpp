// UIScenePage2.cpp : 实现文件
//

#include "stdafx.h"
#include "THUIPane.h"
#include "UIScene2Light.h"
#include "afxdialogex.h"

#include "UIPropertyPane.h"

#include "JsonCommand.h"

// UIScenePage2 对话框

IMPLEMENT_DYNAMIC(UIScene2Light, THSDialog)

UIScene2Light::UIScene2Light(CWnd* pParent /*=NULL*/)
	: THSDialog( UIScene2Light::IDD, FALSE )
{

}

UIScene2Light::~UIScene2Light()
{
}

void UIScene2Light::DoDataExchange(CDataExchange* pDX)
{
	THSDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_GRP23_LIST, m_ctlList);
	DDX_Control(pDX, IDC_GRP23_COM, m_ctlCB);
	DDX_Control(pDX, IDC_GRP23_GRID, m_ctlPG);
}


BEGIN_MESSAGE_MAP(UIScene2Light, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_GRP23_LIST, &UIScene2Light::OnLvnItemchangedGrp23List)
	ON_BN_CLICKED(IDC_GRP23_BTN1, &UIScene2Light::OnBnClickedGrp23Btn1)
	ON_BN_CLICKED(IDC_GRP23_BTN2, &UIScene2Light::OnBnClickedGrp23Btn2)
	ON_BN_CLICKED(IDC_GRP23_BTN3, &UIScene2Light::OnBnClickedGrp23Btn3)
	ON_BN_CLICKED(IDC_GRP23_CHECK, &UIScene2Light::OnBnClickedGrp23Check)
	ON_CBN_SELCHANGE(IDC_GRP23_COM, &UIScene2Light::OnCbnSelchangeGrp23Com)

	ON_REGISTERED_MESSAGE(AFX_WM_PROPERTY_CHANGED, OnPropertyChanged)
END_MESSAGE_MAP()

void UIScene2Light::TH_InitData()
{
	m_ctlList.DeleteAllItems();

	JC::JsonCommand jc;
	jc.SetFunctoin( "light_getdata" );
	jc.AddParam( "from", "ui" );
	jc.Notify();

	vector< string >	asName, asMode;
	vector< int >		anEnable;
	jc.GetValue( "namelist", asName );
	jc.GetValue( "modelist", asMode );
	jc.GetValue( "enablelist", anEnable );

	int n = (int)asName.size();
	for( int i = 0;  i < n; i++ )
		UIAddLightItem( i, asName[i], asMode[i], anEnable[i] );

	if( n > 0 )
		SelectListCtrlItem( &m_ctlList, 0 );
}



void UIScene2Light::UIAddLightItem( int i, string strId, string strMode, int nEnable )
{
	m_ctlList.InsertItem( i, strId.c_str() );
	m_ctlList.SetItemText( i, 1, strMode.c_str() );
	m_ctlList.SetItemText( i, 3, nEnable==1 ? "是": "否" );
}



// UIScenePage2 消息处理程序


BOOL UIScene2Light::OnInitDialog()
{
	THSDialog::OnInitDialog();

	m_ctlList.SetExtendedStyle( m_ctlList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES  ); 
	
	//CRect rect;     
	//m_ctlList.GetClientRect(&rect); 

	//int h = rect.Height();

	//m_ctlList.InsertColumn( 0, "ID", LVCFMT_LEFT, int(h*0.15), 0);
	//m_ctlList.InsertColumn( 1, "类型",LVCFMT_CENTER, int(h*0.3), 0);
	//m_ctlList.InsertColumn( 2, "名字",LVCFMT_CENTER, int(h*0.25), 0);
	//m_ctlList.InsertColumn( 3, "有效",LVCFMT_CENTER, int(h*0.3), 0);

	m_ctlList.InsertColumn(0, _T("ID") );
	m_ctlList.InsertColumn(1, _T("类别") );
	m_ctlList.InsertColumn(2, _T("名字") );
	m_ctlList.InsertColumn(3, _T("有效") );

	m_ctlList.SetColumnWidth( 0, 30 );
	m_ctlList.SetColumnWidth( 1, 100 );
	m_ctlList.SetColumnWidth( 2, 50 );
	m_ctlList.SetColumnWidth( 3, 100 );


	// init PropertyGrid Header
	CMFCHeaderCtrl	&ctlHeader = m_ctlPG.GetHeaderCtrl();

	HDITEM			hi = {0};
	hi.mask = HDI_WIDTH;

	CRect			rt;
	ctlHeader.GetClientRect( &rt );

	hi.cxy = 120;
	ctlHeader.SetItem( 0, &hi );

	hi.cxy = rt.Width() - hi.cxy;
	ctlHeader.SetItem( 1, &hi );

	// init PropertyGrid Format
	CMFCPropertyGridProperty	*pGroup = NULL;
	
	// pos
	pGroup = new CMFCPropertyGridProperty(_T("位置")); 
	{
		pGroup->AddSubItem( new CMFCPropertyGridProperty( _T("X"), (_variant_t)0.f, _T("x位置"), POS_X ));
		pGroup->AddSubItem( new CMFCPropertyGridProperty( _T("Y"), (_variant_t)0.f, _T("y位置"), POS_Y ));
		pGroup->AddSubItem( new CMFCPropertyGridProperty( _T("Z"), (_variant_t)0.f, _T("z位置"), POS_Z ));
	}
	pGroup->SetData( POS );
	m_ctlPG.AddProperty( pGroup );

	// dir
	pGroup = new CMFCPropertyGridProperty(_T("方向")); 
	{
		pGroup->AddSubItem( new CMFCPropertyGridProperty( _T("X"), (_variant_t)0.f, _T("x方向"), DIR_X ));
		pGroup->AddSubItem( new CMFCPropertyGridProperty( _T("Y"), (_variant_t)0.f, _T("y方向"), DIR_Y ));
		pGroup->AddSubItem( new CMFCPropertyGridProperty( _T("Z"), (_variant_t)0.f, _T("z方向"), DIR_Z ));
	}
	pGroup->SetData( DIR );
	m_ctlPG.AddProperty( pGroup );

	m_ctlPG.AddProperty( NewPropertyItem_Option( HASSHADOW, _T("阴影"), _T("否"), _T("") ) );
	m_ctlPG.AddProperty( NewPropertyItem_Option( FIXONCAMERA, _T("相对视点静止"), _T("否"), _T("") ) );

	m_ctlPG.AddProperty( NewPropertyItem_Color( RGB(255,255,255), ::GetSysColor(COLOR_3DFACE), DIFFUSE, _T("散射光") ));
	m_ctlPG.AddProperty( NewPropertyItem_Color( RGB(255,255,255), ::GetSysColor(COLOR_3DFACE), SPECULAR, _T("反射光") ));
	m_ctlPG.AddProperty( NewPropertyItem_Color( RGB(0,0,0), ::GetSysColor(COLOR_3DFACE), AMBIENT, _T("环境光") ));
	m_ctlPG.AddProperty( NewPropertyItem_Color( RGB(1,1,1), ::GetSysColor(COLOR_3DFACE), AMBIENTGLOBAL, _T("全局环境光") ));

	pGroup = new CMFCPropertyGridProperty( _T("衰减") ); 
	{
		pGroup->AddSubItem( new CMFCPropertyGridProperty( _T("常数系数"), (_variant_t)1.f, _T(""), CONSTANT_ATTENUATION ));
		pGroup->AddSubItem( new CMFCPropertyGridProperty( _T("一次项系数"), (_variant_t)0.f, _T(""), LINEAR_ATTENUATION ));
		pGroup->AddSubItem( new CMFCPropertyGridProperty( _T("二次项系数"), (_variant_t)0.f, _T(""), QUADRATIC_ATTENUATION ));
	}
	m_ctlPG.AddProperty( pGroup );


	pGroup = new CMFCPropertyGridProperty( _T("聚光灯选项") ); 
	{
		pGroup->AddSubItem( new CMFCPropertyGridProperty( _T("聚光指数"), (_variant_t)0.f, _T(""), EXPONENT ));
		pGroup->AddSubItem( new CMFCPropertyGridProperty( _T("角度"), (_variant_t)0.f, _T(""), CUTOFF ));
	}
	m_ctlPG.AddProperty( pGroup );

		
	pGroup = new CMFCPropertyGridProperty( _T("边缘轮廓") ); 
	{
		pGroup->AddSubItem( NewPropertyItem_Color( RGB(0,0,0), RGB(255,255,194), BORDERLIGHT, _T("光轮廓") ));
		pGroup->AddSubItem( new CMFCPropertyGridProperty( _T("光轮廓指数"), (_variant_t)0.f, _T(""), BORDERLIGHTFACT ));
		pGroup->AddSubItem( NewPropertyItem_Option( HASBLACKBORDER, _T("黑色描边"),  (_variant_t)_T("否") ));
		pGroup->AddSubItem( new CMFCPropertyGridProperty( _T("描边线宽度"), (_variant_t)2.f, _T(""), BLACKBORDERLINEWIDTH ));
	}
	m_ctlPG.AddProperty( pGroup );

	return TRUE;
}

CMFCPropertyGridProperty* UIScene2Light::NewPropertyItem_Option( DWORD_PTR dwData, const CString& strName, const COleVariant& varValue, LPCTSTR lpszDescr /*= NULL */ )
{
	CMFCPropertyGridProperty *pItem = new CMFCPropertyGridProperty( strName, varValue, lpszDescr, dwData );
	pItem->AddOption( _T("是") );
	pItem->AddOption( _T("否") );
	pItem->AllowEdit( FALSE );

	return pItem;
}

CMFCPropertyGridColorProperty* UIScene2Light::NewPropertyItem_Color( COLORREF crDefault, COLORREF crAutomatic, DWORD_PTR dwData, const CString& strName, LPCTSTR lpszDescr /*= NULL */ )
{
	CMFCPropertyGridColorProperty *pItem = new  CMFCPropertyGridColorProperty( strName, crDefault, NULL, lpszDescr, dwData );
	pItem->EnableOtherButton( _T("其他...") );
	pItem->EnableAutomaticButton(_T("默认"), crAutomatic );

	return pItem;
}


void UIScene2Light::OnLvnItemchangedGrp23List(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	*pResult = 0;

	int nIndex = m_ctlList.GetSelectionMark();
	if( nIndex < 0 )
		return;

	JC::JsonCommand jc;
	jc.SetFunctoin( "light_getitem" );
	jc.AddParam( "index", nIndex );
	jc.AddParam( "from", "ui" );
	jc.Notify();

	UISelectLight( nIndex, &jc );
}

// 新建光照
void UIScene2Light::OnBnClickedGrp23Btn1()
{
	JC::JsonCommand jc;
	jc.SetFunctoin( "light_new" );
	jc.AddParam( "from", "ui" );
	jc.Notify();

	string	strId, strMode;
	jc.GetValue( "id", strId );
	jc.GetValue( "mode", strMode );

	int		nEnable;
	jc.GetValue( "enable", nEnable );

	int		n = m_ctlList.GetItemCount();
	UIAddLightItem( n, strId, strMode, nEnable );
	SelectListCtrlItem( &m_ctlList, n );
}


void UIScene2Light::OnBnClickedGrp23Btn2()
{
	int nIndex = m_ctlList.GetSelectionMark();
	if( nIndex < 0 )
		return;

	JC::JsonCommand jc;
	jc.SetFunctoin( "light_delete" );
	jc.AddParam( "index", nIndex );
	jc.AddParam( "from", "ui" );
	jc.Notify();

	UIDeleteLight( nIndex );
}


void UIScene2Light::OnBnClickedGrp23Btn3()
{
	JC::JsonCommand jc;
	jc.SetFunctoin( "light_show" );
	jc.AddParam( "from", "ui" );
	jc.Notify();
}


void UIScene2Light::OnBnClickedGrp23Check()
{
	int nIndex = m_ctlList.GetSelectionMark();
	if( nIndex < 0 )
		return;

	CButton *pButton = (CButton *)GetDlgItem(IDC_GRP23_CHECK);
	bool bCheck = pButton->GetCheck() ? true : false;

	JC::JsonCommand jc;
	jc.SetFunctoin( "light_enable" );
	jc.AddParam( "index", nIndex );
	jc.AddParam( "enable", bCheck );
	jc.AddParam( "from", "ui" );
	jc.Notify();	

	UIEnableLight( nIndex, bCheck );
}


void UIScene2Light::OnCbnSelchangeGrp23Com()
{
	int nIndex = m_ctlList.GetSelectionMark();
	if( nIndex < 0 )
		return;

	int	nMode = m_ctlCB.GetCurSel();
	if( nMode < 0 )
		return;

	JC::JsonCommand jc;
	jc.SetFunctoin( "light_changemode" );
	jc.AddParam( "index", nIndex );
	jc.AddParam( "mode", nMode );
	jc.AddParam( "from", "ui" );
	jc.Notify();

	UIChangeLightMode( nIndex, nMode );
}


// every mothed for use command to control UI 
void UIScene2Light::UISelectLight( int nIndex, JC::JsonCommand *pValue )
{
	if( NULL == pValue )
		return;

	int		nMode;
	pValue->GetValue( "LightMode", nMode );
	if( nMode < 0 || nMode > 2 )
		nMode = 0;

	m_ctlCB.SetCurSel( nMode );
	m_ctlCB.SetCurSel( 1 );
	
	int		nEnable;
	pValue->GetValue( "Enabled", nEnable );
	((CButton*)GetDlgItem(IDC_GRP23_CHECK))->SetCheck( nEnable );

	//GLLight &light = m_pModelView->m_glscene.m_Lights[lightid];
	//LightClassComboCtrl.SetCurSel(light.LightMode);
	//EnabledCheckCtrl.SetCheck(light.Enabled);

	double	v1, v2, v3;
	pValue->GetValue( "PositionX", v1 );
	pValue->GetValue( "PositionY", v2 );
	pValue->GetValue( "PositionZ", v3 );
	SetPGPValue( POS_X, (float)v1 );
	SetPGPValue( POS_Y, (float)v2 );
	SetPGPValue( POS_Z, (float)v3 );

	//CMFCPropertyGridProperty* p;
	////p = m_mfcPropertyGridCtrl.GetProperty(0);//是第几个属性
	////p->GetSubItem(1);//第几个属性
	//mfcPropertyGridCtrl.FindItemByData(POS);//根据数据调用
	//mfcPropertyGridCtrl.FindItemByData(POS_X)->SetValue((_variant_t)light.Position[0]);
	//mfcPropertyGridCtrl.FindItemByData(POS_Y)->SetValue((_variant_t)light.Position[1]);
	//mfcPropertyGridCtrl.FindItemByData(POS_Z)->SetValue((_variant_t)light.Position[2]);

	pValue->GetValue( "DirectionX", v1 );
	pValue->GetValue( "DirectionY", v2 );
	pValue->GetValue( "DirectionZ", v3 );
	SetPGPValue( DIR_X, (float)v1 );
	SetPGPValue( DIR_Y, (float)v2 );
	SetPGPValue( DIR_Z, (float)v3 );

	//mfcPropertyGridCtrl.FindItemByData(DIR);
	//mfcPropertyGridCtrl.FindItemByData(DIR_X)->SetValue((_variant_t)light.Direction[0]);
	//mfcPropertyGridCtrl.FindItemByData(DIR_Y)->SetValue((_variant_t)light.Direction[1]);
	//mfcPropertyGridCtrl.FindItemByData(DIR_Z)->SetValue((_variant_t)light.Direction[2]);

	int		cr;
	pValue->GetValue( "Diffuse", cr );
	SetPGPColor( DIFFUSE, cr );

	//COLORREF color;
	//color = RGB(light.Diffuse[0]*255,light.Diffuse[1]*255,light.Diffuse[2]*255);
	//((CMFCPropertyGridColorProperty*)mfcPropertyGridCtrl.FindItemByData(DIFFUSE))->SetColor(color);

	pValue->GetValue( "Specular", cr );
	SetPGPColor( SPECULAR, cr );

	//color = RGB(light.Specular[0]*255,light.Specular[1]*255,light.Specular[2]*255);
	//((CMFCPropertyGridColorProperty*)mfcPropertyGridCtrl.FindItemByData(SPECULAR))->SetColor(color);

	pValue->GetValue( "Ambient", cr );
	SetPGPColor( AMBIENT, cr );

	//color = RGB(light.Ambient[0]*255,light.Ambient[1]*255,light.Ambient[2]*255);
	//((CMFCPropertyGridColorProperty*)mfcPropertyGridCtrl.FindItemByData(AMBIENT))->SetColor(color);

	pValue->GetValue( "AmbientGlobal", cr );
	SetPGPColor( AMBIENTGLOBAL, cr );

	//color = RGB(light.AmbientGlobal[0]*255,light.AmbientGlobal[1]*255,light.AmbientGlobal[2]*255);
	//((CMFCPropertyGridColorProperty*)mfcPropertyGridCtrl.FindItemByData(AMBIENTGLOBAL))->SetColor(color);

	pValue->GetValue( "Constant_Attenuation", v1 );
	pValue->GetValue( "Linear_Attenuation", v2 );
	pValue->GetValue( "Quadratic_Attenuation", v3 );
	SetPGPValue( CONSTANT_ATTENUATION, (float)v1 );
	SetPGPValue( LINEAR_ATTENUATION, (float)v2 );
	SetPGPValue( QUADRATIC_ATTENUATION, (float)v3 );

	//mfcPropertyGridCtrl.FindItemByData(CONSTANT_ATTENUATION)->SetValue((_variant_t)light.Constant_Attenuation);
	//mfcPropertyGridCtrl.FindItemByData(LINEAR_ATTENUATION)->SetValue((_variant_t)light.Linear_Attenuation);
	//mfcPropertyGridCtrl.FindItemByData(QUADRATIC_ATTENUATION)->SetValue((_variant_t)light.Quadratic_Attenuation);

	pValue->GetValue( "Exponent", v1 );
	pValue->GetValue( "Cutoff", v2 );
	SetPGPValue( EXPONENT, (float)v1 );
	SetPGPValue( CUTOFF, (float)v2 );
	//mfcPropertyGridCtrl.FindItemByData(EXPONENT)->SetValue((_variant_t)light.Exponent);
	//mfcPropertyGridCtrl.FindItemByData(CUTOFF)->SetValue((_variant_t)light.Cutoff);

	pValue->GetValue( "BorderLight", cr );
	SetPGPColor( BORDERLIGHT, cr );
	//color = RGB(GLLight::BorderLight[0]*255,GLLight::BorderLight[1]*255,GLLight::BorderLight[2]*255);
	//((CMFCPropertyGridColorProperty*)mfcPropertyGridCtrl.FindItemByData(BORDERLIGHT))->SetColor(color);

	pValue->GetValue( "BorderLightFact", v1 );
	SetPGPValue( BORDERLIGHTFACT, (float)v1 );
	//mfcPropertyGridCtrl.FindItemByData(BORDERLIGHTFACT)->SetValue(GLLight::BorderLightFact);

	bool	b = false;
	pValue->GetValue( "HasBlackBorder", b );
	SetPGPValue( HASBLACKBORDER, b?"是":"否" );
	//char* s;
	//if (GLLight::HasBlackBorder)
	//{
	//	s = "是";
	//}else
	//{
	//	s = "否";
	//}
	//mfcPropertyGridCtrl.FindItemByData(HASBLACKBORDER)->SetValue(s);

	pValue->GetValue( "BlackBorderLineWidth", b );
	SetPGPValue( HASBLACKBORDER, b?"是":"否" );
	//mfcPropertyGridCtrl.FindItemByData(BLACKBORDERLINEWIDTH)->SetValue((_variant_t)GLLight::BlackBorderLineWidth);

	pValue->GetValue( "HasShadow", b );
	SetPGPValue( HASBLACKBORDER, b?"是":"否" );
	//if (light.HasShadow)
	//{
	//	s = "是";
	//}else
	//{
	//	s = "否";
	//}
	//mfcPropertyGridCtrl.FindItemByData(HASSHADOW)->SetValue(s);

	pValue->GetValue( "FixOnCamera", b );
	SetPGPValue( HASBLACKBORDER, b?"是":"否" );
	//if (light.FixOnCamera)
	//{
	//	s = "是";
	//}else
	//{
	//	s = "否";
	//}
	//mfcPropertyGridCtrl.FindItemByData(FIXONCAMERA)->SetValue(s);
}


void UIScene2Light::UIDeleteLight( int nIndex )
{
	if( nIndex < 0 && nIndex >= m_ctlList.GetItemCount() )
		return;

	m_ctlList.DeleteItem( nIndex );
	
	int n = m_ctlList.GetItemCount();
	if( n > 0 )
		SelectListCtrlItem( &m_ctlList, n-1 );
}

void UIScene2Light::UIEnableLight( int nIndex, int nEnable )
{
	m_ctlList.SetItemText( nIndex, 3, nEnable==1 ? "是": "否" );
}



void UIScene2Light::UIChangeLightMode( int nIndex, int nMode )
{
	if( nMode < 0 || nMode >= 3 )
		return;

	static const char* s_ModeList[3] = {"点光", "方向光", "聚光灯" };
	m_ctlList.SetItemText( nIndex, 1, s_ModeList[nMode] );
}


// private function for PropertyGrid
void UIScene2Light::SetPGPValue( DWORD_PTR dwData, COleVariant val )
{
	CMFCPropertyGridProperty* pPro = m_ctlPG.FindItemByData( dwData );
	if( NULL == pPro )
		return;

	pPro->SetValue( val );
}

void UIScene2Light::SetPGPColor( DWORD_PTR dwData, int val )
{
	CMFCPropertyGridColorProperty* pPro = (CMFCPropertyGridColorProperty *)m_ctlPG.FindItemByData( dwData );
	if( NULL == pPro )
		return;

	pPro->SetColor( val );
}

void UIScene2Light::SelectListCtrlItem( CListCtrl *pListCtrl, int nIndex )
{
	if( NULL == pListCtrl || !::IsWindow( pListCtrl->m_hWnd ) )
		return;

	pListCtrl->SetItemState( nIndex, LVIS_FOCUSED | LVIS_SELECTED,LVIS_FOCUSED | LVIS_SELECTED );
	pListCtrl->SetSelectionMark( nIndex );
}

LRESULT UIScene2Light::OnPropertyChanged( WPARAM wParam ,LPARAM lParam )
{
	int nIndex = m_ctlList.GetSelectionMark();
	if( nIndex < 0 )
		return 0;

	CMFCPropertyGridProperty *pPro = (CMFCPropertyGridProperty*)lParam;
	if( NULL == pPro )
		return 0;

	int		nDataId;
	nDataId = (int)pPro->GetData();

	COleVariant Value = pPro->GetValue();

	JC::JsonCommand jc;
	jc.SetFunctoin( "light_setproperty" );
	jc.AddParam( "from", "ui" );
	jc.AddParam( "index", nIndex );
	jc.AddParam( "propertyId", nDataId );
	switch( nDataId ) {
		case POS_X:
		case POS_Y:
		case POS_Z:
		case DIR_X:
		case DIR_Y:
		case DIR_Z:
		case CONSTANT_ATTENUATION:
		case LINEAR_ATTENUATION:
		case QUADRATIC_ATTENUATION:
		case EXPONENT:
		case CUTOFF:
		case BORDERLIGHTFACT:
		case BLACKBORDERLINEWIDTH:
			jc.AddParam( "propertytype", "double" );
			jc.AddParam( "propertyValue", Value.fltVal );
			break;
		case DIFFUSE:
		case SPECULAR:
		case AMBIENT:
		case AMBIENTGLOBAL:
		case BORDERLIGHT: {
				std::vector<double> fvec;
				COLORREF color = ((CMFCPropertyGridColorProperty*)pPro)->GetColor();
				fvec.push_back(GetRValue(color)/255.0);
				fvec.push_back(GetGValue(color)/255.0);
				fvec.push_back(GetBValue(color)/255.0);
				jc.AddParam( "propertytype", "vector" );
				jc.AddParam( "propertyValue", fvec );
			}
			break;
		case HASBLACKBORDER:
		case HASSHADOW:
		case FIXONCAMERA: {
				_bstr_t bstr_t(Value.bstrVal);
				std::string str(bstr_t);
				jc.AddParam( "propertytype", "string" );
				jc.AddParam( "propertyValue", str );
			}
			break;
		default:
			break;
	}
	jc.Notify();

	return 0;
}

