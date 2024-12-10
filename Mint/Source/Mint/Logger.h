#ifndef CORE_LOG_H
#define CORE_LOG_H

#include <spdlog/spdlog.h>

class  Logger
{
public:
	static void Init();

	static auto& GetMintLogger() { return s_coreLogger; }
	static auto& GetAppLogger() { return s_appLogger; }
private:
	Logger();
	~Logger();

	static spdlog::logger* s_coreLogger;
	static spdlog::logger* s_appLogger;
};

#ifdef BUILD_CORE
#	define GET_CURRENT_LOGGER ::Logger::GetMintLogger()
#else
#	define GET_CURRENT_LOGGER ::Logger::GetAppLogger()
#endif

#define LogTrace(...)	GET_CURRENT_LOGGER->trace(__VA_ARGS__)
#define LogDebug(...)	GET_CURRENT_LOGGER->debug(__VA_ARGS__)
#define LogInfo(...)	GET_CURRENT_LOGGER->info(__VA_ARGS__)
#define LogWarn(...)	GET_CURRENT_LOGGER->warn(__VA_ARGS__)
#define LogError(...)	GET_CURRENT_LOGGER->error(__VA_ARGS__)
#define LogFatal(...)	GET_CURRENT_LOGGER->fatal(__VA_ARGS__)

#ifdef DEBUG
#	define ASSERT(x, ...) { if(x) { LogError("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#	define ASSERT(x, ...)
#endif
#endif