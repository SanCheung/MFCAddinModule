#pragma once

#include "../THAddIn/THSDialog.h"

#include "resource.h"
// UIMeshSimulation 对话框
class IUIDataExchange;

class UIMeshSimulation : public THUI::THSDialog
{
	DECLARE_DYNAMIC(UIMeshSimulation)

public:
	UIMeshSimulation(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~UIMeshSimulation();

// 对话框数据
	enum { IDD = IDD_MESH3_SIMULATION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	virtual	void TH_InitData();

	afx_msg void OnSelchangeGrp14Combo();

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_ctlCB;
	CMFCPropertyGridCtrl m_ctlPG;

};
