#pragma once

#include "../THAddIn/THWndDialogsGroup.h"

class UIPropertySceneMesh : public THUI::THWndDialogsGroup
{
public:
	UIPropertySceneMesh( CString strTitle );
	virtual ~UIPropertySceneMesh(void);

	void	InitSubDialogs();
};

