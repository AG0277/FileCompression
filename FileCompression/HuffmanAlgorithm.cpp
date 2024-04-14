#include "HuffmanAlgorithm.h"

#include <bitset>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

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

string HuffmanAlgorithm::decodeText(const string& stringifiedHuffmanTree,const string& textToDecode)
{

    auto HuffmanTree = readNode(stringifiedHuffmanTree,0);
    string decodedString;
    this->constructedTree = HuffmanTree;
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

std::pair<string,string> HuffmanAlgorithm::encodeText(const string& textToEncode)
{
    this->text = textToEncode;
    BuildHuffmanTree();
    string encodedText;
    for(auto character:text){
        encodedText += HuffmanCode[character];
    }
    string binaryHuffmanTree;
    serializeNode(constructedTree, binaryHuffmanTree);

    return std::pair<string,string>{binaryHuffmanTree,encodedText};
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

HuffmanNode* HuffmanAlgorithm::readNode(const string& text, int index)
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
