#pragma once

#include "../THAddIn/THSDialog.h"

// UISplineType �Ի���

class UISplineType : public THUI::THSDialog
{
	DECLARE_DYNAMIC(UISplineType)

public:
	UISplineType(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~UISplineType();

// �Ի�������
	enum { IDD = IDD_SPLINE2_TYPE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	virtual	void	TH_InitData();
};
