// DialogContainer.cpp : 实现文件
//

#include "stdafx.h"
#include "resource.h"
#include "THWndDialogsGroup.h"
#include "THSDialog.h"
//#include "SubDlg1.h"
//#include "SubDlg2.h"
//#include "SubDlg3.h"
//#include "SubDlg4.h"
//
//#include "MainFrm.h"


namespace THUI
{


#define		DCWNDCLASSNAME			_T("DCWnd_WindowClass")


// CDialogContainer

IMPLEMENT_DYNAMIC(THWndDialogsGroup, CWnd)

BOOL THWndDialogsGroup::RegisterWindowClass()
{
	WNDCLASS	wc = {0};
	HINSTANCE	hInstance = AfxGetInstanceHandle();   

	if( !(::GetClassInfo(hInstance, DCWNDCLASSNAME, &wc)))   
	{                
		wc.style = CS_DBLCLKS;   
		wc.lpfnWndProc	= ::DefWindowProc;   
		wc.hInstance	= hInstance;   
		wc.hCursor		= AfxGetApp()->LoadStandardCursor(IDC_ARROW);   
		wc.hbrBackground = ::CreateSolidBrush( RGB(200,200,255) );  
		wc.lpszClassName = DCWNDCLASSNAME;   

		if( !AfxRegisterClass( &wc ) )   
		{   
			AfxThrowResourceException();   
			return FALSE;   
		}   
	}   

	return TRUE; 
}

THWndDialogsGroup::THWndDialogsGroup( CString strName )
	: m_nContentHeight( 0 )
	, m_nPage( 0 )
	, m_yOffset( 0 )
	, m_strName( strName )
	, m_pOwner( NULL )
{
	RegisterWindowClass();
}

THWndDialogsGroup::~THWndDialogsGroup()
{
}


BEGIN_MESSAGE_MAP(THWndDialogsGroup, CWnd)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_NCDESTROY()
	ON_WM_SIZE()
	ON_WM_VSCROLL()
	ON_WM_MOUSEWHEEL()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()



void THWndDialogsGroup::AppendDialog( string str, THSDialog *p )
{
	AddDialogIndirect( str, p );

	m_arDlgs.back()->SetGS( m_pOwner );
	m_abExpand.push_back( true );

	CRect		rt;
	GetClientRect( rt );
	int		cy = rt.Height();

	RecalContentHeight();
	AdjustLayout();

}


void THWndDialogsGroup::ResetAll()
{
	int		i;
	int		n = GetCount();
	m_abExpand.resize( n );
	for( i = 0; i < n; i++ )
		m_abExpand[i] = true;

	n = (int)m_arDlgs.size();
	for( i = 0; i < n; i++ )
	{
		THSDialog *pDlg = m_arDlgs[i];
		pDlg->SetGS( m_pOwner );
	}

	CRect		rt;
	GetClientRect( rt );
	int		cy = rt.Height();

	RecalContentHeight();
	AdjustLayout();
}

int THWndDialogsGroup::OnCreate( LPCREATESTRUCT lpCreateStruct )
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	InitSubDialogs();

	ResetAll();
	return 0;
}


BOOL THWndDialogsGroup::WndCreate(  const RECT& rect, CWnd* pParentWnd, UINT nID )
{
	return Create( DCWNDCLASSNAME, _T(""), WS_VISIBLE|WS_CHILD|WS_CLIPCHILDREN|WS_CLIPSIBLINGS|WS_VSCROLL, rect, pParentWnd, nID );
}

void THWndDialogsGroup::RecalContentHeight()
{
	int		nHeight = 0;

	int		i = 0;
	int		n = (int)m_arDlgs.size();
	for( i = 0; i < n; i++ )
	{
		THSDialog *pDlg = m_arDlgs[i];

		// expand tab;
		nHeight += 20;

		// 
		bool	bExpand = m_abExpand[i];
		if( bExpand )
		{
			int		nWindowHeight = pDlg->m_rt.Height();

			// reset sub dialog Rect;
			CRect	rt = pDlg->m_rt;
			rt.top = nHeight;
			rt.bottom = rt.top + nWindowHeight;
			pDlg->m_rt = rt;


			nHeight += nWindowHeight;
		}
	}

	nHeight += 10;
	m_nContentHeight = nHeight;
}




// CDialogContainer 消息处理程序
void THWndDialogsGroup::OnPaint()
{
	CPaintDC	dc(this);

	CRect		rt;
	GetClientRect( &rt );

	//dc.FillSolidRect( rt, RGB(200,200,255) );
	dc.FillSolidRect( rt, GetSysColor(COLOR_BTNFACE) );
	//dc.FillSolidRect( rt, RGB(255,255,255) );

	dc.SetWindowOrg( 0, -m_yOffset );

	CRect		rtBar = rt;
	rt.DeflateRect( 10, 0 );
	int			nHeight = 0;

	dc.SetBkMode( TRANSPARENT );

	int			n = GetCount();
	for( int i = 0; i < n; ++i )
	{
		THSDialog *p = m_arDlgs[i];

		CString		str = p->m_strTitle;
		if( str.IsEmpty() )
			str = m_asName[i].c_str();

		rtBar.top = nHeight;
		rtBar.bottom = nHeight + 20;

		CRect		rtPad = rtBar;
		rtPad.DeflateRect( 2, 2 );
		dc.FillRect( rtPad, &CBrush(RGB(200,200,200)));

		CRect	rt1 = rtBar;
		rt1.right = rt1.left + rt1.Height();
		DrawTriangle( &dc, rt1, m_abExpand[i]?1:0 );

		CFont	font;
		font.CreateFont( -12, 0, 1, 1, 500, 0, 0, 0, 0, 0, 0, 0, 0, _T("Microsoft Yahei") );
		CFont	*pOldFont = dc.SelectObject( &font );
		dc.TextOut( rtBar.left+ 20, rtBar.top+2, str );
		dc.SelectObject( pOldFont );

		//// draw hot
		//CRect	rtHot = rtBar;
		//rtHot.DeflateRect( 2, 2 );

		//CBrush *pOldBr = (CBrush *)dc.SelectStockObject( NULL_BRUSH );
		//dc.Rectangle( rtHot );
		//dc.SelectObject( pOldBr );
		

		rtPad = rtBar;
		rtPad.DeflateRect( 1, 1 );
		int nSavedDC = dc.SaveDC();
		dc.Draw3dRect( rtPad, RGB(255,255,255), RGB(128,128,128) );
		dc.RestoreDC( nSavedDC );

		nHeight += 20;
		if( m_abExpand[i] )
			nHeight += p->m_rt.Height();
	}

	//if( m_nMaxHeight < rt.Height() )
	//{
	//	rt.InflateRect( 10, 0 );
	//	CRect	rtBlank = rt;
	//	rtBlank.top = m_nMaxHeight;

	//	dc.FillRect( rtBlank, &CBrush(RGB(255,255,255)) );
	//}
}

void THWndDialogsGroup::DrawTriangle( CDC *pDC, CRect rt, int nType )
{
	CFont	font;

	int ppi = pDC->GetDeviceCaps(LOGPIXELSX);
	//int pointsize = MulDiv(60, 96, ppi); // 6 points at 96 ppi
	int pointsize = MulDiv(140, 96, ppi); // 6 points at 96 ppi
	font.CreatePointFont(pointsize, _T("Marlett"));
	CFont* oldfont = pDC->SelectObject(&font);

	CPoint pt = rt.TopLeft();

	if( 0 == nType )
		pDC->TextOut( pt.x, pt.y+2, _T("4") );
	else
		pDC->TextOutA( pt.x, pt.y, _T("6") );

	pDC->SelectObject(oldfont);
}


BOOL THWndDialogsGroup::PreTranslateMessage(MSG* pMsg)
{
	if( ::IsDialogMessage( m_hWnd, pMsg ) )
		return TRUE;

	return CWnd::PreTranslateMessage(pMsg);
}

void THWndDialogsGroup::OnNcDestroy()
{
	CWnd::OnNcDestroy();
	delete this;
}


void THWndDialogsGroup::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);
	AdjustLayout();
}


void THWndDialogsGroup::AdjustSubDialogs()
{
	if( m_arDlgs.size() != m_abExpand.size() )
		return;

	CRect	rtMain;
	GetClientRect( rtMain );

	int		i = 0;
	int		n = (int)m_arDlgs.size();
	for( i = 0; i < n; i++ )
	{
		THSDialog *pDlg = m_arDlgs[i];

		bool	bExpand = m_abExpand[i];
		pDlg->ShowWindow( bExpand ? SW_SHOW : SW_HIDE );

		if( bExpand )
		{
			CRect	rt = pDlg->m_rt;
			rt.OffsetRect( 0, m_yOffset );

			rt.right = rtMain.right;
			pDlg->MoveWindow( rt );
		}
	}
}

void THWndDialogsGroup::RecalcScroll( int cy )
{
	SCROLLINFO		si1 = {0};
	si1.cbSize = sizeof( SCROLLINFO );
	si1.fMask = SIF_ALL;
	GetScrollInfo( SB_VERT, &si1 );

	m_nPage = cy;
	
	SCROLLINFO		si = {0};
	si.cbSize = sizeof( SCROLLINFO );
	si.fMask	= SIF_RANGE|SIF_PAGE;
	si.nMin		= 0;
	si.nMax		= m_nContentHeight;
	si.nPage	= m_nPage;
	SetScrollInfo( SB_VERT, &si );

	if( m_nContentHeight == 0 )
		return;

	//CString		str;
	//str.Format( "%d  %d ----> %d  %d\n", si1.nMax, si1.nPage, m_nMaxHeight, m_nPage );
	//CMainFrame *pMF = (CMainFrame *)AfxGetMainWnd();
	//if( NULL != pMF && ::IsWindow( pMF->m_hWnd ) )
	//	pMF->Output( str );

	int nMax = m_nContentHeight - m_nPage;
	if( nMax < 0 )
		m_yOffset = 0;
	else
	{
		if( -m_yOffset > nMax )
			m_yOffset = -nMax;
	}

	//m_yOffset = 0;

	si.fMask	= SIF_POS;
	si.nPos		= -m_yOffset;
	SetScrollInfo( SB_VERT, &si );
}


void THWndDialogsGroup::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	if( m_nContentHeight <= m_nPage )
	{
		__super::OnVScroll(nSBCode, nPos, pScrollBar);
		return;
	}

	int nOldPos = GetScrollPos( SB_VERT );
	int	nNewPos = nOldPos;

	switch( nSBCode )
	{
	case SB_BOTTOM:
		nNewPos = m_nContentHeight;
		break;
	case SB_ENDSCROLL:
		break;
	case SB_LINEDOWN:
		nNewPos += int(m_nContentHeight/100.f);
		break;
	case SB_LINEUP:
		nNewPos -= int(m_nContentHeight/100.f);
		break;
	case SB_PAGEDOWN:
		nNewPos += m_nPage;
		break;
	case SB_PAGEUP:
		nNewPos -= m_nPage;
		break;
	case SB_THUMBPOSITION:
		nNewPos = nPos;
		break;
	case SB_THUMBTRACK:
		nNewPos = nPos;
		break;
	case SB_TOP:
		nNewPos = 0;
		break;
	}

	//CString		str;
	//str.Format( "%d %d    %d\n", m_nMaxHeight, m_nPage, nNewPos );
	//CMainFrame *pMF = (CMainFrame *)AfxGetMainWnd();
	//pMF->Output( str );

	if( nNewPos > m_nContentHeight - m_nPage )
		nNewPos = m_nContentHeight - m_nPage;

	if( nNewPos < 0 )
		nNewPos = 0;

	if( nNewPos == nOldPos )
	{
		__super::OnVScroll(nSBCode, nPos, pScrollBar);
		return;
	}

	SCROLLINFO		si = {0};
	si.cbSize = sizeof( SCROLLINFO );
	si.fMask = SIF_POS;
	si.nPos = nNewPos;
	SetScrollInfo( SB_VERT, &si );
	ScrollWindow( 0, nOldPos-nNewPos );
	m_yOffset += nOldPos-nNewPos;
	Invalidate();

	__super::OnVScroll(nSBCode, nPos, pScrollBar);
}


BOOL THWndDialogsGroup::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	const int nSteps = abs(zDelta) / WHEEL_DELTA;
	for (int i = 0; i < nSteps; i++)
	{
		OnVScroll(zDelta < 0 ? SB_LINEDOWN : SB_LINEUP, 0, NULL);
	}

	return __super::OnMouseWheel(nFlags, zDelta, pt);
}


void THWndDialogsGroup::OnLButtonUp(UINT nFlags, CPoint point)
{
	CPoint		pt = point;
	pt.Offset( 0, -m_yOffset );
	
	CRect		rt;
	GetClientRect( rt );

	CRect		rtBar = rt;
	rt.DeflateRect( 10, 0 );
	int			nHeight = 0;

	int			n = GetCount();
	for( int i = 0; i < n; ++i )
	{
		THSDialog *p = m_arDlgs[i];

		rtBar.top = nHeight;
		rtBar.bottom = nHeight + 20;

		CRect	rtHot = rtBar;
		rtHot.DeflateRect( 2, 2 );
		if( rtHot.PtInRect( pt ) )
		{
			m_abExpand[i] = !m_abExpand[i];

			RecalContentHeight();
			AdjustLayout();

			__super::OnLButtonUp(nFlags, point);
			return;
		}

		nHeight += 20;	
		if( m_abExpand[i] )
			nHeight += p->m_rt.Height();
	}

	__super::OnLButtonUp(nFlags, point);
}

void THWndDialogsGroup::AdjustLayout()
{
	CRect		rt;
	GetClientRect( rt );

	RecalcScroll( rt.Height() );
	AdjustSubDialogs();
	Invalidate();
}

void THWndDialogsGroup::InitSubDialogs()
{
	//AddDialog<CSubDlg1>( _T("全局渲染"), this );
	//AddDialog<CSubDlg2>( _T("光源"), this );
	//AddDialog<CSubDlg3>( _T("脚本"), this );
	//AddDialog<CSubDlg4>( _T("模拟纸样"), this );
}

void THWndDialogsGroup::SetGS( THWDGroupSwitcher *p )
{
	m_pOwner = p;
}

void THWndDialogsGroup::OnSwitch()
{
	int			n = GetCount();
	for( int i = 0; i < n; ++i )
	{
		THSDialog *p = m_arDlgs[i];
		p->TH_InitData();
	}
}


};