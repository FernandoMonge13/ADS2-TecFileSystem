//
// Created by fernando on 23/6/21.
//

#include "Huffman.h"


Huffman::Huffman() {

}

struct TreeNode{
    char data;
    int rep;
    TreeNode *right;
    TreeNode *left;

    TreeNode(char data, int rep){
        right = NULL;
        left = NULL;
        this->data = data;
        this->rep = rep;
    }
};

struct compare{
    bool operator()(TreeNode* x, TreeNode* y){
        return (x->rep > y->rep);
    }


};