// THAddIn.h : THAddIn DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTHAddInApp
// �йش���ʵ�ֵ���Ϣ������� THAddIn.cpp
//

class CTHAddInApp : public CWinApp
{
public:
	CTHAddInApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
