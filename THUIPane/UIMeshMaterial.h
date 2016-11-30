#pragma once

#include "../THAddIn/THSDialog.h"

#include "resource.h"
// UIMeshMaterial 对话框

class IUIDataExchange;
class UIMeshMaterial : public THUI::THSDialog
{
	DECLARE_DYNAMIC(UIMeshMaterial)

public:
	UIMeshMaterial(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~UIMeshMaterial();

// 对话框数据
	enum { IDD = IDD_MESH2_MATERIAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

	virtual BOOL OnInitDialog();
	virtual	void	TH_InitData();

public:
	CMFCPropertyGridCtrl m_ctlPG;
};
