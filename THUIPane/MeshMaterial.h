#pragma once


// CMeshMaterial �Ի���

class CMeshMaterial : public CDialogEx
{
	DECLARE_DYNAMIC(CMeshMaterial)

public:
	CMeshMaterial(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMeshMaterial();

// �Ի�������
	enum { IDD = IDD_MESH_SIMULATION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
