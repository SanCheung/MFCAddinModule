#pragma once

#include "../THAddIn/THSDialog.h"

// UIScenePage3 对话框

class UIScene3Script : public THUI::THSDialog
{
	DECLARE_DYNAMIC(UIScene3Script)

public:
	UIScene3Script(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~UIScene3Script();

// 对话框数据
	enum { IDD = IDD_SCENE3_SCRIPT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	virtual	void	TH_InitData();
	virtual BOOL OnInitDialog();
};
