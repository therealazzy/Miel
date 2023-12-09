#pragma once


#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"


namespace Miel {

	class MIEL_API Log
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
//MACROS FOR CORE LOG
#define ML_CORE_TRACE(...)    ::Miel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ML_CORE_INFO(...)     ::Miel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ML_CORE_WARN(...)     ::Miel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ML_CORE_ERROR(...)    ::Miel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ML_CORE_CRITICAL(...) ::Miel::Log::GetCoreLogger()->critical(__VA_ARGS__)

//MACROS FOR CLIENT LOG
#define ML_TRACE(...)	      ::Miel::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ML_INFO(...)          ::Miel::Log::GetClientLogger()->info(__VA_ARGS__)
#define ML_WARN(...)          ::Miel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ML_ERROR(...)         ::Miel::Log::GetClientLogger()->error(__VA_ARGS__)
#define ML_CRITICAL(...)      ::Miel::Log::GetClientLogger()->critical(__VA_ARGS__)
