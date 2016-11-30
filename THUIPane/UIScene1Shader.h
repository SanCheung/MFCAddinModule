#pragma once

#include "../THAddIn/THSDialog.h"
#include "afxwin.h"
#include "afxpropertygridctrl.h"

// UIScenePage1 对话框

class IUIDataExchange;
class UIScene1Shader : public THUI::THSDialog
{
	DECLARE_DYNAMIC(UIScene1Shader)

public:
	UIScene1Shader(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~UIScene1Shader();

// 对话框数据
	enum { IDD = IDD_SCENE1_SHADER };

	// 给外部调用的UI改变函数
	void		UISetCtrlEnable( UINT uId, bool bEnable );
	void		UIAddProgram( string strProgram );
	void		UIDelProgram( int nIndex );

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeList();
	afx_msg void OnBnClickedGrp22Check2();
	afx_msg void OnBnClickedGrp22Check3();
	afx_msg void OnBnClickedGrp22Check();
	afx_msg void OnBnClickedGrp22Btn5();
	afx_msg void OnBnClickedGrp22Btn6();
	afx_msg void OnBnClickedGrp22Btn7();

	afx_msg LRESULT OnPropertyChanged(WPARAM wParam ,LPARAM lParam);

	DECLARE_MESSAGE_MAP()

	//IUIDataExchange *GetDataExchange();

	CListBox				m_ctlLB;
	CMFCPropertyGridCtrl	m_ctlPG;
	CComboBox				m_ctlCB;
	CButton					m_ctlBnCheck;

	CString			m_strFragmentPath;
	CString			m_strVertexPath;
	
	virtual	void	TH_InitData();

};
