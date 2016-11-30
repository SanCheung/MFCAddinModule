#pragma once

class THUIPANE_DLL IUIDataExchange
{
public:
	IUIDataExchange();
	virtual ~IUIDataExchange();

public:
	// Shader
	virtual void	ShaderDataToUI( CListBox &ctlLB, CButton &ctlBn ) = 0;
	virtual	int		Shader_getInitData( vector< CString > &asProgram, bool &bUsingBodyGLOs ) = 0;
	virtual bool	Shader_getItem( int nIndex, CString &strFragment, CString &strVertax ) = 0;
	virtual void	ShaderEnable_beingused( bool bEnable ) = 0;
	virtual void	ShaderEnable_usingshader( bool bEnable ) = 0;
	virtual void	ShaderEnable_usingBodyGLOs( bool bEnable ) = 0;
	virtual void	Shader_load() = 0;
	virtual CString	Shader_new() = 0;
	virtual void	Shader_delete( int nIndex ) = 0;
	virtual void	Shader_setItem( int nIndex, int nDataId, CString strName, CString strValue ) = 0;

	// Light
	virtual int		Light_getInitData( vector< CString> &asName, vector<CString> &asMode, vector<CString> &asEnable ) = 0;


};

