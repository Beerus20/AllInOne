#include "../../include/utils/Logger.hpp"
#include <chrono>
#include <ctime>
#include <iomanip>

namespace One {
namespace Utils {

Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
}

Logger::~Logger() {
    if (m_logFile.is_open()) {
        m_logFile.close();
    }
}

void Logger::setLogLevel(LogLevel level) {
    m_logLevel = level;
}

void Logger::setLogFile(const std::string& filepath) {
    if (m_logFile.is_open()) {
        m_logFile.close();
    }
    m_logFile.open(filepath, std::ios::app);
}

void Logger::debug(const std::string& message) {
    log(LogLevel::Debug, message);
}

void Logger::info(const std::string& message) {
    log(LogLevel::Info, message);
}

void Logger::warning(const std::string& message) {
    log(LogLevel::Warning, message);
}

void Logger::error(const std::string& message) {
    log(LogLevel::Error, message);
}

void Logger::fatal(const std::string& message) {
    log(LogLevel::Fatal, message);
}

void Logger::log(LogLevel level, const std::string& message) {
    if (level < m_logLevel) {
        return;
    }
    writeLog(level, message);
}

void Logger::writeLog(LogLevel level, const std::string& message) {
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    
    std::tm tm = *std::localtime(&time);
    
    std::string logMessage = "[";
    logMessage += std::to_string(tm.tm_year + 1900) + "-";
    logMessage += (tm.tm_mon + 1 < 10 ? "0" : "") + std::to_string(tm.tm_mon + 1) + "-";
    logMessage += (tm.tm_mday < 10 ? "0" : "") + std::to_string(tm.tm_mday) + " ";
    logMessage += (tm.tm_hour < 10 ? "0" : "") + std::to_string(tm.tm_hour) + ":";
    logMessage += (tm.tm_min < 10 ? "0" : "") + std::to_string(tm.tm_min) + ":";
    logMessage += (tm.tm_sec < 10 ? "0" : "") + std::to_string(tm.tm_sec);
    logMessage += "] [" + std::string(getLevelString(level)) + "] " + message;
    
    std::cout << logMessage << std::endl;
    
    if (m_logFile.is_open()) {
        m_logFile << logMessage << std::endl;
        m_logFile.flush();
    }
}

const char* Logger::getLevelString(LogLevel level) {
    switch (level) {
        case LogLevel::Debug:   return "DEBUG";
        case LogLevel::Info:    return "INFO ";
        case LogLevel::Warning: return "WARN ";
        case LogLevel::Error:   return "ERROR";
        case LogLevel::Fatal:   return "FATAL";
        default:                return "UNKNW";
    }
}

} // namespace Utils
} // namespace One
