// THUIPane.h : THUIPane DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTHUIPaneApp
// �йش���ʵ�ֵ���Ϣ������� THUIPane.cpp
//

class CTHUIPaneApp : public CWinApp
{
public:
	CTHUIPaneApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
