#include <engine/logging/Logger.h>

shared_ptr<Logger> Logger::getInstance(string name) {
#ifdef _WIN32
    return make_shared<FileLogger<(name);
#else
    return make_shared<StdoutLogger>(name);
#endif
}

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
    cout << format("DEBUG ", name, message) << endl;
}

void FileLogger::info(string message) {
    cout << format("INFO  ", name, message) << endl;
}

void FileLogger::warn(string message) {
    cout << format("WARN  ", name, message) << endl;
}

void FileLogger::error(string message) {
    cout << format("ERROR ", name, message) << endl;
}

void FileLogger::crit(string message) {
    cout << format("CRIT  ", name, message) << endl;
}
