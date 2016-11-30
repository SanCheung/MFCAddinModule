#include "StdAfx.h"
#include "AddInMain.h"
#include "THAddInHost.h"

void THAddIn_init()
{
	gAddInHost::instance()->Init();
}

void THAddIn_release()
{
	gAddInHost::release();
}

THADDIN_DLL BOOL THAddIn_create( LPCTSTR strName, void *pPara )
{
	return gAddInHost::instance()->CreateAddIn( strName, pPara );
}
