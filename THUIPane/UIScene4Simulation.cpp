// UIScenePage4.cpp : 实现文件
//

#include "stdafx.h"
#include "THUIPane.h"
#include "UIScene4Simulation.h"
#include "afxdialogex.h"

#include "JsonCommand.h"


// UIScenePage4 对话框

IMPLEMENT_DYNAMIC(UIScene4Simulation, THSDialog)

UIScene4Simulation::UIScene4Simulation(CWnd* pParent /*=NULL*/)
	: THSDialog(UIScene4Simulation::IDD, FALSE)
	, m_bPause( true )
{

}

UIScene4Simulation::~UIScene4Simulation()
{
}

void UIScene4Simulation::DoDataExchange(CDataExchange* pDX)
{
	THSDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_GRP25_LIST, m_ctlList);
	DDX_Control(pDX, IDC_GRP25_BTN3, m_ctlBtnInit);
	DDX_Control(pDX, IDC_GRP25_BTN4, m_ctlBtnStart);
	DDX_Control(pDX, IDC_GRP25_BTN5, m_ctlBtnSwitch);
	DDX_Control(pDX, IDC_GRP25_BTN6, m_ctlBtnStop);
}


BEGIN_MESSAGE_MAP(UIScene4Simulation, THSDialog)
	ON_BN_CLICKED(IDC_GRP25_BTN1, &UIScene4Simulation::OnBnClickedGrp25Btn1)
	ON_BN_CLICKED(IDC_GRP25_BTN2, &UIScene4Simulation::OnBnClickedGrp25Btn2)
	ON_BN_CLICKED(IDC_GRP25_BTN3, &UIScene4Simulation::OnBnClickedGrp25Btn3)
	ON_BN_CLICKED(IDC_GRP25_BTN4, &UIScene4Simulation::OnBnClickedGrp25Btn4)
	ON_BN_CLICKED(IDC_GRP25_BTN5, &UIScene4Simulation::OnBnClickedGrp25Btn5)
	ON_BN_CLICKED(IDC_GRP25_BTN6, &UIScene4Simulation::OnBnClickedGrp25Btn6)
END_MESSAGE_MAP()

void UIScene4Simulation::TH_InitData()
{
	m_ctlList.DeleteAllItems();

	JC::JsonCommand jc;
	jc.SetFunctoin( "mesh_getdata" );
	jc.AddParam( "from", "ui" );
	jc.Notify();

	vector< string >	asId, asClass, asName, asLayer;
	jc.GetValue( "idlist", asId );
	jc.GetValue( "classlist", asClass );
	jc.GetValue( "namelist", asName );
	jc.GetValue( "layerlist", asLayer );

	int n = (int)asId.size();
	for( int i = 0;  i < n; i++ )
	{
		m_ctlList.InsertItem( i, asId[i].c_str() );
		m_ctlList.SetItemText( i, 1, asClass[i].c_str() );
		m_ctlList.SetItemText( i, 2, asName[i].c_str() );
		m_ctlList.SetItemText( i, 3, asLayer[i].c_str() );

		m_ctlList.SetCheck( i );
	}
}


// UIScenePage4 消息处理程序


BOOL UIScene4Simulation::OnInitDialog()
{
	THSDialog::OnInitDialog();

	// 设置属性
	DWORD	dwExStyle = m_ctlList.GetExtendedStyle();
	m_ctlList.SetExtendedStyle( dwExStyle | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_CHECKBOXES ); 

	m_ctlList.InsertColumn(0, "" );
	m_ctlList.InsertColumn(1, "类别" );
	m_ctlList.InsertColumn(2, "名字" );
	m_ctlList.InsertColumn(3, "层" );

	m_ctlList.SetColumnWidth( 0, 40 );
	m_ctlList.SetColumnWidth( 1, 100 );
	m_ctlList.SetColumnWidth( 2, 100 );
	m_ctlList.SetColumnWidth( 3, 40 );

	m_ctlBtnStart.EnableWindow( 0 );
	m_ctlBtnSwitch.EnableWindow( 0 );
	m_ctlBtnStop.EnableWindow( 0 );

	return TRUE;
}

void UIScene4Simulation::UISelectAll( int nSelect )
{
	int n = m_ctlList.GetItemCount();
	for( int i = 0; i < n; i++ )
		m_ctlList.SetCheck( i, nSelect );
}

void UIScene4Simulation::UISimulateInit()
{
	m_ctlBtnInit.EnableWindow( 0 );
	m_ctlBtnStart.EnableWindow( 1 );
}

void UIScene4Simulation::UISimulateStart()
{
	m_ctlBtnInit.EnableWindow( 0 );
	m_ctlBtnStart.EnableWindow( 0 );
	m_ctlBtnSwitch.EnableWindow( 1 );
	m_ctlBtnSwitch.SetWindowText( "暂停");
	m_ctlBtnStop.EnableWindow( 1 );
}

void UIScene4Simulation::UISimulateStop()
{
	// ?
	m_ctlBtnInit.EnableWindow( 0 );
	m_ctlBtnStart.EnableWindow( 1 );
	m_ctlBtnSwitch.EnableWindow( 0 );
	m_ctlBtnStop.EnableWindow( 0 );
}

void UIScene4Simulation::UISimulateSwitch( bool bPause )
{
	if( bPause )
		m_ctlBtnSwitch.SetWindowText( "继续");
	else
		m_ctlBtnSwitch.SetWindowText( "暂停");
}

//全部选中
void UIScene4Simulation::OnBnClickedGrp25Btn1()
{
	UISelectAll( 1 );

	JC::JsonCommand jc;
	jc.SetFunctoin( "simulate_selectall" );
	jc.AddParam( "from", "ui" );
	jc.Notify();
}

// 全取消选中
void UIScene4Simulation::OnBnClickedGrp25Btn2()
{
	UISelectAll( 0 );

	JC::JsonCommand jc;
	jc.SetFunctoin( "simulate_unselectall" );
	jc.AddParam( "from", "ui" );
	jc.Notify();
}

//初始化模拟
void UIScene4Simulation::OnBnClickedGrp25Btn3()
{
	UISimulateInit();

	JC::JsonCommand jc;
	jc.SetFunctoin( "simulate_init" );
	jc.AddParam( "from", "ui" );
	jc.Notify();

}

//开始模拟
void UIScene4Simulation::OnBnClickedGrp25Btn4()
{
	UISimulateStart();

	JC::JsonCommand jc;
	jc.SetFunctoin( "simulate_start" );
	jc.AddParam( "from", "ui" );
	jc.Notify();
}

//暂停/继续
void UIScene4Simulation::OnBnClickedGrp25Btn5()
{
	UISimulateSwitch( m_bPause );

	JC::JsonCommand jc;
	jc.SetFunctoin( "simulate_switch" );
	jc.AddParam( "from", "ui" );
	jc.AddParam( "ispause", m_bPause?1:0 );
	jc.Notify();

	m_bPause = !m_bPause;
}

//结束模拟
void UIScene4Simulation::OnBnClickedGrp25Btn6()
{
	UISimulateStop();

	JC::JsonCommand jc;
	jc.SetFunctoin( "simulate_stop" );
	jc.AddParam( "from", "ui" );
	jc.Notify();
}
