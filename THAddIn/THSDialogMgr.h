#pragma once

namespace THUI
{



class THSDialog;
class THADDIN_DLL THSDialogMgr
{
public:
	THSDialogMgr(void);
	virtual ~THSDialogMgr(void);

	// 模板添加子窗口
	template< typename T >
	T*	AddDialog( string str, HWND hWndParent )
	{
		T *p = THSDialog::AddSubDlg< T >( hWndParent );
		AddDialogIndirect( str, p );
		return p;
	}

	int				GetCount();
	THSDialog*		GetSubDialog( string str );

protected:
	vector< string >		m_asName;
	vector< THSDialog* >	m_arDlgs;

	void			AddDialogIndirect( string str, THSDialog *p );



	friend class THWDGroupSwitcher;
};



};

