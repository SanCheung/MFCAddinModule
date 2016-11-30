#pragma once

//#include "THUIPaneLib.h"
#include "../THAddIn/THWDGroupSwitcher.h"
#include "../S3DCmdMgr/CmdMgrUnit.h"

// UIPropertyPane

class IUIDataExchange;
class THUIPANE_DLL UIPropertyPane	: public CDockablePane
									, public THUI::THWDGroupSwitcher
									, public JC::CmdMgrUnit
{
	DECLARE_DYNAMIC(UIPropertyPane)

public:
	UIPropertyPane();
	virtual ~UIPropertyPane();

	BOOL	dllCreate( LPCTSTR lpszCaption, HWND hWnd, const RECT& rect, BOOL bHasGripper,
						UINT nID, DWORD dwStyle );

	//void	RegisterPropertyExchange( IUIDataExchange *pPE );
	//IUIDataExchange* GetDataExchange(){ return m_pPE; }

	void	OnSelectMesh( int nMeshId );
	void	OnSelectScence();
	void	OnSelectSpline();


protected:
	DECLARE_MESSAGE_MAP()

	afx_msg void	OnPaint();
	afx_msg int		OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void	OnSize(UINT nType, int cx, int cy);
	afx_msg void	OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);

	//IUIDataExchange	*m_pPE;

	virtual bool	Run( const std::string &str, JC::JCmdBase &value );

	bool	RunShader( const std::string &str, JC::JCmdBase &value );
	bool	RunLight( const std::string &str, JC::JCmdBase &value );

private:
	int		m_nMeshId;


friend class UIMeshTexture;
};


