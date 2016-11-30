#pragma once

#include "../THAddIn/THSDialog.h"

// UISplineType 对话框

class UISplineType : public THUI::THSDialog
{
	DECLARE_DYNAMIC(UISplineType)

public:
	UISplineType(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~UISplineType();

// 对话框数据
	enum { IDD = IDD_SPLINE2_TYPE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	virtual	void	TH_InitData();
};
