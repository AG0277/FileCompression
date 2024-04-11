#include "HuffmanAlgorithm.h"



struct compare {
    bool operator()(HuffmanNode* l, HuffmanNode* r) {
        return (l->NuOfAppearances > r->NuOfAppearances);
    }
};
HuffmanNode* HuffmanAlgorithm::BuildHuffmanTree()
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
    GenerateHuffmanCode(queue.top());
    return queue.top();
}

string HuffmanAlgorithm::encodedText(){
    string encodedText;
    for(auto character:text){
        encodedText += HuffmanCode[character];
    }
    return encodedText;
};

void HuffmanAlgorithm::GenerateHuffmanCode(HuffmanNode* root){
    if(!root)
        return;
    if(root->left == nullptr && root->right == nullptr)
       {
           char character= root->character[0];
           HuffmanCode[character] = root->encoding;}
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

HuffmanAlgorithm::HuffmanAlgorithm(const string &textToFormat)
{
    this->text = textToFormat;
    BuildHuffmanTree();
}

HuffmanAlgorithm::~HuffmanAlgorithm()
{
}
