#pragma once

#include "../THAddIn/THSDialog.h"

#include "resource.h"
// UIMeshMaterial �Ի���

class IUIDataExchange;
class UIMeshMaterial : public THUI::THSDialog
{
	DECLARE_DYNAMIC(UIMeshMaterial)

public:
	UIMeshMaterial(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~UIMeshMaterial();

// �Ի�������
	enum { IDD = IDD_MESH2_MATERIAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

	virtual BOOL OnInitDialog();
	virtual	void	TH_InitData();

public:
	CMFCPropertyGridCtrl m_ctlPG;
};
