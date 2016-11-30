#pragma once
#include "TH_Singleton.h"

class THAddInBase;
class THAddInHost
{
public:
	THAddInHost(void);
	virtual ~THAddInHost(void);

public:
	void	Init();
	void	RegisterAddIn( THAddInBase *p );
	bool	CreateAddIn( CString strName, void *pParam );

	vector< THAddInBase* >		m_aoAddInDlgs;


private:
	vector< HINSTANCE >				m_arModule;
};


typedef TH_Singleton< THAddInHost >		gAddInHost;