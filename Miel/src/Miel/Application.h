#pragma once

#include "Core.h"

namespace Miel {
	class MIEL_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};


	//DEFINED IN CLIENT
	Application* CreateApplication();



}

