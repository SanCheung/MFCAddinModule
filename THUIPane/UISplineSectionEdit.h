#pragma once
#include "../THAddIn/THSDialog.h"

// UISplineSectionEdit 对话框

class UISplineSectionEdit : public THUI::THSDialog
{
	DECLARE_DYNAMIC(UISplineSectionEdit)

public:
	UISplineSectionEdit(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~UISplineSectionEdit();

// 对话框数据
	enum { IDD = IDD_SPLINE3_SECTION_EDIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	virtual	void	TH_InitData();
};
