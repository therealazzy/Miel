#include "mlpch.h"
#include "Application.h"

#include "Miel/Events/ApplicationEvent.h"
#include "Miel/Log.h"

namespace Miel {
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		ML_TRACE(e);
		while (true);
	}
}