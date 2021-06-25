//
// Created by fernando on 23/6/21.
//

#ifndef TEST_HUFFMAN_H
#define TEST_HUFFMAN_H
#include <iostream>
#include <bits/stdc++.h>


class Huffman {
public:

    Huffman();

    static Huffman* getInstance();
    std::map<char, std::string> codes;
    std::map<char, int> freq;
    std::string code(std::string info);
    std::string decode(std::string info);

private:

    static Huffman* instance;
    void printCodes(struct MinHeapNode* root, std::string str);
    void storeCodes(struct MinHeapNode* root, std::string str);
    void HuffmanCodes(int size);
    void calcFreq(std::string str, int n);
    std::string decode_file(struct MinHeapNode* root, std::string s);


};



#endif //ADS2_TECFILESYSTEM_HUFFMAN_H
