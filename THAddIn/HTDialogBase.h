#pragma once

#include "THAddInLib.h"
// HTDialogBase �Ի���
// ����dll����֮�ã���ʵ����;

class THADDIN_DLL HTDialogBase : public CDialogEx
{
	DECLARE_DYNAMIC(HTDialogBase)

public:
	HTDialogBase(CWnd* pParent = NULL);   // ��׼���캯��
	HTDialogBase( UINT nIDTemplate, CWnd* pParent );
	virtual ~HTDialogBase();
	virtual BOOL OnInitDialog();


// �Ի�������
	enum { IDD = IDD_DIALOG1 };


	static void	work();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()


	COLORREF		m_crBackColor;
	
};
