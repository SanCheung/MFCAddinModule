#pragma once
#include "../THAddIn/THSDialog.h"

// UISplineSectionEdit �Ի���

class UISplineSectionEdit : public THUI::THSDialog
{
	DECLARE_DYNAMIC(UISplineSectionEdit)

public:
	UISplineSectionEdit(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~UISplineSectionEdit();

// �Ի�������
	enum { IDD = IDD_SPLINE3_SECTION_EDIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	virtual	void	TH_InitData();
};
