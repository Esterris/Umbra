#pragma once
#include "Umbra.h"

class SandboxApp : public Umbra::Application
{

public:

	SandboxApp(){}

	~SandboxApp(){}
};

Umbra::Application* Umbra::CreateApplication()
{
	return new SandboxApp();
}