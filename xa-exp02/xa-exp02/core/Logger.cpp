#include "Logger.h"

Logger *Logger::getLogger(const string& loggerName) {
	Logger *newLogger = new Logger(loggerName);

	return newLogger;
}

Logger::Logger() {
	logfile.open("application.log");
}

Logger::Logger(const string& loggerName) {
	string filename = loggerName + ".log";
	logfile.open(filename);
	this->loggerName = loggerName;
}

Logger::~Logger() {
	logfile.close();
}

void Logger::append(const string& message) {
#ifdef _WIN32
	time_t current_time;
	time(&current_time);
	struct tm tstruct;

	localtime_s(&tstruct, &current_time);

	char dateBuffer[24];
	strftime(dateBuffer, sizeof(dateBuffer), "%Y-%m-%d %H:%M:%S", &tstruct);
	
	logfile << dateBuffer << " " << loggerName << " " << message << endl;
#endif
}

void Logger::trace(const string& message) {
	append("TRACE " + message);
}

void Logger::debug(const string& message) {
	append("DEBUG " + message);
}

void Logger::info(const string& message) {
	append(" INFO " + message);
}

void Logger::warn(const string& message) {
	append(" WARN " + message);
}

void Logger::error(const string& message) {
	append("ERROR " + message);
}
