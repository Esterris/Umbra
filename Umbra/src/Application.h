#pragma once

#include "Macros.h"

namespace Umbra
{

	class UMBRA_API Application
	{

	public:

		Application(){}
		virtual ~Application(){}

		void Run();

	};


	//To be defined in CLIENT
	Application* CreateApplication();

}