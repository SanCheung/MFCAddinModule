#pragma once

#include "THAddInLib.h"
// HTDialogBase 对话框
// 测试dll调用之用，无实际用途

class THADDIN_DLL HTDialogBase : public CDialogEx
{
	DECLARE_DYNAMIC(HTDialogBase)

public:
	HTDialogBase(CWnd* pParent = NULL);   // 标准构造函数
	HTDialogBase( UINT nIDTemplate, CWnd* pParent );
	virtual ~HTDialogBase();
	virtual BOOL OnInitDialog();


// 对话框数据
	enum { IDD = IDD_DIALOG1 };


	static void	work();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()


	COLORREF		m_crBackColor;
	
};
