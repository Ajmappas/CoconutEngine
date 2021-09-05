#pragma once

#include "Core.h"

namespace Coconut {
	class COCONUT_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}

