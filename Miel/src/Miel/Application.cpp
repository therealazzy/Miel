#include "mlpch.h"
#include "Application.h"

#include "Miel/Events/ApplicationEvent.h"
#include "Miel/Log.h"

namespace Miel {
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}