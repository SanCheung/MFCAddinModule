#pragma once

#include "../THAddIn/THSDialog.h"

// UIScenePage3 �Ի���

class UIScene3Script : public THUI::THSDialog
{
	DECLARE_DYNAMIC(UIScene3Script)

public:
	UIScene3Script(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~UIScene3Script();

// �Ի�������
	enum { IDD = IDD_SCENE3_SCRIPT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	virtual	void	TH_InitData();
	virtual BOOL OnInitDialog();
};
