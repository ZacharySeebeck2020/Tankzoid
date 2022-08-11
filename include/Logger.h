#pragma once
#include <iostream>

enum LogLevel
{
	LOG_DEBUG,
	LOG_INFO,
	LOG_WARN,
	LOG_ERROR,
	LOG_FATAL
};

// Create a singleton class to log messages
class Logger
{
private:
	Logger(){};

public:
	LogLevel activeLogLevel = LOG_ERROR;
	static Logger &getInstance()
	{
		static Logger instance;
		return instance;
	}
	void log(const std::string &message, LogLevel level = LOG_INFO);
	void ForceLog(const std::string &message);
	void setLogLevel(LogLevel level);
};