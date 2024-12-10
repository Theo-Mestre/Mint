#include "corepch.h"

spdlog::logger* Logger::s_coreLogger;
spdlog::logger* Logger::s_appLogger;

void Logger::Init()
{
	spdlog::set_pattern("%^[%T] %n: %v%$");
	s_coreLogger = spdlog::stdout_color_mt("CORE").get();
	s_coreLogger->set_level(spdlog::level::trace);

	s_appLogger = spdlog::stdout_color_mt("CLIENT").get();
	s_appLogger->set_level(spdlog::level::trace);

	LogInfo("Logger initialized!");
}

Logger::Logger()
{
	s_coreLogger = nullptr;
	s_appLogger = nullptr;
}

Logger::~Logger()
{
	s_coreLogger = nullptr;
	s_appLogger = nullptr;
}