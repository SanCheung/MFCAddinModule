////////////////////////////////////////////////////////////
// Copyright (c) 2015, hzzqh@foxmail.com
// All rights reserved.
// 
//
// �汾��1.1
// �������Ի�����࣬�����ڹ����ʱ����bModal������
//		�Զ�����ģʽ���ڻ��ģʽ����
//
//      �Ӵ���ģʽ�ĵ��ô���
//			�ȴ�THSmartDialog�̳�һ���Ի���
//			Ȼ�����SubWindow_New(), �ٶԸöԻ���Ĵ����ݽ��г�ʼ��
//			������SubWindow_Show(),��ʾ�öԻ���
// ʱ�䣺2015��1��27��
// ���ߣ�zhang Qinhua
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