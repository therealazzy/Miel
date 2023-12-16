#include <Miel.h>

class ExampleLayer : public Miel::Layer 
{
public:
	ExampleLayer()
		: Layer("Example"){}

	void OnUpdate() override
	{
		ML_INFO("ExampleLayer::Update");
	}

	void OnEvent(Miel::Event& event) override
	{
		ML_TRACE("{0}", event);
	}

};

class Sandbox : public Miel::Application
{
	public:
		Sandbox()
		{
			PushLayer(new ExampleLayer());
		}

		~Sandbox()
		{

		}
};

Miel::Application* Miel::CreateApplication()
{
	return new Sandbox();
}
