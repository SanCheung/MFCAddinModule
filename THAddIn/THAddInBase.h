#pragma once

#include "THSDialog.h"


typedef struct tag_AddInParameter
{
	// in 内部参数 
	// 插件的宿主窗口
	HWND	_hWndParent;

	// out 内部参数
	// 插件的窗口句柄
	THUI::THSDialog	*_pDlgOut;
} AddInParameter, *PAddInPara;



class THADDIN_DLL THAddInBase
{
public:
	THAddInBase(void);
	virtual ~THAddInBase(void);

	CString			m_strId;

	void			RegisterThis( const char *strId );
	virtual void	Create( void *pParam, int nLen ) = 0;

	friend class THAddInHost;
};



// 从THAddInDlgBase派生的插件，在.h中 直接使用这个宏声明即可
#define		DECLARE_ADDIN_CLASS( pluginId ) \
class CPlugin_##pluginId : public THAddInBase \
{ \
public: \
	CPlugin_##pluginId(void){ RegisterThis( #pluginId ); } \
	virtual ~CPlugin_##pluginId(void){} \
	\
	virtual void	Create( void *pParam, int nLen ); \
};



// 在.cpp中 直接使用这个宏
#define		IMPLEMENT_ADDIN_CLASS( pluginId, instName, pf ) \
CPlugin_##pluginId	instName; \
void CPlugin_##pluginId::Create( void *pParam, int nLen ) \
{ \
	AFX_MANAGE_STATE(AfxGetStaticModuleState()); \
	(*pf)( pParam, nLen ); \
} 


// 简化版本，直接在新建dll的*App.cpp中声明即可
#define		ADDIN_CLASS( pluginId, instName, pf ) \
DECLARE_ADDIN_CLASS( pluginId ) \
IMPLEMENT_ADDIN_CLASS( pluginId, instName, pf )

