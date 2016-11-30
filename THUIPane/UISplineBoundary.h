#pragma once

#include "../THAddIn/THSDialog.h"

// UISplineBoundary 对话框

class UISplineBoundary : public THUI::THSDialog
{
	DECLARE_DYNAMIC(UISplineBoundary)

public:
	UISplineBoundary(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~UISplineBoundary();

// 对话框数据
	enum { IDD = IDD_SPLINE1_BOUNDARY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	virtual	void	TH_InitData();
};
