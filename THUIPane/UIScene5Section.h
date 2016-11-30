#pragma once
#include "../THAddIn/THSDialog.h"

// UIScenePage5 对话框

class UIScene5Section : public THUI::THSDialog
{
	DECLARE_DYNAMIC(UIScene5Section)

public:
	UIScene5Section(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~UIScene5Section();

// 对话框数据
	enum { IDD = IDD_SCENE5_SECTION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	virtual	void	TH_InitData();
	afx_msg void OnBnClickedGrp26Btn2();
};
