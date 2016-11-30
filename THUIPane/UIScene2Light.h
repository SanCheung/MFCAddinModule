#pragma once

#include "../THAddIn/THSDialog.h"
#include "afxwin.h"
#include "afxpropertygridctrl.h"
#include "afxcmn.h"
#include "UI_light_enum.h"

namespace JC
{
	class JsonCommand;
}

// UIScenePage2 对话框
class IUIDataExchange;
class UIScene2Light : public THUI::THSDialog
{
	DECLARE_DYNAMIC(UIScene2Light)

public:
	UIScene2Light(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~UIScene2Light();

// 对话框数据
	enum { IDD = IDD_SCENE2_LIGHT };


	// 给外部调用的UI改变函数
	void	UISelectLight( int nIndex, JC::JsonCommand *pValue );
	void	UIDeleteLight( int nIndex );
	void	UIEnableLight( int nIndex, int nEnable );
	void	UIChangeLightMode( int nIndex, int nMode );
	void	UIAddLightItem( int i, string strId, string strMode, int nEnable );


private:
	CMFCPropertyGridProperty*		NewPropertyItem_Option( DWORD_PTR dwData, const CString& strName, const COleVariant& varValue, LPCTSTR lpszDescr = NULL );
	CMFCPropertyGridColorProperty*	NewPropertyItem_Color( COLORREF crDefault, COLORREF crAutomatic, DWORD_PTR dwData, const CString& strName, LPCTSTR lpszDescr = NULL );
	
	void	SetPGPValue( DWORD_PTR dwData, COleVariant val );
	void	SetPGPColor( DWORD_PTR dwData, int val );

	void	SelectListCtrlItem( CListCtrl *pListCtrl, int nIndex );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	afx_msg void OnLvnItemchangedGrp23List(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedGrp23Btn1();
	afx_msg void OnBnClickedGrp23Btn2();
	afx_msg void OnBnClickedGrp23Btn3();
	afx_msg void OnBnClickedGrp23Check();
	afx_msg void OnCbnSelchangeGrp23Com();

	afx_msg LRESULT OnPropertyChanged( WPARAM wParam ,LPARAM lParam );

	DECLARE_MESSAGE_MAP()

	virtual	void	TH_InitData();

	CListCtrl				m_ctlList;
	CComboBox				m_ctlCB;
	CMFCPropertyGridCtrl	m_ctlPG;

};
