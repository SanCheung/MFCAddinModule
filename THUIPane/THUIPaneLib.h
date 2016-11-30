#pragma once

#ifdef _USR_THUIPANE_DLL
#define		THUIPANE_DLL		__declspec(dllimport)
#else
#define		THUIPANE_DLL		__declspec(dllexport)
#endif