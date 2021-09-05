#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Coconut {
	class COCONUT_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core log macros
#define CN_CORE_TRACE(...) ::Coconut::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CN_CORE_INFO(...)  ::Coconut::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CN_CORE_WARN(...)  ::Coconut::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CN_CORE_ERROR(...) ::Coconut::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CN_CORE_FATAL(...) ::Coconut::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define CN_TRACE(...) ::Coconut::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CN_INFO(...)  ::Coconut::Log::GetClientLogger()->info(__VA_ARGS__)
#define CN_WARN(...)  ::Coconut::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CN_ERROR(...) ::Coconut::Log::GetClientLogger()->error(__VA_ARGS__)
#define CN_FATAL(...) ::Coconut::Log::GetClientLogger()->fatal(__VA_ARGS__)