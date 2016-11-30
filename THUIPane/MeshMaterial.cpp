// MeshMaterial.cpp : 实现文件
//

#include "stdafx.h"
#include "THUIPane.h"
#include "MeshMaterial.h"
#include "afxdialogex.h"


// CMeshMaterial 对话框

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


// CMeshMaterial 消息处理程序
