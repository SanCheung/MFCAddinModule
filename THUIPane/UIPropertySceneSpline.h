#pragma once
#include "../THAddIn/THWndDialogsGroup.h"

class UIPropertySceneSpline : public THUI::THWndDialogsGroup
{
public:
	UIPropertySceneSpline( CString strTitle );
	virtual ~UIPropertySceneSpline(void);

	void	InitSubDialogs();
};

