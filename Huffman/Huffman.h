//
// Created by fernando on 23/6/21.
//

#ifndef ADS2_TECFILESYSTEM_HUFFMAN_H
#define ADS2_TECFILESYSTEM_HUFFMAN_H
#define Tree_High 256

#include <bits/stdc++.h>


class Huffman {

public:
    Huffman();

private:
    std::map<char, std::string> code;
    std::map<char, int> rep;

    void printCode(struct TreeNode* root, std::string string);


};


#endif //ADS2_TECFILESYSTEM_HUFFMAN_H
