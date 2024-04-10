#include <iostream>
#include "InputFile.h"




 string LoadFile(const string& path)
{
    string content;
    std::ifstream myFile;
    myFile.open(path);
    string line;
    if(myFile.is_open()){
        while(std::getline(myFile,line)){
            content += line;
        }
    }
    else{
        std::cerr << "Error: unable to open file " << path << "\n";
    }
    return content;
}
