#pragma once

#ifdef UM_PLATFORM_WINDOWS
	#ifdef UM_BUILD_DLL
		#define UMBRA_API __declspec(dllexport)
	#else
		#define UMBRA_API __declspec(dllimport)
	#endif
#else 
	#error Umbra only supports windows! 
#endif