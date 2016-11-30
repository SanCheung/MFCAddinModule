// ImageStatic.cpp : 实现文件
//

#include "stdafx.h"
#include <io.h>
#include "ImageStatic.h"

#include "..\bcls\ImageIO\bmpImage.h"
#include "..\bcls\FileStream.h"


// CImageStatic

IMPLEMENT_DYNAMIC(CImageStatic, CStatic)

CImageStatic::CImageStatic()
{

}

CImageStatic::~CImageStatic()
{
}


BEGIN_MESSAGE_MAP(CImageStatic, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CImageStatic 消息处理程序




void CImageStatic::OnPaint()
{
	CPaintDC	dc(this);

	if( m_imageProcessed.Width() == 0 )
	{
		CRect		rt;
		GetClientRect( rt );
		dc.FillRect( &rt, &CBrush(RGB(255,255,255)) );

		CFont		font;
		font.CreateFont( -12, 0, 0, 0, 500, 0, 0, 0, 0, 0, 0, 0, 0, "Microsoft Yahei" );

		CFont		*pOldFont = dc.SelectObject( &font );
		dc.SetTextColor( RGB(64,64,64) );

		CString		str = "没有图片";
		dc.DrawText( str, str.GetLength(), &rt, DT_CENTER|DT_VCENTER|DT_SINGLELINE );

		dc.SelectObject( pOldFont );
	}
	


	DrawImagePixel( &dc, &m_imageProcessed );
}

void CImageStatic::SetImageFile( CString strFile )
{
	m_image.Clear();
	m_imageProcessed.Clear();

	if( !strFile.IsEmpty() && !_access( strFile, 0 ) )
	{
		bcls::BMPImage		loader( m_image );
		bcls::CStreamFile	file( strFile.GetBuffer(0), bcls::CStreamFile::READ );
		strFile.ReleaseBuffer();

		bool ret = loader.Read( file );
		file.close();
		
		m_imageProcessed = m_image;
	}

	Invalidate( FALSE );
}

void CImageStatic::DrawImagePixel( CDC *pDC, bcls::CImagePixel * pImage )
{
	CRect		rt;
	GetClientRect( &rt );

	unsigned char buffer[sizeof(BITMAPINFOHEADER) + 1024];
	BITMAPINFO* bmi = (BITMAPINFO*)buffer;
	int bmpw = pImage->Width();
	int bmph = pImage->Height();

	BITMAPINFOHEADER* bmih = &(bmi->bmiHeader);
	memset( bmih, 0, sizeof(*bmih));
	bmih->biSize = sizeof(BITMAPINFOHEADER);
	bmih->biWidth = bmpw;
	bmih->biHeight = -bmph;
	bmih->biPlanes = 1;
	bmih->biBitCount = 32;
	bmih->biCompression = BI_RGB;

	if( rt.Width() < bmpw )
		SetStretchBltMode( pDC->m_hDC, HALFTONE );
	else
		SetStretchBltMode( pDC->m_hDC, COLORONCOLOR );

	BYTE* pBuffer = (BYTE*)pImage->GetBuffer();
	::StretchDIBits(
		pDC->m_hDC, rt.left, rt.top, rt.Width(), rt.Height(), 0, 0, bmpw, bmph, pBuffer, bmi, DIB_RGB_COLORS, SRCCOPY );
}

void CImageStatic::ImageProcess( float fBrightness, float fContrast, float fHue, float fSaturation, float fGamma )
{
	m_imageProcessed.Clear();

	bcls::CImagePixel::Adjust_bright( m_image, m_imageProcessed, fBrightness);
	bcls::CImagePixel::Adjust_alpha( m_imageProcessed, m_imageProcessed, fContrast);
	bcls::CImagePixel::Adjust_hue( m_imageProcessed, m_imageProcessed, fHue);
	bcls::CImagePixel::Adjust_Saturation( m_imageProcessed, m_imageProcessed, fSaturation);
	bcls::CImagePixel::Adjust_gamma( m_imageProcessed, m_imageProcessed, fGamma);

	Invalidate( FALSE );
}

void CImageStatic::ProcessBrightness( float f )
{
	static float sf = 0;
	if( abs( sf - f ) < 1.f )
		return;

	sf = f;
	bcls::CImagePixel::Adjust_bright( m_image, m_imageProcessed, f );
	Invalidate( FALSE );
}

void CImageStatic::ProcessContrast( float f )
{
	static float sf = 0;
	if( abs( sf - f ) < .01f )
		return;
	sf = f;

	bcls::CImagePixel::Adjust_alpha( m_image, m_imageProcessed, f );
	Invalidate( FALSE );
}

void CImageStatic::ProcessHue( float f )
{
	static float sf = 0;
	if( abs( sf - f ) < .01f )
		return;
	sf = f;

	bcls::CImagePixel::Adjust_hue( m_image, m_imageProcessed, f );
	Invalidate( FALSE );
}

void CImageStatic::ProcessSaturation( float f )
{
	bcls::CImagePixel::Adjust_Saturation( m_image, m_imageProcessed, f );
	Invalidate( FALSE );
}

void CImageStatic::ProcessGamma( float f )
{
	bcls::CImagePixel::Adjust_gamma( m_image, m_imageProcessed, f );
	Invalidate( FALSE );
}
