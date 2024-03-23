#ifndef BST_H_
#define BST_H_

#include <functional>

struct BstNode {
    BstNode() : key(0) {}
    BstNode(int key) : key(key) {}
    BstNode(int key, BstNode* parent, BstNode* left, BstNode* right)
        : key(key), parent(parent), left(left), right(right) {}

    int key;
    BstNode* parent = 0;
    BstNode* left = 0;
    BstNode* right = 0;
};


void preorder(BstNode* tree, const std::function<void(BstNode*)>& action);
void inorder(BstNode* tree, const std::function<void(BstNode*)>& action);
void postorder(BstNode* tree, const std::function<void(BstNode*)>& action);


// Get node whose key is equal to given parameter
// If not find, return nullptr
BstNode* search(BstNode* tree, int key);

// Get minimum node from given tree
BstNode* min(BstNode* tree);
// Get maximum node from given tree
BstNode* max(BstNode* tree);

// Get next node from given tree
BstNode* successor(BstNode* tree);
// Get previous node from given tree
BstNode* predecessor(BstNode* tree);

// Insert the key and then return changed root node
BstNode* insertNode(BstNode* tree, int key);
// Delete the key and then return changed root node
BstNode* deleteNode(BstNode* tree, int key);
#endif