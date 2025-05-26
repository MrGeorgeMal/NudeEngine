#pragma once
#ifndef CORE_H
#define CORE_H



#ifdef NU_PLATFORM_WINDOWS

	#ifdef NU_BUILD_DLL
		#define NUDE_API __declspec(dllexport)
	#else
		#define NUDE_API __declspec(dllimport)
	#endif // NU_BUILD_DLL

#else
	#error Nude Engine only supports Windows

#endif // NU_PLATFORM_WINDOW



#endif // !CORE_H