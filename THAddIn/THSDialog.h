////////////////////////////////////////////////////////////
// Copyright (c) 2015, hzzqh@foxmail.com
// All rights reserved.
// 
//
// 版本：1.1
// 描述：对话框基类，可以在构造的时候定义bModal参数，
//		自动创建模式窗口或非模式窗口
//
//      子窗口模式的调用次序：
//			先从THSmartDialog继承一个对话框
//			然后调用SubWindow_New(), 再对该对话框的纯数据进行初始化
//			最后调用SubWindow_Show(),显示该对话框
// 时间：2015年1月27日
// 作者：zhang Qinhua
////////////////////////////////////////////////////////////

#pragma once


#include <afxdialogex.h>

namespace THUI
{


class THWDGroupSwitcher;
class THADDIN_DLL THSDialog : public CDialogEx
{
// Construction
public:
	THSDialog( UINT id, BOOL bModal = TRUE );


// Dialog Data
	//{{AFX_DATA(CHJAutoDialog)
	//}}AFX_DATA
	
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHJAutoDialog)
	public:
		virtual void OnOK();
		virtual void OnCancel();
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CHJAutoDialog)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	virtual void PreSubclassWindow();
	virtual void PostNcDestroy();
	virtual BOOL OnInitDialog();


private:
	BOOL		m_bModal;

protected:
	THWDGroupSwitcher *m_pOwner;

public:
	CRect		m_rt;
	CString		m_strTitle;

public:
	template< typename T >
	static T* AddSubDlg( HWND hWndParent )
	{
		CWnd	*pWnd = CWnd::FromHandle( hWndParent );

		T *pDlg = new T;
		pDlg->Create( T::IDD, pWnd );

		CRect	rt = pDlg->m_rt;
		pDlg->MoveWindow( rt );
		//pDlg->ShowWindow( SW_SHOW );
		return pDlg;
	}

	void	SetGS( THWDGroupSwitcher *p );
	virtual void TH_InitData();
};




};