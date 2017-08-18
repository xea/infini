#ifndef XA_FILESOURCE_H
#define XA_FILESOURCE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileSource {
public:
    static string getFileContents(string fileName);
};

#endif // XA_FILESOURCE_H