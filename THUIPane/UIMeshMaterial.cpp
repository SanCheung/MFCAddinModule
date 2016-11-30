// UIMeshMaterial.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "THUIPane.h"
#include "UIMeshMaterial.h"
#include "afxdialogex.h"
#include "MFCCtrlHelper.h"


// UIMeshMaterial �Ի���

IMPLEMENT_DYNAMIC(UIMeshMaterial, THSDialog)

UIMeshMaterial::UIMeshMaterial(CWnd* pParent /*=NULL*/)
	: THSDialog(UIMeshMaterial::IDD, FALSE)
{

}

UIMeshMaterial::~UIMeshMaterial()
{
}

void UIMeshMaterial::DoDataExchange(CDataExchange* pDX)
{
	THSDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_GRP12_GRID1, m_ctlPG);
}

void UIMeshMaterial::TH_InitData()
{

}

BEGIN_MESSAGE_MAP(UIMeshMaterial, THSDialog)
END_MESSAGE_MAP()


// UIMeshMaterial ��Ϣ�������


BOOL UIMeshMaterial::OnInitDialog()
{
	THSDialog::OnInitDialog();

	// init PropertyGrid Header
	CMFCHeaderCtrl	&ctlHeader = m_ctlPG.GetHeaderCtrl();

	HDITEM			hi = {0};
	hi.mask = HDI_WIDTH|HDI_TEXT;

	CRect			rt;
	ctlHeader.GetClientRect( &rt );

	hi.cxy = 120;
	hi.pszText = _T("��������");
	ctlHeader.SetItem( 0, &hi );

	hi.cxy = rt.Width() - hi.cxy;
	hi.pszText = _T("ֵ");
	ctlHeader.SetItem( 1, &hi );

	// init PropertyGrid Format
	m_ctlPG.AddProperty( CMFCCtrlHelper::PropertyGridCtrl_NewOption( 1, _T("�����б�"), _T("��ʼ����"), _T("ѡ��Ԥ�����") ) );
	// PropertyGridCtrl_NewOption2

	CMFCPropertyGridProperty	*pGroup = NULL;

	// Phong
	pGroup = new CMFCPropertyGridProperty(_T("Phong")); 
	{
		pGroup->AddSubItem( CMFCCtrlHelper::PropertyGridCtrl_NewColor( RGB(255, 255, 255), ::GetSysColor(COLOR_3DFACE), 2, _T("ɢ��ϵ��") ) );
		pGroup->AddSubItem( CMFCCtrlHelper::PropertyGridCtrl_NewColor( RGB(255, 255, 255), ::GetSysColor(COLOR_3DFACE), 3, _T("����ϵ��") ) );
		pGroup->AddSubItem( CMFCCtrlHelper::PropertyGridCtrl_NewColor( RGB(0, 0, 0), ::GetSysColor(COLOR_3DFACE), 4, _T("����ϵ��") ) );
		pGroup->AddSubItem( CMFCCtrlHelper::PropertyGridCtrl_NewColor( RGB(0, 0, 0), ::GetSysColor(COLOR_3DFACE), 5, _T("�����") ) );

		pGroup->AddSubItem( CMFCCtrlHelper::PropertyGridCtrl_NewColor( RGB(0, 0, 0), ::GetSysColor(COLOR_3DFACE), 6, _T("�߹�ָ��") ) );

		pGroup->AddSubItem( new CMFCPropertyGridProperty( _T("�߹�ָ��"), (_variant_t)500.f, _T("�߹�ָ������"), 7 ));
		pGroup->AddSubItem( new CMFCPropertyGridProperty( _T("�Ƿ�͸��"), (_variant_t)1.f, _T("�Ƿ�͸��ѡ��Ի���"), 8 ));
	}
	m_ctlPG.AddProperty( pGroup );

	pGroup = new CMFCPropertyGridProperty(_T("����"));
	{
		pGroup->AddSubItem( new CMFCPropertyGridProperty( _T("Shader�ű�"), (_variant_t)_T("Shader: 0"), _T("��ǰShader�ű�"), 9 ));
		pGroup->AddSubItem( new CMFCPropertyGridProperty( _T("�����ʣ��ǣ�"), (_variant_t)1.f, _T("����������"), 10 ));
	}
	m_ctlPG.AddProperty( pGroup );

	vector< CString >		as;
	as.push_back( _T("X") );
	as.push_back( _T("Y") );
	m_ctlPG.AddProperty( CMFCCtrlHelper::PropertyGridCtrl_NewOption2( 11, _T("tab"), _T("X"), as, _T("Tangent �� Binormal") ));

	pGroup = new CMFCPropertyGridProperty(_T("Tangent"));
	{
		pGroup->AddSubItem( CMFCCtrlHelper::PropertyGridCtrl_NewColor( RGB(255, 255, 255), ::GetSysColor(COLOR_3DFACE), 11, _T("Color") ) );
		pGroup->AddSubItem( new CMFCPropertyGridProperty( _T("Scale"), (_variant_t)0.3f, _T(""), 12 ));
		pGroup->AddSubItem( new CMFCPropertyGridProperty( _T("Kd"), (_variant_t)0.3f, _T(""), 13 ));
		pGroup->AddSubItem( new CMFCPropertyGridProperty( _T("Rs"), (_variant_t)12.f, _T(""), 14 ));
		pGroup->AddSubItem( new CMFCPropertyGridProperty( _T("Rv"), (_variant_t)24.f, _T(""), 15 ));
		pGroup->AddSubItem( new CMFCPropertyGridProperty( _T("Alpha"), (_variant_t)24.f, _T(""), 16 ));
		pGroup->AddSubItem( new CMFCPropertyGridProperty( _T("Offsets"), (_variant_t)24.f, _T("Offsets (Degrees)"), 17 ));
		pGroup->AddSubItem( new CMFCPropertyGridProperty( _T("Lengths"), (_variant_t)_T("1,1"), _T(""), 18 ) );
	}
	m_ctlPG.AddProperty( pGroup );


	pGroup = new CMFCPropertyGridProperty(_T("Binormal"));
	{
		pGroup->AddSubItem( CMFCCtrlHelper::PropertyGridCtrl_NewColor( RGB(255, 255, 255), ::GetSysColor(COLOR_3DFACE), 21, _T("Color") ) );
		pGroup->AddSubItem( new CMFCPropertyGridProperty( _T("Scale"), (_variant_t)0.3f, _T(""), 22 ));
		pGroup->AddSubItem( new CMFCPropertyGridProperty( _T("Kd"), (_variant_t)0.3f, _T(""), 23 ));
		pGroup->AddSubItem( new CMFCPropertyGridProperty( _T("Rs"), (_variant_t)12.f, _T(""), 24 ));
		pGroup->AddSubItem( new CMFCPropertyGridProperty( _T("Rv"), (_variant_t)24.f, _T(""), 25 ));
		pGroup->AddSubItem( new CMFCPropertyGridProperty( _T("Alpha"), (_variant_t)24.f, _T(""), 26 ));
		pGroup->AddSubItem( new CMFCPropertyGridProperty( _T("Offsets"), (_variant_t)_T("-32,-32,-18,0,18,32,32"), _T("Offsets (Degrees)"),27 ));
		pGroup->AddSubItem( new CMFCPropertyGridProperty( _T("Lengths"), (_variant_t)_T("1.33,0.66,2,2,2,0.66,1.33"), _T(""), 28 ) );
	}

	pGroup->Show( FALSE );
	m_ctlPG.AddProperty( pGroup );

	return TRUE;
}
