#pragma once

#ifdef NU_PLATFORM_WINDOWS

extern Nude::Application* Nude::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Nude::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif // NU_PLATFORM_WINDOWS