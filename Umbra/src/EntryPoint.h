#pragma once

#ifdef UM_PLATFORM_WINDOWS

extern Umbra::Application* Umbra::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Umbra::CreateApplication();
	app->Run();
	delete app;
}

#endif