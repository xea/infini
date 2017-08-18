#include <engine/io/FileSource.h>


string FileSource::getFileContents(string fileName) {
    string fileString = string();                                                                                                                                                              
    string line = string();                                                                                                                                                                    

    ifstream file(fileName);                                                                                                                                                                   

    if (file.is_open()) {                                                                                                                                                                      
        while (!file.eof()) {                                                                                                                                                                  
            getline(file, line);                                                                                                                                                               
            fileString.append(line);                                                                                                                                                           
            fileString.append("\n");                                                                                                                                                           
        }                                                                                                                                                                                      

        file.close();                                                                                                                                                                          
    }                                                                                                                                                                                          

    return fileString;
}
