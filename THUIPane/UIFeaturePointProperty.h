#pragma once
#include "../THAddIn/THSDialog.h"

// UIFeaturePointProperty �Ի���

class UIFeaturePointProperty : public THUI::THSDialog
{
	DECLARE_DYNAMIC(UIFeaturePointProperty)

public:
	UIFeaturePointProperty(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~UIFeaturePointProperty();

// �Ի�������
	enum { IDD = IDD_FEATUREPOINT_PROPERTY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	virtual	void	TH_InitData();
};
