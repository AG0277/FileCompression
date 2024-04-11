#include <string>
using std::string;
#include <unordered_map>
#include <queue>

struct HuffmanNode{
    string character;
    string encoding;
    unsigned int NuOfAppearances;
    HuffmanNode *left, *right;
    HuffmanNode(string character, unsigned int NuOfAppearances) : character(character), NuOfAppearances(NuOfAppearances), encoding(""), left(nullptr), right(nullptr) {}
};

class HuffmanAlgorithm
{
private:
    string text;
    std::unordered_map<char, string> HuffmanCode;
    HuffmanNode *BuildHuffmanTree();
    void GenerateHuffmanCode(HuffmanNode *root);

public:
    HuffmanAlgorithm(const string& textToFormat);
    ~HuffmanAlgorithm();
        string encodedText();
};


