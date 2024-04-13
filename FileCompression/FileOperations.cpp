#include <iostream>
#include "FileOperations.h"

 string FileOperations::LoadFile(const string& path)
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

void FileOperations::SaveToTxtFile(const string& text, const HuffmanNode* node){
    std::ofstream file("encoded.txt", std::ios::binary);
    if(!file.is_open())
        return;
    file << text;
    file.close();
}

void FileOperations::LoadFromBinary(const string& path){
    HuffmanAlgorithm algorithm;
    HuffmanNode *node;
    std::ifstream binary(path, std::ios::binary);
    unsigned int size = 0;        
    binary.read(reinterpret_cast<char *>(&size), sizeof(size)  );
    

    string buffer;
    buffer.resize(size);
    
    binary.read(&buffer[0],  buffer.size() );
    binary.close();
    int s = 2;
}