#pragma once

#ifdef CN_PLATFORM_WINDOWS
	#ifdef CN_BUILD_DLL
		#define COCONUT_API __declspec(dllexport)
	#else
		#define COCONUT_API __declspec(dllimport)
	#endif
#else
	#error Coconut only supports windows!
#endif