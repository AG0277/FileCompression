#include <compare>
#include <iostream>
#include <set>
#include <fmt/format.h>
#include "InputFile.h"
#include <string>
#include "HuffmanAlgorithm.h"
 
 
int main()
{
    string filePath = "../FileCompression/lorem.txt";
    string text = LoadFile(filePath);
    std::cout << text;
    HuffmanAlgorithm huffman(text);
}