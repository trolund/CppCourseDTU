#include <iostream>
#include <vector>
#include "FibNode.h"

struct Result {
    unsigned int value;
    FibNode* node;
};

int output(unsigned int x);

Result* fib(unsigned int n){
    if (n == 0 || n == 1){
        FibNode *leaf = new FibNode(1);

        Result *r = new Result();
        r->node = leaf;
        r->value = 1;
        return r;
    }
    else{
        Result *left = fib(n-1);
        Result *right = fib(n-2);

        unsigned int value = left->value + right->value;

        FibNode *node = new FibNode(value, left->node, right->node);

        Result *r = new Result();
        r->node = node;
        r->value = value;
        return r;
    }
}

int main() {

    unsigned int x;
    cin >> x;

    output(x);
/*    int  *m = new int[38];

    for (int i = 1; i < 37; ++i) {
        int s = output(i);
        m[i-1] = s;
    }

    for (int i = 0; i < 36; ++i) {
        cout << m[i-1] << " ";
    }*/

    return 0;
}

int output(unsigned int n){
    FibNode *root = fib(n)->node;

    cout << "Call tree in pre-order: ";
    root->preOrder();
    cout << endl;

    cout << "Call tree size: " << root->getSize() << endl;
    cout << "Call tree depth: " << root->getDept() << endl;
    cout << "Call tree leafs: " << root->getLeaf() << endl;

    return root->getSize();
}
