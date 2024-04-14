#pragma once

#include <string>
using std::string;
#include <unordered_map>
#include <queue>
#include <fstream>
#include <bitset>
#include <iostream>
#include <memory>

struct HuffmanNode{
    string character;
    string encoding;
    unsigned int NuOfAppearances;
    std::shared_ptr<HuffmanNode> left, right;
    HuffmanNode(string character, unsigned int NuOfAppearances) : character(character), NuOfAppearances(NuOfAppearances), encoding(""), left(nullptr), right(nullptr) {}
    HuffmanNode(): character("test"), NuOfAppearances(0), encoding(""), left(nullptr), right(nullptr) {}
    HuffmanNode &operator=(const HuffmanNode &) = delete;
    HuffmanNode(const HuffmanNode&) = delete;

};

class HuffmanAlgorithm
{
private:
    string text;
    std::unordered_map<char, string> HuffmanCode;
    std::shared_ptr<HuffmanNode> constructedTree;
    void BuildHuffmanTree();
    void GenerateHuffmanCode(std::shared_ptr<HuffmanNode> root);
    void serializeNode(std::shared_ptr<HuffmanNode> node, string& text);
    int index;
    int getIndex();
    void deleteNode(HuffmanNode* node);
    std::shared_ptr<HuffmanNode> readNode(const string &text, int index);

public:
    HuffmanAlgorithm(): index(0){};
    ~HuffmanAlgorithm();
    string decodeText(const string& stringifiedHuffmanTree,const string& textToDecode);
    std::pair<string,string> encodeText(const string& textToEncode);
};

