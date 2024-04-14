#pragma once
#include <string>
#include <fstream>
#include "HuffmanAlgorithm.h"


using std::string;

class FileOperations
{
private:

public:
  string LoadFile(const string& path);
  void SaveToBinaryFile(const string& stringifiedNode,const string& text);
  void SaveToTxtFile(const string& text);
  std::pair<string,string> LoadFromBinary(const string &path);
};