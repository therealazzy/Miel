#pragma once



#ifdef ML_PLATFORM_WINDOWS

extern Miel::Application* Miel::CreateApplication();

int main(int argc, char** argv)
{
	Miel::Log::Init();
	ML_CORE_WARN("Initialized Core log");
	ML_INFO("Initialized Client log");
	auto app = Miel::CreateApplication();
	app->Run();
	delete app;
}

#endif