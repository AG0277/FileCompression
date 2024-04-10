#include <string>
using std::string;
#include <unordered_map>

class HuffmanAlgorithm
{
private:
    string text;
    void CalculateFrequencyTable();

public:
    HuffmanAlgorithm(const string& textToFormat);
    ~HuffmanAlgorithm();
};


