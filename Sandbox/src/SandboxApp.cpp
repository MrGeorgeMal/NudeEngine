#include <Nude.h>



class Sandbox : public Nude::Application
{
public:

	Sandbox()
	{

	}

	~Sandbox()
	{

	}

private:

};



Nude::Application* Nude::CreateApplication()
{
	return new Sandbox();
}