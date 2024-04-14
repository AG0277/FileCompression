#pragma once

#include <string>
using std::string;
#include <unordered_map>
#include <queue>
#include <fstream>
#include <bitset>
#include <iostream>

struct HuffmanNode{
    string character;
    string encoding;
    unsigned int NuOfAppearances;
    HuffmanNode *left, *right;
    HuffmanNode(string character, unsigned int NuOfAppearances) : character(character), NuOfAppearances(NuOfAppearances), encoding(""), left(nullptr), right(nullptr) {}
    HuffmanNode(): character("test"), NuOfAppearances(0), encoding(""), left(nullptr), right(nullptr) {}
};

class HuffmanAlgorithm
{
private:
    string text;
    std::unordered_map<char, string> HuffmanCode;
    HuffmanNode* constructedTree;
    void BuildHuffmanTree();
    void GenerateHuffmanCode(HuffmanNode *root);
    void serializeNode(const HuffmanNode *node, string& text);
    int index;
    int getIndex();
    HuffmanNode* readNode(const string &text, int index);

public:
    HuffmanAlgorithm(): index(0){};
    ~HuffmanAlgorithm();
    string decodeText(const string& stringifiedHuffmanTree,const string& textToDecode);
    std::pair<string,string> encodeText(const string& textToEncode);
    HuffmanNode* getHuffmanNode();
};

