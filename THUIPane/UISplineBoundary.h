#pragma once

#include "../THAddIn/THSDialog.h"

// UISplineBoundary �Ի���

class UISplineBoundary : public THUI::THSDialog
{
	DECLARE_DYNAMIC(UISplineBoundary)

public:
	UISplineBoundary(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~UISplineBoundary();

// �Ի�������
	enum { IDD = IDD_SPLINE1_BOUNDARY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	virtual	void	TH_InitData();
};
