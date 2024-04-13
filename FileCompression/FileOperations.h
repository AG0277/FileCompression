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
  void SaveToTxtFile(const string &text, const HuffmanNode* node);
  void LoadFromBinary(const string &path);
};