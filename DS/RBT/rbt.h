#ifndef RBT_H_
#define RBT_H_

#include <functional>

struct RbtNode {
    static constexpr int BLACK = 0;
    static constexpr int RED = 1;

    RbtNode(int _key = 0, int _color = BLACK,
        RbtNode* _parent = 0, RbtNode* _left = 0, RbtNode* _right = 0)
        : key(_key), color(_color), parent(_parent), left(_left), right(_right) {}

    // Data
    int key;
    int color;
    bool isNull = false;
    // Link
    RbtNode* parent = 0;
    RbtNode* left = 0;
    RbtNode* right = 0;
};


void preorder(RbtNode* tree, const std::function<void(RbtNode*)>& action);
void inorder(RbtNode* tree, const std::function<void(RbtNode*)>& action);
void postorder(RbtNode* tree, const std::function<void(RbtNode*)>& action);

// Get node whose key is equal to given parameter
// If not find, return nullptr
RbtNode* search(RbtNode* tree, int key);

// Get minimum node from given tree
RbtNode* min(RbtNode* tree);
// Get maximum node from given tree
RbtNode* max(RbtNode* tree);

// Get next node from given tree
RbtNode* successor(RbtNode* tree);
// Get previous node from given tree
RbtNode* predecessor(RbtNode* tree);

// Insert the key and then return changed root node
RbtNode* insertNode(RbtNode* tree, RbtNode* target);
// Delete the key and then return changed root node
RbtNode* deleteNode(RbtNode* tree, RbtNode* target);
#endif