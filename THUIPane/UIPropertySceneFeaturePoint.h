#pragma once
#include "../THAddIn/THWndDialogsGroup.h"

class UIPropertySceneFeaturePoint : public THUI::THWndDialogsGroup
{
public:
	UIPropertySceneFeaturePoint( CString strTitle );
	virtual ~UIPropertySceneFeaturePoint(void);

	void	InitSubDialogs();
};

