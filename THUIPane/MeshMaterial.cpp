// MeshMaterial.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "THUIPane.h"
#include "MeshMaterial.h"
#include "afxdialogex.h"


// CMeshMaterial �Ի���

IMPLEMENT_DYNAMIC(CMeshMaterial, CDialogEx)

CMeshMaterial::CMeshMaterial(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMeshMaterial::IDD, pParent)
{

}

CMeshMaterial::~CMeshMaterial()
{
}

void CMeshMaterial::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMeshMaterial, CDialogEx)
END_MESSAGE_MAP()


// CMeshMaterial ��Ϣ�������
