#include <engine/logging/Logger.h>

shared_ptr<Logger> Logger::getInstance(string name) {
#ifdef _WIN32
    return make_shared<FileLogger>(name);
#else
    return make_shared<StdoutLogger>(name);
#endif
}

shared_ptr<Logger> Logger::getDefault() {
    return defaultLogger;
    /*
    if (Logger::defaultInitialised) {
        return Logger::defaultInstance;
    } else {
        Logger::defaultInstance = Logger::getInstance("Default");
        Logger::defaultInitialised = true;

        return defaultInstance;
    }
    */
}

/*
void Logger::message(LogLevel level, string format, ...) {
    string message;

    va_list args;
    va_start(args, format);
    va_end(args);

    switch (level) {
        case LogLevel::DEBUG:
            debug(format);
            break;
        case LogLevel::INFO:
            info(format);
            break;
        case LogLevel::WARNING:
            warn(format);
            break;
        case LogLevel::ERROR:
            error(format);
            break;
    }
}*/

string Logger::format(string level, string name, string message) {
    string msg;

    msg.append("[");
    msg.append(level);
    msg.append(name);
    msg.append("] ");
    msg.append(message);

    return msg;
}

StdoutLogger::StdoutLogger(string name) {
    this->name = name;
}

void StdoutLogger::debug(string message) {
    cout << format("DEBUG ", name, message) << endl;
}

void StdoutLogger::info(string message) {
    cout << format("INFO  ", name, message) << endl;
}

void StdoutLogger::warn(string message) {
    cout << format("WARN  ", name, message) << endl;
}

void StdoutLogger::error(string message) {
    cout << format("ERROR ", name, message) << endl;
}

void StdoutLogger::crit(string message) {
    cout << format("CRIT  ", name, message) << endl;
}

FileLogger::FileLogger(string name) {
    this->name = name;
}

void FileLogger::debug(string message) {
    out << format("DEBUG ", name, message) << endl;
}

void FileLogger::info(string message) {
    out << format("INFO  ", name, message) << endl;
}

void FileLogger::warn(string message) {
    out << format("WARN  ", name, message) << endl;
}

void FileLogger::error(string message) {
    out << format("ERROR ", name, message) << endl;
}

void FileLogger::crit(string message) {
    out << format("CRIT  ", name, message) << endl;
}
