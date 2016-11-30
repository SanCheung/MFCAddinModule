#pragma once
#include "../THAddIn/THSDialog.h"

// UIFeaturePointProperty 对话框

class UIFeaturePointProperty : public THUI::THSDialog
{
	DECLARE_DYNAMIC(UIFeaturePointProperty)

public:
	UIFeaturePointProperty(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~UIFeaturePointProperty();

// 对话框数据
	enum { IDD = IDD_FEATUREPOINT_PROPERTY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	virtual	void	TH_InitData();
};
