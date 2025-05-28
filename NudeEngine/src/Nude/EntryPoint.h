#pragma once

#ifdef NU_PLATFORM_WINDOWS

extern Nude::Application* Nude::CreateApplication();

int main(int argc, char** argv)
{
	Nude::Log::Init();
	NU_CORE_WARN("Initialize Log!");
	NU_TRACE("LETS GOOOO");

	auto app = Nude::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif // NU_PLATFORM_WINDOWS