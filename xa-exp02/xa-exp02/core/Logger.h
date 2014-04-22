#ifndef XA_LOGGER_H
#define XA_LOGGER_H

#include <string>
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

/**
 * A very simple implementation for file-based logging
 */
class Logger {
private:

	Logger();

	Logger(const string& loggerName);

	ofstream logfile;
	string loggerName;

protected:

	void append(const string& message);

public:
	
	~Logger();

	/**
	 * Creates a new Logger instance with name <code>loggerName</code>
	 */
	static Logger *getLogger(const string& loggerName);

	/**
	 * Appends a new TRACE level message to the log
	 */
	void trace(const string& message);

	/**
	 * Appends a new DEBUG level message to the log
	 */
	void debug(const string& message);

	/**
	 * Appends a new INFO level message to the log
	 */
	void info(const string& message);

	/**
	 * Appends a new WARN level message to the log
	 */
	void warn(const string& message);

	/**
	 * Adds a new ERROR level message to the log
	 */
	void error(const string& message);

};


#endif // XA_LOGGER_H