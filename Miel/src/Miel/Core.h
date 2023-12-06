#pragma once

#ifdef	ML_PLATFORM_WINDOWS
	#ifdef ML_BUILD_DLL
		#define MIEL_API __declspec(dllexport)
	#else
		#define MIEL_API __declspec(dllimport)
	#endif
#else
	#error Only Windows is supported.
#endif