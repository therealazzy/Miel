#pragma once



#ifdef ML_PLATFORM_WINDOWS

extern Miel::Application* Miel::CreateApplication();

int main(int argc, char** argv)
{

	auto app = Miel::CreateApplication();
	app->Run();
	delete app;
}

#endif