#pragma once

#include "../THAddIn/THSDialog.h"
#include "afxwin.h"
#include "afxpropertygridctrl.h"
#include <vector>
#include <tuple>
#include "resource.h"

#include "ImageStatic.h"
// UIMeshPage1 对话框

//class UITexColorInfo
//{
//public:
//	UITexColorInfo()
//	{
//		fBrightness = 0.0f;
//		fContrast = 1.0f;
//		fHue = 0.0f;
//		fSaturation = 0.0f;
//		fGamma = 1.0f;
//	}
//
//	float fBrightness;//亮度
//	float fContrast;//对比度
//	float fHue;//色调
//	float fSaturation;//饱和度
//	float fGamma;//伽马值
//};

class IUIDataExchange;
class UIMeshTexture : public THUI::THSDialog
{
	//typedef tuple< CString, CString, CString, CString > TEX_PATH_TYPE;
	//typedef tuple< UITexColorInfo, UITexColorInfo, UITexColorInfo, UITexColorInfo > TEX_COLORINFO_TYPE;

	DECLARE_DYNAMIC(UIMeshTexture)

public:
	UIMeshTexture(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~UIMeshTexture();

// 对话框数据
	enum { IDD = IDD_MESH1_TEXTURE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual	void TH_InitData();
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

	afx_msg void OnBnClickedRadio_Texture0();
	afx_msg void OnBnClickedRadio_Texture1();
	afx_msg void OnBnClickedRadio_Texture2();
	afx_msg void OnBnClickedRadio_Texture3();
	afx_msg void OnBnClickedBtn10();
	afx_msg void OnBnClickedBtn1();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);

	afx_msg void OnBnClickedGrp11Check1();
	afx_msg void OnBnClickedGrp11Check2();
	afx_msg void OnBnClickedGrp11Check3();
	afx_msg void OnBnClickedGrp11Btn11();
	afx_msg void OnBnClickedGrp11Btn2();
	afx_msg void OnBnClickedGrp11Btn9();
	afx_msg void OnBnClickedGrp11Btn12();
	afx_msg void OnBnClickedGrp11Btn13();
	afx_msg void OnBnClickedGrp11Btn14();
	afx_msg void OnBnClickedGrp11Btn15();
	afx_msg void OnBnClickedGrp11Btn3();
	afx_msg void OnBnClickedGrp11Btn7();
	afx_msg void OnBnClickedGrp11Btn6();
	afx_msg void OnBnClickedGrp11Btn5();

	//void GetDefaultTexturePath();


    //纹理参数
	//vector< TEX_PATH_TYPE > m_tex_paths;  //纹理路径
	//vector< TEX_COLORINFO_TYPE > m_tex_colorInfos;

private:
	int			m_nTextureIndex;
	CString		m_strPathDefault;

	CString		m_strTexture;
	CImageStatic m_stPreview;

	int			m_nBrightness;
	int			m_nContrast;
	int			m_nHue;
	int			m_nSaturation;
	int 		m_nGamma;

	float		m_fBrightness;
	float		m_fContrast;
	float		m_fHue;
	float		m_fSaturation;
	float		m_fGamma;

	CSliderCtrl m_ctlSd1;
	CSliderCtrl m_ctlSd2;
	CSliderCtrl m_ctlSd3;
	CSliderCtrl m_ctlSd4;
	CSliderCtrl m_ctlSd5;

	double		m_dX;
	double		m_dY;
	double		m_dRotate;
	double		m_dScale;

	BOOL		m_bEditMode;
	BOOL		m_bFlagMode;
	BOOL		m_bAlphaMode;


public:
	// 界面相关
	void	UISelectTexture( int nIndex, CString strPath, double av[9], bool bRefreshUI = true );

private:
	void	DoSelectTexture( int nIndex, bool bRefreshUI = true );
	void	Float2IntValue();
	void	ChangeMatrix();


};
