//
// Created by Troels Lund on 23/11/2021.
//

#ifndef WEEK_11_FIBNODE_H
#define WEEK_11_FIBNODE_H

#include <iostream>

using namespace std;

class FibNode {
public:
    FibNode(unsigned int value);

    FibNode(unsigned int value,
            FibNode *left,
            FibNode *right);

    ~FibNode();

    void preOrder();
    unsigned int getSize();
    unsigned int getDept();
    unsigned int getLeaf();
private:
    int value;
    FibNode *left;
    FibNode *right;
};


#endif //WEEK_11_FIBNODE_H
