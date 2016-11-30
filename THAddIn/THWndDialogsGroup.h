#pragma once

#include "THSDialogMgr.h"


namespace THUI
{


// CWndDialogsGroup
class THWDGroupSwitcher;
class THADDIN_DLL THWndDialogsGroup : public CWnd
									, public THSDialogMgr
{
	DECLARE_DYNAMIC(THWndDialogsGroup)

public:
	THWndDialogsGroup( CString strName );
	virtual ~THWndDialogsGroup();

	BOOL	WndCreate( const RECT& rect, CWnd* pParentWnd, UINT nID );
	void	AdjustLayout();

	void	ResetAll();

	// 外部追加新的子窗口
	void	AppendDialog( string str, THSDialog *p );

	virtual void	InitSubDialogs();

	CString		m_strName;

protected:
	DECLARE_MESSAGE_MAP()

private:
	BOOL	RegisterWindowClass();

	void	RecalContentHeight();
	void	RecalcScroll( int cy );
	void	AdjustSubDialogs();

	void	DrawTriangle( CDC *pDC, CRect rt, int nType );


public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnNcDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);

	virtual BOOL PreTranslateMessage(MSG* pMsg);


	//template< typename T >
	//void	AddSubDialog( int nTop, string str, CWnd *pWnd )
	//{
	//	T *p = THSDialog::SubWindow_New< T >();
	//	THSDialog::SubWindow_Show< T >( p, pWnd, CPoint(0, nTop) );
	//}

private:
	int		m_nContentHeight;
	int		m_nPage;

	int		m_yOffset;

	vector< bool >		m_abExpand;
	THWDGroupSwitcher	*m_pOwner;

public:
	void	SetGS( THWDGroupSwitcher *p );
	virtual void OnSwitch();
};


};