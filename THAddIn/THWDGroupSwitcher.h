#pragma once

namespace THUI
{


class THSDialog;
class THWndDialogsGroup;
class THADDIN_DLL THWDGroupSwitcher
{
public:
	THWDGroupSwitcher(void);
	virtual ~THWDGroupSwitcher(void);

	bool	AddGroup( const CRect &rt, CWnd *pWndParent, UINT id, THWndDialogsGroup *pGroup );
	void	SwitchTo( int nIndex );
	THSDialog*				GetDialog( int nIndex, int nSubIndex );
	THWndDialogsGroup*		GetGroup( int nIndex );

	int		GetCurSel()	{ return m_nCurSel; }

protected:
	void	DoSize();


private:
	vector< THWndDialogsGroup* >	m_arGroup;
	CWnd		*m_pWndHost;

	int			m_nCurSel;
};


};

