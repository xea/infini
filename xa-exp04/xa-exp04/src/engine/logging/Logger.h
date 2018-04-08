#ifndef XA_LOGGER_H
#define XA_LOGGER_H

#include <cstdarg>
#include <iostream>
#include <memory>
#include <string>
#include <fstream>

using namespace std;

/**
 * Contains initialisation information that's required to set up a working logger instance.
 */
class LoggerConfiguration {
public:
	LoggerConfiguration();

	LoggerConfiguration(string& target);

	void setTarget(string& target);
};

#ifdef __APPLE__
enum LogLevel {
    DEBU,
    INFO,
    WARNING,
    ERROR
};
#else
enum class LogLevel : unsigned int {
    DEBUG,
    INFO,
    WARNING,
    ERRO
};
#endif


/**
 * Basic implementation for logging functionality
 */
class Logger {
protected: 
	string name;

	LogLevel level;

	static string format(string level, string name, string message);
public:
	static shared_ptr<Logger> getInstance(string name);
	static shared_ptr<Logger> getDefault();

	virtual void debug(string message) = 0;
	virtual void info(string message) = 0;
	virtual void warn(string message) = 0;
	virtual void error(string message) = 0;
	virtual void crit(string message) = 0;

};

static const shared_ptr<Logger> defaultLogger = Logger::getInstance("Default");

class StdoutLogger : public Logger {
public:
	StdoutLogger(string name);
	void debug(string message);
	void info(string message);
	void warn(string message);
	void error(string message);
	void crit(string message);
};

class FileLogger : public Logger {
private:
	ofstream out{ ofstream("app.log") };
public:
	FileLogger(string name);
	void debug(string message);
	void info(string message);
	void warn(string message);
	void error(string message);
	void crit(string message);
};

#endif // XA_LOGGER_H
