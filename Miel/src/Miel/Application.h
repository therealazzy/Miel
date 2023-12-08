#pragma once

#include "Core.h"
#include "Events/Event.h"
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

