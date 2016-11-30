#pragma once

#include "../THAddIn/THSDialog.h"

#include "resource.h"
// UIMeshSimulation �Ի���
class IUIDataExchange;

class UIMeshSimulation : public THUI::THSDialog
{
	DECLARE_DYNAMIC(UIMeshSimulation)

public:
	UIMeshSimulation(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~UIMeshSimulation();

// �Ի�������
	enum { IDD = IDD_MESH3_SIMULATION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	virtual	void TH_InitData();

	afx_msg void OnSelchangeGrp14Combo();

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_ctlCB;
	CMFCPropertyGridCtrl m_ctlPG;

};
