#pragma once
#ifndef LOG_H
#define LOG_H

#include "Core.h"
#include "spdlog/spdlog.h"
#include <memory>

namespace Nude
{

	class NUDE_API Log
	{

	public:

		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return clientLogger; }

	private:

		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;

	};

}


// Core log macros
#define NU_CORE_TRACE(...)	::Nude::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NU_CORE_INFO(...)	::Nude::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NU_CORE_WARN(...)	::Nude::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NU_CORE_ERROR(...)	::Nude::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NU_CORE_FATAL(...)	::Nude::Log::GetCoreLogger()->critical(__VA_ARGS__)

// CLient log macros
#define NU_TRACE(...)		::Nude::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NU_INFO(...)		::Nude::Log::GetClientLogger()->info(__VA_ARGS__)
#define NU_WARN(...)		::Nude::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NU_ERROR(...)		::Nude::Log::GetClientLogger()->error(__VA_ARGS__)
#define NU_FATAL(...)		::Nude::Log::GetCoreLogger()->critical(__VA_ARGS__)

#endif // !LOG_H