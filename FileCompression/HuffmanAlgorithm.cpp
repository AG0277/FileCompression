#include "HuffmanAlgorithm.h"

#include <bitset>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

struct compare {
    bool operator()(const std::shared_ptr<HuffmanNode> l, const std::shared_ptr<HuffmanNode> r) {
        return (l->NuOfAppearances > r->NuOfAppearances);
    }
};

void HuffmanAlgorithm::BuildHuffmanTree()
{
    std::unordered_map<char, int> frequencyTable;
    for(char c:this->text){
        frequencyTable[c]++;
    }
    auto x = frequencyTable.size();
    if(frequencyTable.size()<4){
        frequencyTable['q'] = 10;
        frequencyTable['w'] = 10;
        frequencyTable['y'] = 10;
        frequencyTable['z'] = 10;
    }

    std::priority_queue<std::shared_ptr<HuffmanNode>,std::vector<std::shared_ptr<HuffmanNode>>, compare>queue;

    for( auto pair: frequencyTable){
        string str(1, pair.first);
        queue.push(std::make_shared<HuffmanNode>(str, pair.second));
    }   
    while(queue.size()>1){

        std::shared_ptr<HuffmanNode> left = queue.top();
        queue.pop();
        std::shared_ptr<HuffmanNode> right = queue.top();
        queue.pop();
        auto node = std::make_shared<HuffmanNode>(left->character+right->character, left->NuOfAppearances+right->NuOfAppearances);
        node->left = left;
        node->right = right;
        queue.push(node);
    }
    string encodedText;
    GenerateHuffmanCode(queue.top());
    constructedTree = queue.top();
}

string HuffmanAlgorithm::decodeText(const string& stringifiedHuffmanTree,const string& textToDecode)
{

    auto HuffmanTree = readNode(stringifiedHuffmanTree,0);
    string decodedString;
    this->constructedTree = HuffmanTree;
    std::shared_ptr<HuffmanNode> node = constructedTree;
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
    auto it = binaryHuffmanTree.find(10);
    if(it==std::string::npos)
    {
        binaryHuffmanTree += "0";
    }
    else{
        binaryHuffmanTree.insert(it, "1");
    }

    return std::pair<string,string>{binaryHuffmanTree,encodedText};
};

void HuffmanAlgorithm::serializeNode(std::shared_ptr<HuffmanNode> node, string& text){

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

std::shared_ptr<HuffmanNode> HuffmanAlgorithm::readNode(const string& text, int index)
{

    if (text[index]== '1')
    {
        auto leaf = std::make_shared<HuffmanNode>();
        leaf->character = text[getIndex()];
        return leaf;
    }
    else
    {
        int newIndexLeft = getIndex();
        std::shared_ptr<HuffmanNode> left = ( readNode( text, newIndexLeft));
        int newIndexRight = getIndex();
        std::shared_ptr<HuffmanNode> right =(readNode( text, newIndexRight));
        auto notLeaf = std::make_shared<HuffmanNode>();
        notLeaf->character =left->character + right->character;
        notLeaf->left = left;
        notLeaf->right = right;
        return notLeaf;
    }
}

void HuffmanAlgorithm::GenerateHuffmanCode(std::shared_ptr<HuffmanNode> root)
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



HuffmanAlgorithm::~HuffmanAlgorithm()
{
 
}

void HuffmanAlgorithm::deleteNode(HuffmanNode* node){
    // if(node->left == nullptr&& node->right == nullptr){
    //     delete node;
    // }
    // deleteNode(node->left);
    // deleteNode(node->right);
}

