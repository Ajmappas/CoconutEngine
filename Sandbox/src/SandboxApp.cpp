#include <Coconut.h>

class Sandbox : public Coconut::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Coconut::Application* Coconut::CreateApplication()
{
	return new Sandbox();
}