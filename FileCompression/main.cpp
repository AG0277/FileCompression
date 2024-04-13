#include <compare>
#include <iostream>
#include <set>
#include <fmt/format.h>
#include "FileOperations.h"
#include <string>
#include "HuffmanAlgorithm.h"
 
 
int main()
{
    string filePath = "../FileCompression/lorem.txt";
    FileOperations files;
    string text = files.LoadFile(filePath);
    HuffmanAlgorithm huffman;
    string encodedStr = huffman.encodeText(text);

    // string decodedStr= huffman.decodeText(encodedStr);
    // files.SaveToTxtFile(encodedStr,huffman.getHuffmanNode());
    // if( text ==decodedStr )
    //     std::cout << "equal";
    // string path = "test.bin";
    // files.LoadFromBinary(path);
}