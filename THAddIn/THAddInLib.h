#pragma once

#ifdef _USR_THADDIN_DLL
#define		THADDIN_DLL		__declspec(dllimport)
#else
#define		THADDIN_DLL		__declspec(dllexport)
#endif