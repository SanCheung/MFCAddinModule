#pragma once

#include "../THAddIn/THWndDialogsGroup.h"

class UIPropertySceneScene : public THUI::THWndDialogsGroup
{
public:
	UIPropertySceneScene( CString strTitle );
	virtual ~UIPropertySceneScene(void);

	void	InitSubDialogs();
};

