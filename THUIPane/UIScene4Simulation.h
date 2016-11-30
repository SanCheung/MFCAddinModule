#pragma once

#include "../THAddIn/THSDialog.h"

// UIScenePage4 �Ի���

class UIScene4Simulation : public THUI::THSDialog
{
	DECLARE_DYNAMIC(UIScene4Simulation)

public:
	UIScene4Simulation(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~UIScene4Simulation();

// �Ի�������
	enum { IDD = IDD_SCENE4_SIMULATION };


	void UISelectAll( int nSelect );
	void UISimulateInit();
	void UISimulateStart();
	void UISimulateStop();
	void UISimulateSwitch( bool bPause );



protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual	void	TH_InitData();
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

	afx_msg void OnBnClickedGrp25Btn1();
	afx_msg void OnBnClickedGrp25Btn2();
	afx_msg void OnBnClickedGrp25Btn3();
	afx_msg void OnBnClickedGrp25Btn4();
	afx_msg void OnBnClickedGrp25Btn5();
	afx_msg void OnBnClickedGrp25Btn6();

	CListCtrl m_ctlList;
	CButton m_ctlBtnInit;
	CButton m_ctlBtnStart;
	CButton m_ctlBtnSwitch;
	CButton m_ctlBtnStop;

	bool m_bPause;
};
