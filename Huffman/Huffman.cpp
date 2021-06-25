//
// Created by fernando on 23/6/21.
//

#include "Huffman.h"

Huffman* Huffman:: instance = nullptr;



Huffman::Huffman() {

}

struct MinHeapNode{
    char data;
    int freq;
    MinHeapNode *left, *right;

    MinHeapNode(char data, int freq){
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};


struct compare{
    bool operator()(MinHeapNode* l, MinHeapNode* r){
        return (l->freq > r->freq);
    }
};

//void Huffman::printCodes(struct MinHeapNode *root, std::string str) {
//    if (!root)
//        return;
//    if (root->data != '$')
//        std::cout << root->data << ": " << str << "\n";
//    printCodes(root->left, str + "0");
//    printCodes(root->right, str + "1");
//
//}

void Huffman::storeCodes(struct MinHeapNode *root, std::string str) {
    if (root==NULL){
        return;
    }

    if (root->data != '$'){
        codes[root->data]=str;
    }
    storeCodes(root->left, str + "0");
    storeCodes(root->right, str + "1");
}

std::priority_queue<MinHeapNode*, std::vector<MinHeapNode*>, compare> minHeap;

void Huffman::HuffmanCodes(int size) {

    struct MinHeapNode *left, *right, *top;
    for (std::map<char, int>::iterator v=freq.begin(); v!=freq.end(); v++){
        minHeap.push(new MinHeapNode(v->first, v->second));
    }

    while (minHeap.size() != 1){
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    storeCodes(minHeap.top(), "");
}

void Huffman::calcFreq(std::string str, int n) {
    for (int i=0; i<str.size(); i++){
        freq[str[i]]++;
    }
}

std::string Huffman::decode_file(struct MinHeapNode *root, std::string s) {

    std::string ans = "";
    struct MinHeapNode* curr = minHeap.top();
    for (int i=0;i<s.size();i++){
        if (s[i] == '0'){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }

        if (curr->left==NULL and curr->right==NULL){
            ans += curr->data;
            curr = root;
        }
    }
    return ans;
}

std::string Huffman::code(std::string info) {
    std::string encodedString, decodedString;
    calcFreq(info, info.length());
    HuffmanCodes(info.length());
//    std::cout << "Character With there Frequencies:\n";
//    for (auto v=codes.begin(); v!=codes.end(); v++)
//        std::cout << v->first <<' ' << v->second << std::endl;

    for (auto i: info){
        encodedString+=codes[i];
    }
    return encodedString;

}

Huffman *Huffman::getInstance() {
    if (instance == nullptr){
        instance = new Huffman;
    }
    return instance;

}

std::string Huffman::decode(std::string info) {

    //std::string encodedString = decode_file(minHeap.top(), info);
    return decode_file(minHeap.top(), info);;
}