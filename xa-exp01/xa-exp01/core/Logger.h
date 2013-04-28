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
	~Logger();

	ofstream logfile;
	string loggerName;

protected:

	void append(const string& message);

public:
	
	static Logger *getLogger(const string& loggerName);

	void trace(const string& message);

	void debug(const string& message);

	void info(const string& message);

	void warn(const string& message);

	void error(const string& message);

};


#endif // XA_LOGGER_H