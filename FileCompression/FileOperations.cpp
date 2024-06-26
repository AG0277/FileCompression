#include <iostream>
#include "FileOperations.h"
#include <limits>
using byte = unsigned char ;
constexpr std::size_t BITS_PER_BYTE = std::numeric_limits<byte>::digits ;
using bits_in_byte = std::bitset<BITS_PER_BYTE> ;

 string FileOperations::LoadFile(const string& path)
{
    string content;
    std::ifstream myFile;
    myFile.open(path);
    string line;
    if(myFile.is_open()){
        char ch;
        while (myFile.get(ch)) {
            content += ch;
    }
    }
    else{
        std::cerr << "Error: unable to open file " << path << "\n";
    }
    auto sw = content[1];
        auto sw1 = content[2];
            auto sw2 = content[3];
    return content;
}

void FileOperations::SaveToBinaryFile(const string& stringifiedNode,const string& encodedText){

    std::fstream binFile("test.dat", std::ios::binary | std::ios::out);
    binFile.write(stringifiedNode.c_str(), stringifiedNode.size());
    char newline = '\n';
    binFile.write(&newline, sizeof(char));
    unsigned char byte = 0;
    int bitsWritten = 0;
    for (char bit : encodedText) {
        byte <<= 1;
        if (bit == '1') {
            byte |= 1;
        }
        ++bitsWritten;
        if (bitsWritten == 8) {
            binFile.write(reinterpret_cast<const char*>(&byte), sizeof(byte));
            byte = 0;
            bitsWritten = 0;
        }
    }
    if(bitsWritten >0){
        byte <<= (8 - bitsWritten);
        binFile.write(reinterpret_cast<char *>(&byte), sizeof(byte));
    }
    
    binFile.close();
}

void FileOperations::SaveToTxtFile(const string& text){
    std::fstream outputFile("testt.txt", std::ios::out);
    outputFile << text;
    outputFile.close();
}

std::pair<string,string> FileOperations::LoadFromBinary(const string& path){
    HuffmanAlgorithm algorithm;

    std::streampos fileSize;
    std::ifstream file(path, std::ios::binary);
    string encodedTree;
    string line;
    getline(file, encodedTree);
    int tttt = encodedTree.size()-1;
    int hasNewLine = encodedTree[tttt];
    string decodedData;
    if(hasNewLine ==49){
        encodedTree.pop_back();
        encodedTree += '\n';
        getline(file, line);
        if(line!="")
        encodedTree += line;

    }
    else{
        encodedTree.pop_back();
    }

        char c ;
        while( file.get(c) )
        {
            decodedData += bits_in_byte( byte(c) ).to_string() ;
        }
    
    return std::pair<string, string>{encodedTree, decodedData};
}
