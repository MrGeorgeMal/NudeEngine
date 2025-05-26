#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

#include "Core.h"

namespace Nude
{
	class NUDE_API Application
	{

	public:

		Application();
		virtual ~Application();

		void Run();
	
	};

	// To be defined on client side
	Application* CreateApplication();

}

#endif // !APPLICATION_H