#pragma once

#ifdef CN_PLATFORM_WINDOWS

extern Coconut::Application* Coconut::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Coconut::CreateApplication();
	app->Run();
	delete app;
}
#endif