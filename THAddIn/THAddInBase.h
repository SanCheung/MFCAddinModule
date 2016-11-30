#pragma once

#include "THSDialog.h"


typedef struct tag_AddInParameter
{
	// in �ڲ����� 
	// �������������
	HWND	_hWndParent;

	// out �ڲ�����
	// ����Ĵ��ھ��
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



// ��THAddInDlgBase�����Ĳ������.h�� ֱ��ʹ���������������
#define		DECLARE_ADDIN_CLASS( pluginId ) \
class CPlugin_##pluginId : public THAddInBase \
{ \
public: \
	CPlugin_##pluginId(void){ RegisterThis( #pluginId ); } \
	virtual ~CPlugin_##pluginId(void){} \
	\
	virtual void	Create( void *pParam, int nLen ); \
};



// ��.cpp�� ֱ��ʹ�������
#define		IMPLEMENT_ADDIN_CLASS( pluginId, instName, pf ) \
CPlugin_##pluginId	instName; \
void CPlugin_##pluginId::Create( void *pParam, int nLen ) \
{ \
	AFX_MANAGE_STATE(AfxGetStaticModuleState()); \
	(*pf)( pParam, nLen ); \
} 


// �򻯰汾��ֱ�����½�dll��*App.cpp����������
#define		ADDIN_CLASS( pluginId, instName, pf ) \
DECLARE_ADDIN_CLASS( pluginId ) \
IMPLEMENT_ADDIN_CLASS( pluginId, instName, pf )

