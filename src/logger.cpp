#include "Logger.h"
#include <iostream>

void Logger::log(const std::string &message, LogLevel level)
{
    if (level >= activeLogLevel)
    {
        switch (level)
        {
        case LogLevel::LOG_DEBUG:
            std::cout << "DEBUG: " << message << std::endl;
            break;

        case LogLevel::LOG_INFO:
            std::cout << "INFO: " << message << std::endl;
            break;

        case LogLevel::LOG_ERROR:
            std::cout << "ERROR: " << message << std::endl;
            break;

        case LogLevel::LOG_FATAL:
            std::cout << "FATAL: " << message << std::endl;
            break;

        default:
            std::cout << "UNKNOWN LOG LEVEL: " << message << std::endl;
            break;
        }
    }
}

void Logger::ForceLog(const std::string &message)
{
    std::cout << "FORCED LOG: " << message << std::endl;
}

void Logger::setLogLevel(LogLevel level)
{
    activeLogLevel = level;
}