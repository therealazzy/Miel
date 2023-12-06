#include <Miel.h>

class Sandbox : public Miel::Application
{
	public:
		Sandbox()
		{

		}

		~Sandbox()
		{

		}
};

Miel::Application* Miel::CreateApplication()
{
	return new Sandbox();
}
