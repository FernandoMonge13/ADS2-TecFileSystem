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

    /**
     * @brief codes a message
     * @param info to be coded
     * @return already coded
     */
    std::string code(std::string info);

    /**
     * @brief decodes que information
     * @param info the one is gonna be decode
     * @return decoded information
     */
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
