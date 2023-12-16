#pragma once

#include "Core.h"

#include "Window.h"
#include "Miel/LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"




namespace Miel {
	class MIEL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);


		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};


	//DEFINED IN CLIENT
	Application* CreateApplication();



}

