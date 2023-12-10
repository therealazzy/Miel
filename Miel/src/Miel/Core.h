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

#ifdef ML_ENABLE_ASSERTS
	#define ML_ASSERT(x, ...) { if(!(x)) { ML_ERROR("Assert failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define ML_CORE_ASSERT(x, ...) { if(!(x)) { ML_CORE_ERROR("Assert failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define ML_ASSERT(x, ...)
	#define ML_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)