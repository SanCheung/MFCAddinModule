// UIMeshPage1.cpp : 实现文件
//

#include "stdafx.h"
#include "THUIPane.h"
#include "UIMeshTexture.h"
#include <afxdialogex.h>
#include <io.h>

#include "UIPropertyPane.h"

#include "MFCCtrlHelper.h"
#include "JsonCommand.h"


// UIMeshPage1 对话框

IMPLEMENT_DYNAMIC(UIMeshTexture, THSDialog)

UIMeshTexture::UIMeshTexture(CWnd* pParent /*=NULL*/)
	: THSDialog(UIMeshTexture::IDD, FALSE)
	, m_nTextureIndex( 0 )
	, m_strPathDefault( "" )
	, m_strTexture( "" )
	//, m_nBrightness(0)
	//, m_nContrast(0)
	//, m_nHue( 0 )
	//, m_nSaturation( 0 )
	//, m_nGamma( 0 )
	, m_fBrightness( 0.f )
	, m_fContrast( 1.f )
	, m_fHue( 0.f )
	, m_fSaturation( 0.f )
	, m_fGamma( 1.f )
	, m_dX(0)
	, m_dY(0)
	, m_dRotate(0)
	, m_dScale(1.)
	, m_bEditMode(FALSE)
	, m_bFlagMode(FALSE)
	, m_bAlphaMode(FALSE)
{
	Float2IntValue();
}

UIMeshTexture::~UIMeshTexture()
{
}

void UIMeshTexture::DoDataExchange(CDataExchange* pDX)
{
	THSDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_GRP11_RADIO1, m_nTextureIndex);
	DDV_MinMaxInt(pDX, m_nTextureIndex, 0, 3);
	DDX_Text(pDX, IDC_GRP11_EDIT1, m_strTexture);
	DDX_Control(pDX, IDC_GRP11_PICSTC1, m_stPreview);
	DDX_Slider(pDX, IDC_GRP11_SLIDER1, m_nBrightness);
	DDX_Slider(pDX, IDC_GRP11_SLIDER2, m_nContrast);
	DDX_Slider(pDX, IDC_GRP11_SLIDER3, m_nHue);
	DDX_Slider(pDX, IDC_GRP11_SLIDER4, m_nSaturation);
	DDX_Slider(pDX, IDC_GRP11_SLIDER5, m_nGamma);
	DDX_Text(pDX, IDC_GRP11_STC7, m_fBrightness);
	DDX_Text(pDX, IDC_GRP11_STC8,m_fContrast);
	DDX_Text(pDX, IDC_GRP11_STC10, m_fHue);
	DDX_Text(pDX, IDC_GRP11_STC12, m_fSaturation);
	DDX_Text(pDX, IDC_GRP11_STC14, m_fGamma);
	DDX_Control(pDX, IDC_GRP11_SLIDER1, m_ctlSd1);
	DDX_Control(pDX, IDC_GRP11_SLIDER2, m_ctlSd2);
	DDX_Control(pDX, IDC_GRP11_SLIDER3, m_ctlSd3);
	DDX_Control(pDX, IDC_GRP11_SLIDER4, m_ctlSd4);
	DDX_Control(pDX, IDC_GRP11_SLIDER5, m_ctlSd5);
	DDX_Text(pDX, IDC_GRP11_EDIT4, m_dX);
	DDX_Text(pDX, IDC_GRP11_EDIT5, m_dY);
	DDX_Text(pDX, IDC_GRP11_EDIT6, m_dRotate);
	DDX_Text(pDX, IDC_GRP11_EDIT7, m_dScale);
	DDX_Check(pDX, IDC_GRP11_CHECK1, m_bEditMode);
	DDX_Check(pDX, IDC_GRP11_CHECK3, m_bFlagMode);
	DDX_Check(pDX, IDC_GRP11_CHECK2, m_bAlphaMode);
}


BEGIN_MESSAGE_MAP(UIMeshTexture, THSDialog)
	ON_BN_CLICKED(IDC_GRP11_RADIO1, &UIMeshTexture::OnBnClickedRadio_Texture0)
	ON_BN_CLICKED(IDC_GRP11_RADIO2, &UIMeshTexture::OnBnClickedRadio_Texture1)
	ON_BN_CLICKED(IDC_GRP11_RADIO3, &UIMeshTexture::OnBnClickedRadio_Texture2)
	ON_BN_CLICKED(IDC_GRP11_RADIO4, &UIMeshTexture::OnBnClickedRadio_Texture3)
	ON_BN_CLICKED(IDC_GRP11_BTN10, &UIMeshTexture::OnBnClickedBtn10)
	ON_BN_CLICKED(IDC_GRP11_BTN1, &UIMeshTexture::OnBnClickedBtn1)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_GRP11_CHECK1, &UIMeshTexture::OnBnClickedGrp11Check1)
	ON_BN_CLICKED(IDC_GRP11_CHECK2, &UIMeshTexture::OnBnClickedGrp11Check2)
	ON_BN_CLICKED(IDC_GRP11_CHECK3, &UIMeshTexture::OnBnClickedGrp11Check3)
	ON_BN_CLICKED(IDC_GRP11_BTN11, &UIMeshTexture::OnBnClickedGrp11Btn11)
	ON_BN_CLICKED(IDC_GRP11_BTN2, &UIMeshTexture::OnBnClickedGrp11Btn2)
	ON_BN_CLICKED(IDC_GRP11_BTN9, &UIMeshTexture::OnBnClickedGrp11Btn9)
	ON_BN_CLICKED(IDC_GRP11_BTN12, &UIMeshTexture::OnBnClickedGrp11Btn12)
	ON_BN_CLICKED(IDC_GRP11_BTN13, &UIMeshTexture::OnBnClickedGrp11Btn13)
	ON_BN_CLICKED(IDC_GRP11_BTN14, &UIMeshTexture::OnBnClickedGrp11Btn14)
	ON_BN_CLICKED(IDC_GRP11_BTN15, &UIMeshTexture::OnBnClickedGrp11Btn15)
	ON_BN_CLICKED(IDC_GRP11_BTN3, &UIMeshTexture::OnBnClickedGrp11Btn3)
	ON_BN_CLICKED(IDC_GRP11_BTN7, &UIMeshTexture::OnBnClickedGrp11Btn7)
	ON_BN_CLICKED(IDC_GRP11_BTN6, &UIMeshTexture::OnBnClickedGrp11Btn6)
	ON_BN_CLICKED(IDC_GRP11_BTN5, &UIMeshTexture::OnBnClickedGrp11Btn5)
END_MESSAGE_MAP()

void UIMeshTexture::TH_InitData()
{
	//IUIDataExchange* p = GetDataExchange();

	//vector< tuple<CString, CString, CString, CString> > texpaths;
	//vector< tuple< tuple<float, float, float, float>, tuple<float, float, float, float>, tuple<float, float, float, float>, tuple<float, float, float, float>>> texcolorInfo;
	//p->Mesh_Tex_GetTexData( );

	DoSelectTexture( m_nTextureIndex, false );
}




// UIMeshPage1 消息处理程序
//IUIDataExchange * UIMeshTexture::GetDataExchange()
//{
//	if( NULL == m_pOwner )
//		return NULL;
//
//	UIPropertyPane	*pPane = (UIPropertyPane  *)m_pOwner;
//	return pPane->GetDataExchange();
//}

void UIMeshTexture::OnBnClickedRadio_Texture0() //Tecture0 单选按钮
{
	UpdateData();
	DoSelectTexture( m_nTextureIndex );
}


void UIMeshTexture::OnBnClickedRadio_Texture1()  //Texture1 单选按钮
{
	UpdateData();
	DoSelectTexture( m_nTextureIndex );
}


void UIMeshTexture::OnBnClickedRadio_Texture2()  //Texture2 单选按钮
{
	UpdateData();
	DoSelectTexture( m_nTextureIndex );
}


void UIMeshTexture::OnBnClickedRadio_Texture3()  //法向图 单选按钮
{
	UpdateData();
	DoSelectTexture( m_nTextureIndex );
}

//打开纹理路径按钮
void UIMeshTexture::OnBnClickedBtn10()  
{
	if( m_strTexture.IsEmpty() )
		return;

	//1、测试指定路径的文件是否存在
	if( _access( m_strTexture, 0 ) != 0 )
	{
		AfxMessageBox("纹理路径无效");
		return ;
	}

	//打开文件夹并选中文件
	CString strtemp = " /select, ";
	strtemp += m_strTexture;
	SHELLEXECUTEINFO shex = { 0 };
	shex.cbSize = sizeof( SHELLEXECUTEINFO );
	shex.lpFile = _T("explorer");
	shex.lpParameters = strtemp.GetBuffer(0);
	shex.lpVerb = _T( "open" );
	shex.nShow = SW_SHOWDEFAULT;
	shex.lpDirectory =NULL;

	BOOL bResult = ShellExecuteEx( &shex );
	if( !bResult)
		AfxMessageBox("打开纹理路径失败");
}

// 纹理路径浏览 
// 弹出文件对话框，选择一个纹理文件
void UIMeshTexture::OnBnClickedBtn1()  
{
	CFileDialog		dlg( TRUE, "", m_strPathDefault, OFN_NOCHANGEDIR | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_EXTENSIONDIFFERENT, 0, NULL );
	if( IDOK != dlg.DoModal() )
		return;

	double		av[9] = { 0, 1., 0, 0, 1.,   0, 0, 0, 1.};

	UISelectTexture( m_nTextureIndex, dlg.GetPathName(), av );

	//m_strTexture = dlg.GetPathName();
	//UpdateData( FALSE );

	//m_stPreview.SetImageFile( m_strTexture );

	//m_nBrightness = 0;
	//m_fBrightness = (float)m_nBrightness;

	//m_nContrast = 20;
	//m_fContrast = m_nContrast/20.f;

	//m_nHue = 0;
	//m_fHue = (float)m_nHue;

	//m_nSaturation = 50;
	//m_fSaturation = -1.00 + m_nSaturation/50.f;

	//m_nGamma = 25;
	//m_fGamma = m_nGamma/25.f;

	//UpdateData( FALSE );
}


BOOL UIMeshTexture::OnInitDialog()
{
	THSDialog::OnInitDialog();

	//m_strPathDefault = CMFCCtrlHelper::GetModulePath() + "..\\data\\texture\\";
	m_strPathDefault = CMFCCtrlHelper::GetUpperPath( CMFCCtrlHelper::GetModulePath() ) + "\\data\\texture\\";

	m_ctlSd1.SetRange( -255, 255, 1 );
	m_ctlSd1.SetPos( 0 );
	m_ctlSd3.SetRange( 0, 360 );

	// DoSelectTexture( m_nTextureIndex );

	((CSpinButtonCtrl *)GetDlgItem( IDC_SPIN1 ))->SetRange32( -1000, 1000 );
	((CSpinButtonCtrl *)GetDlgItem( IDC_SPIN2 ))->SetRange32( -1000, 1000 );
	((CSpinButtonCtrl *)GetDlgItem( IDC_SPIN3 ))->SetRange32( -1000, 1000 );
	((CSpinButtonCtrl *)GetDlgItem( IDC_SPIN4 ))->SetRange32( -1000, 1000 );
	return TRUE;
}

// 切换功能
void UIMeshTexture::DoSelectTexture( int nIndex, bool bRefreshUI )
{
	if( NULL == m_pOwner )
		return;

	int		meshId = ((UIPropertyPane * )m_pOwner)->m_nMeshId;
	if( -1 == meshId )
		return;

	JC::JsonCommand jc;
	jc.SetFunctoin( "texture_getitem" );
	jc.AddParam( "from", "ui" );
	jc.AddParam( "meshId", meshId );
	jc.AddParam( "index", nIndex );
	jc.Notify();

	string		str;
	double		av[9] = { 0, 1., 0, 0, 1.,   0, 0, 0, 1.};
	if( jc.GetValue( "path", str ) )
	{
		jc.GetValue( "brightness",	av[0] );
		jc.GetValue( "contrast",	av[1] );
		jc.GetValue( "hue",			av[2] );
		jc.GetValue( "saturation",	av[3] );
		jc.GetValue( "gamma",		av[4] );

		jc.GetValue( "centerX",		av[5] );
		jc.GetValue( "centerY",		av[6] );
		jc.GetValue( "angle",		av[7] );
		jc.GetValue( "scale",		av[8] );
	}

	UISelectTexture( nIndex, str.c_str(), av, bRefreshUI );
}


void UIMeshTexture::Float2IntValue()
{
	m_nBrightness	= int( m_fBrightness );
	m_nContrast		= int( m_fContrast*20.f );
	m_nHue			= int( m_fHue );
	m_nSaturation	= int( (m_fSaturation+1.f)*50.f );
	m_fGamma		= int( m_fGamma * 25.f );
}



//void UIMeshTexture::UISelectTexture( int nIndex, CString strPath, float fBrightness, float fContrast, float fHue, float fSaturation, float fGamma, bool bRefreshUI )
void UIMeshTexture::UISelectTexture( int nIndex, CString strPath, double av[9], bool bRefreshUI )
{
	m_nTextureIndex = nIndex;
	m_strTexture	= strPath;
	m_stPreview.SetImageFile( m_strTexture );

	//m_fBrightness	= fBrightness;
	//m_fContrast	= fContrast;
	//m_fHue		= fHue;
	//m_fSaturation	= fSaturation;
	//m_fGamma		= fGamma;

	m_fBrightness	= float(av[0]);
	m_fContrast		= float(av[1]);
	m_fHue			= float(av[2]);
	m_fSaturation	= float(av[3]);
	m_fGamma		= float(av[4]);

	m_dX		= av[5];
	m_dY		= av[6];
	m_dRotate	= av[7];
	m_dScale	= av[8];

	Float2IntValue();

	// 正常情况下需要RefreshUI，当TH_InitData的时候，刷新会出错
	if( bRefreshUI )
		UpdateData( FALSE );
}


void UIMeshTexture::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	THSDialog::OnHScroll(nSBCode, nPos, pScrollBar);

	UpdateData();

	if( pScrollBar == (CScrollBar*)&m_ctlSd1 )
	{
		//m_stPreview.ProcessBrightness( (float)m_nBrightness );
		//m_strBrightness.Format( "%d", m_nBrightness );
		m_fBrightness = (float)m_nBrightness;
	}
	else if( pScrollBar == (CScrollBar*)&m_ctlSd2 )
	{
		m_fContrast = m_nContrast/20.f;
		//m_stPreview.ProcessContrast( v );
	}
	else if( pScrollBar == (CScrollBar*)&m_ctlSd3 )
	{
		m_fHue = (float)m_nHue;
		//m_stPreview.ProcessContrast( v );

	}
	else if( pScrollBar == (CScrollBar*)&m_ctlSd4 )
	{
		m_fSaturation = -1.00 + m_nSaturation/50.f;
		//m_stPreview.ProcessSaturation( v );
	}
	else if( pScrollBar == (CScrollBar*)&m_ctlSd5 )
	{
		m_fGamma = m_nGamma/25.f;
		//m_stPreview.ProcessGamma( v );
	}
	
	m_stPreview.ImageProcess( m_fBrightness, m_fContrast, m_fHue, m_fSaturation, m_fGamma );
	UpdateData( FALSE );	
}

// 编辑模式
void UIMeshTexture::OnBnClickedGrp11Check1()
{
	//AfxMessageBox( "编辑模式" );
	//m_pModelView->OnSignmove(state);

	UpdateData();

	JC::JsonCommand jc;
	jc.SetFunctoin( "texture_editmode" );
	jc.AddParam( "from", "ui" );
	jc.AddParam( "check", m_bEditMode );
	jc.Notify();
}

// 标记模式
void UIMeshTexture::OnBnClickedGrp11Check3()
{
	//AfxMessageBox( "标记模式" );

	UpdateData();

	JC::JsonCommand jc;
	jc.SetFunctoin( "texture_flagmode" );
	jc.AddParam( "from", "ui" );
	jc.AddParam( "check", m_bFlagMode );
	jc.Notify();
}

// alpha模式
void UIMeshTexture::OnBnClickedGrp11Check2()
{
	//AfxMessageBox( "alpha模式" );
	UpdateData();

	JC::JsonCommand jc;
	jc.SetFunctoin( "texture_alphamode" );
	jc.AddParam( "from", "ui" );
	jc.AddParam( "check", m_bAlphaMode );
	jc.Notify();
}

// 清除纹理
void UIMeshTexture::OnBnClickedGrp11Btn11()
{
	//AfxMessageBox( "清除纹理" );
	int		meshId = ((UIPropertyPane * )m_pOwner)->m_nMeshId;
	if( -1 == meshId )
		return;

	UpdateData();

	JC::JsonCommand jc;
	jc.SetFunctoin( "texture_clear" );
	jc.AddParam( "from", "ui" );
	jc.AddParam( "meshId", meshId );
	jc.AddParam( "index", m_nTextureIndex );
	jc.Notify();
}

// 加载纹理
void UIMeshTexture::OnBnClickedGrp11Btn2()
{
	//AfxMessageBox( "加载纹理" );
	int		meshId = ((UIPropertyPane * )m_pOwner)->m_nMeshId;
	if( -1 == meshId )
		return;

	JC::JsonCommand jc;
	jc.SetFunctoin( "texture_load" );
	jc.AddParam( "from", "ui" );
	jc.AddParam( "meshId", meshId );
	jc.AddParam( "index", m_nTextureIndex );
	jc.Notify();
}

// 编辑纹理
void UIMeshTexture::OnBnClickedGrp11Btn9()
{
	//AfxMessageBox( "编辑纹理" );

	int		meshId = ((UIPropertyPane * )m_pOwner)->m_nMeshId;
	if( -1 == meshId )
		return;

	JC::JsonCommand jc;
	jc.SetFunctoin( "texture_edit" );
	jc.AddParam( "from", "ui" );
	jc.AddParam( "meshId", meshId );
	jc.AddParam( "index", m_nTextureIndex );
	jc.Notify();
}


void UIMeshTexture::ChangeMatrix()
{
	int		meshId = ((UIPropertyPane * )m_pOwner)->m_nMeshId;
	if( -1 == meshId )
		return;

	UpdateData();

	JC::JsonCommand jc;
	jc.SetFunctoin( "texture_editx" );
	jc.AddParam( "from", "ui" );
	jc.AddParam( "meshId", meshId );
	jc.AddParam( "index", m_nTextureIndex );
	jc.AddParam( "x", m_dX );
	jc.AddParam( "y", m_dY );
	jc.AddParam( "rotate", m_dRotate );
	jc.AddParam( "scale", m_dScale );
	jc.Notify();
}



// X应用
void UIMeshTexture::OnBnClickedGrp11Btn12()
{
	//AfxMessageBox( "X应用" );
	ChangeMatrix();
}

// Y应用
void UIMeshTexture::OnBnClickedGrp11Btn13()
{
	//AfxMessageBox( "Y应用" );
	ChangeMatrix();
}

// Rotate应用
void UIMeshTexture::OnBnClickedGrp11Btn14()
{
	//AfxMessageBox( "Rotate应用" );
	ChangeMatrix();
}

// Scale应用
void UIMeshTexture::OnBnClickedGrp11Btn15()
{
	//AfxMessageBox( "Scale应用" );
	ChangeMatrix();
}


// 生成路径浏览
void UIMeshTexture::OnBnClickedGrp11Btn3()
{
	//AfxMessageBox( "生成路径浏览" );	
}

// 生成整体纹理
void UIMeshTexture::OnBnClickedGrp11Btn7()
{
	//AfxMessageBox( "生成整体纹理" );
	int		meshId = ((UIPropertyPane * )m_pOwner)->m_nMeshId;
	if( -1 == meshId )
		return;

	UpdateData();

	JC::JsonCommand jc;
	jc.SetFunctoin( "texture_buildMesh" );
	jc.AddParam( "from", "ui" );
	jc.AddParam( "meshId", meshId );
	jc.AddParam( "index", m_nTextureIndex );
	jc.Notify();
}

// 设置默认路径
void UIMeshTexture::OnBnClickedGrp11Btn6()
{
	AfxMessageBox( "设置默认路径" );	
}

// 分配整体纹理坐标
void UIMeshTexture::OnBnClickedGrp11Btn5()
{
	//AfxMessageBox( "分配整体纹理坐标" );
}

