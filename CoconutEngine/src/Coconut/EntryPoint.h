#pragma once

#ifdef CN_PLATFORM_WINDOWS

extern Coconut::Application* Coconut::CreateApplication();

int main(int argc, char** argv)
{
	int a = 5;
	Coconut::Log::Init();
	CN_CORE_WARN("Initialized Log!");
	CN_INFO("Hello Var = {0}", a);

	auto app = Coconut::CreateApplication();
	app->Run();
	delete app;
}
#endif