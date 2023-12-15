#pragma once

#include "mlpch.h"

#include "Miel/Core.h"
#include "Miel/Events/Event.h"

namespace Miel {

	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Miel Engine",
			unsigned int width = 1080,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height) {}
	};

	//pure interface
	class MIEL_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}
		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVsync(bool enabled) = 0;
		virtual bool IsVsync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}