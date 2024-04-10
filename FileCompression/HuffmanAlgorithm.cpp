#include "HuffmanAlgorithm.h"

void HuffmanAlgorithm::CalculateFrequencyTable()
{
    std::unordered_map<char, int> frequencyTable;
    for(char c:this->text){
        frequencyTable[c]++;
    }
    int s = 2;

}

HuffmanAlgorithm::HuffmanAlgorithm(const string &textToFormat)
{
    this->text = textToFormat;
    CalculateFrequencyTable();
}

HuffmanAlgorithm::~HuffmanAlgorithm()
{
}
