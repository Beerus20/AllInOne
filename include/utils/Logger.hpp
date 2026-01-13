#pragma once

#include <string>
#include <fstream>
#include <iostream>

namespace One {
namespace Utils {

/**
 * @brief Logger levels
 */
enum class LogLevel {
    Debug,
    Info,
    Warning,
    Error,
    Fatal
};

/**
 * @brief Simple logger
 * Provides basic logging functionality
 */
class Logger {
public:
    static Logger& getInstance();

    void setLogLevel(LogLevel level);
    void setLogFile(const std::string& filepath);

    void debug(const std::string& message);
    void info(const std::string& message);
    void warning(const std::string& message);
    void error(const std::string& message);
    void fatal(const std::string& message);

    void log(LogLevel level, const std::string& message);

private:
    Logger() = default;
    ~Logger();
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    void writeLog(LogLevel level, const std::string& message);
    const char* getLevelString(LogLevel level);

    LogLevel m_logLevel = LogLevel::Info;
    std::ofstream m_logFile;
};

// Convenience macros
#define LOG_DEBUG(msg) One::Utils::Logger::getInstance().debug(msg)
#define LOG_INFO(msg) One::Utils::Logger::getInstance().info(msg)
#define LOG_WARNING(msg) One::Utils::Logger::getInstance().warning(msg)
#define LOG_ERROR(msg) One::Utils::Logger::getInstance().error(msg)
#define LOG_FATAL(msg) One::Utils::Logger::getInstance().fatal(msg)

} // namespace Utils
} // namespace One
