#pragma once
#include "../THAddIn/THSDialog.h"

// UIScenePage5 �Ի���

class UIScene5Section : public THUI::THSDialog
{
	DECLARE_DYNAMIC(UIScene5Section)

public:
	UIScene5Section(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~UIScene5Section();

// �Ի�������
	enum { IDD = IDD_SCENE5_SECTION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	virtual	void	TH_InitData();
	afx_msg void OnBnClickedGrp26Btn2();
};
