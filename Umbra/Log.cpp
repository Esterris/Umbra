#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"


namespace Umbra
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log:: s_ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[$T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("UMBRA");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}

// Core log macros
#define UM_CORE_TRACE(...) ::Umbra::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define UM_CORE_INFO(...)  ::Umbra::Log::GetCoreLogger()->info(__VA_ARGS__)
#define UM_CORE_WARN(...)  ::Umbra::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define UM_CORE_ERROR(...) ::Umbra::Log::GetCoreLogger()->error(__VA_ARGS__)
#define UM_CORE_FATAL(...) ::Umbra::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define UM_TRACE(...)      ::Umbra::Log::GetClientLogger()->trace(__VA_ARGS__)
#define UM_INFO(...)       ::Umbra::Log::GetClientLogger()->info(__VA_ARGS__)
#define UM_WARN(...)       ::Umbra::Log::GetClientLogger()->warn(__VA_ARGS__)
#define UM_ERROR(...)      ::Umbra::Log::GetClientLogger()->error(__VA_ARGS__)
#define UM_FATAL(...)      ::Umbra::Log::GetClientLogger()->fatal(__VA_ARGS__)

