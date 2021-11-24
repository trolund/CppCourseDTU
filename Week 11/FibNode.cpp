//
// Created by Troels Lund on 23/11/2021.
//

#include <vector>
#include "FibNode.h"

FibNode::~FibNode() {
    if (this->left != nullptr) {
        delete this->left;
    }
    if (this->right != nullptr) {
        delete this->right;
    }
}

unsigned int FibNode::getSize() {
    if(this->left != nullptr && this->right != nullptr){
        return 1 + this->left->getSize() + this->right->getSize();
    }else if(this->left != nullptr){
        return 1 + this->left->getSize();
    }else if(this->right != nullptr){
        return 1 + this->right->getSize();
    }else{
        return 1;
    }
}

FibNode::FibNode(unsigned int value) {
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
}

FibNode::FibNode(unsigned int value, FibNode *left, FibNode *right) {
    this->value = value;
    this->left = left;
    this->right = right;
}

void FibNode::preOrder() {
    cout << this->value << " ";

    // leaf
    if (this->left == nullptr && this->right == nullptr) {
        return;
    }

    if(this->left != nullptr){
        this->left->preOrder();
    }

    if(this->right != nullptr){
        this->right->preOrder();
    }
}

unsigned int FibNode::getDept() {
    if(this->left != nullptr && this->right != nullptr){
        return 1 + max(this->left->getDept(), this->right->getDept());
    }else if(this->left != nullptr){
        return 1 + this->left->getDept();
    }else if(this->right != nullptr){
        return 1 + this->right->getDept();
    }else{
        return 1;
    }
}

unsigned int FibNode::getLeaf() {
    if(this->left == nullptr && this->right == nullptr){
        return 1;
    }else if(this->left == nullptr && this->right != nullptr){
        return this->right->getLeaf();
    }else if(this->right == nullptr && this->left != nullptr){
        return this->left->getLeaf();
    }else{
        return this->left->getLeaf() + this->right->getLeaf();
    }
}


