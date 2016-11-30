#pragma once

#include "..\bcls\definition.h"
#include "..\bcls\PixelImage.h"


// CImageStatic

class CImageStatic : public CStatic
{
	DECLARE_DYNAMIC(CImageStatic)

public:
	CImageStatic();
	virtual ~CImageStatic();

	void	SetImageFile( CString strFile );
	void	ImageProcess( float fBrightness, float fContrast, float fHue, float fSaturation, float fGamma );
	
	void	ProcessBrightness( float f );
	void	ProcessContrast( float f );
	void	ProcessHue( float f );
	void	ProcessSaturation( float f );
	void	ProcessGamma( float f );

protected:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();

	void	DrawImagePixel( CDC *pDC, bcls::CImagePixel * pImage );

	bcls::CImagePixel		m_image;
	bcls::CImagePixel		m_imageProcessed;
};


