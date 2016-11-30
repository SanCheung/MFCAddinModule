#pragma once


// CMeshMaterial 对话框

class CMeshMaterial : public CDialogEx
{
	DECLARE_DYNAMIC(CMeshMaterial)

public:
	CMeshMaterial(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMeshMaterial();

// 对话框数据
	enum { IDD = IDD_MESH_SIMULATION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
