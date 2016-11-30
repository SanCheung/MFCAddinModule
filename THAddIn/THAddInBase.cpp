#include "StdAfx.h"
#include "THAddInBase.h"
#include "THAddInHost.h"


THAddInBase::THAddInBase(void)
{
}


THAddInBase::~THAddInBase(void)
{
}

void THAddInBase::RegisterThis( const char *strId )
{
	m_strId = strId;
	gAddInHost::instance()->RegisterAddIn( this );
}
