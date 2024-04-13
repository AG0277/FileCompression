#include "HuffmanAlgorithm.h"



struct compare {
    bool operator()(HuffmanNode* l, HuffmanNode* r) {
        return (l->NuOfAppearances > r->NuOfAppearances);
    }
};

void HuffmanAlgorithm::BuildHuffmanTree()
{
    std::unordered_map<char, int> frequencyTable;
    for(char c:this->text){
        frequencyTable[c]++;
    }

    std::priority_queue<HuffmanNode*,std::vector<HuffmanNode*>, compare>queue;

    for( auto pair: frequencyTable){
        string str(1, pair.first);
        queue.push(new HuffmanNode(str, pair.second));
    }   
    while(queue.size()>1){

        HuffmanNode *left = queue.top();
        queue.pop();
        HuffmanNode *right = queue.top();
        queue.pop();
        auto node = new HuffmanNode(left->character+right->character, left->NuOfAppearances+right->NuOfAppearances);
        node->left = left;
        node->right = right;
        queue.push(node);
    }
    string encodedText;
    GenerateHuffmanCode(queue.top());
    constructedTree =  queue.top();
}

string HuffmanAlgorithm::decodeText(const string& textToDecode)
{
    string decodedString;
    const HuffmanNode* node = constructedTree;
    for(const char character: textToDecode){
        if(character == '0'){
            node = node->left;
        }
        else{
            node = node->right;
        }
        if(node->left == nullptr && node->right == nullptr){
            decodedString +=node->character;
            node = constructedTree;
        }
    }
    return decodedString;
};

string HuffmanAlgorithm::encodeText(const string& textToEncode)
{
    this->text = textToEncode;
    BuildHuffmanTree();
    string encodedText;
    for(auto character:text){
        encodedText += HuffmanCode[character];
    }
    string binaryHuffmanTree;
    serializeNode(constructedTree, binaryHuffmanTree);

    //auto text123 = readNode(binaryHuffmanTree,0);
    
    std::fstream binFile("test.dat", std::ios::binary | std::ios::out);
    binFile.write(binaryHuffmanTree.c_str(), binaryHuffmanTree.size());
    unsigned char byte = 0;
    int bitsWritten = 0;

    for (char bit : encodedText) {
        byte <<= 1;
        if (bit == '1') {
            byte |= 1;
        }
        ++bitsWritten;
        if (bitsWritten == 8) {
            binFile.write(reinterpret_cast<const char*>(&byte), sizeof(byte));
            byte = 0;
            bitsWritten = 0;
        }
    }
    
    binFile.close();
    return encodedText;
};

void HuffmanAlgorithm::serializeNode(const HuffmanNode* node, string& text){

    if(node->left == nullptr && node->right==nullptr){
        text += "1";
        text += node->character;
        return;
    }
    else{
        text += "0";
        serializeNode(node->left, text);
        serializeNode(node->right, text);
    }

}

int HuffmanAlgorithm::getIndex(){
    return this->index += 1;
}

HuffmanNode* HuffmanAlgorithm::readNode(string& text, int index)
{
    auto test = text[index];
    if (test== 49)
    {
    auto leaf = new HuffmanNode();
    leaf->character = text[getIndex()];
    return leaf;
    }
    else{
        int newIndexLeft = getIndex();
        HuffmanNode* left = ( readNode( text, newIndexLeft));
        int newIndexRight = getIndex();
        HuffmanNode* right =(readNode( text, newIndexRight));
        auto notLeaf = new HuffmanNode();
        notLeaf->character =left->character + right->character;
        notLeaf->left = left;
        notLeaf->right = right;
        return notLeaf;
    }
}

void HuffmanAlgorithm::GenerateHuffmanCode(HuffmanNode *root)
{
    if(root->left == nullptr && root->right == nullptr)
    {
        char character= root->character[0];
        HuffmanCode[character] = root->encoding;
    }

    if(root->left!=nullptr )
    {
        root->left->encoding = root->encoding +"0";
        GenerateHuffmanCode(root->left);
    }

    if( root->right !=nullptr)
    {   
        root->right->encoding = root->encoding +"1";
        GenerateHuffmanCode(root->right);
    }
};

HuffmanNode* HuffmanAlgorithm:: getHuffmanNode(){
    return constructedTree;
}

HuffmanAlgorithm::~HuffmanAlgorithm()
{
}
