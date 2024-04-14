#include <compare>
#include <iostream>
#include <set>
#include <fmt/format.h>
#include "FileOperations.h"
#include <string>
#include "HuffmanAlgorithm.h"
 
 
int main()
{
    string filePath = "lorem.txt";
    FileOperations files;
    string text = files.LoadFile(filePath);
    std::cout << text;
    HuffmanAlgorithm huffman;
    std::pair<string,string> encodedStr = huffman.encodeText(text);
    files.SaveToBinaryFile(encodedStr.first, encodedStr.second);

    string path = "test.dat";
    std::pair<string,string> encodedString = files.LoadFromBinary(path);
    string decodedString = huffman.decodeText(encodedString.first, encodedString.second);
    files.SaveToTxtFile(decodedString);
    
}