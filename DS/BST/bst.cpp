#include "bst.h"

// ===================
// =======Query=======
// ===================

void preorder(BstNode* tree, const std::function<void(BstNode*)>& action) {
    if (tree == 0) return;
    action(tree);
    preorder(tree->left, action);
    preorder(tree->right, action);
}
void inorder(BstNode* tree, const std::function<void(BstNode*)>& action) {
    if (tree == 0) return;
    inorder(tree->left, action);
    action(tree);
    inorder(tree->right, action);
}
void postorder(BstNode* tree, const std::function<void(BstNode*)>& action) {
    if (tree == 0) return;
    postorder(tree->left, action);
    postorder(tree->right, action);
    action(tree);
}

BstNode* search(BstNode* tree, int key) {
    while (tree != nullptr && tree->key != key) {
        if (key < tree->key)
            tree = tree->left;
        else
            tree = tree->right;
    }
    return tree;
}

BstNode* min(BstNode* tree) {
    while (tree->left) {
        tree = tree->left;
    }
    return tree;
}

BstNode* max(BstNode* tree) {
    while (tree->right) {
        tree = tree->right;
    }
    return tree;
}

BstNode* successor(BstNode* tree) {
    if (tree->right) {  // successor is in right subtree
        return min(tree->right);
    }
    // successor is in ancestor
    BstNode* parent = tree->parent;
    while (parent != nullptr && tree != parent->left) {
        tree = parent;
        parent = parent->parent;
    }
    return parent;
}

BstNode* predecessor(BstNode* tree) {
    if (tree->left) {  // predecessor is in left subtree
        return max(tree->left);
    }
    // predecessor is in ancestor
    BstNode* parent = tree->parent;
    while (parent != nullptr && tree != parent->right) {
        tree = parent;
        parent = parent->parent;
    }
    return parent;
}

// ===================
// ===Insert/Delete===
// ===================

BstNode* insertNode(BstNode* tree, int key) {
    BstNode* cursor = tree;
    while (cursor != nullptr && tree->key != key) {
        if (key < cursor->key) {
            if (cursor->left) {
                cursor = cursor->left;
            } else {
                cursor->left = new BstNode(key, cursor, 0, 0);
                break;
            }
        } else {
            if (cursor->right) {
                cursor = cursor->right;
            } else {
                cursor->right = new BstNode(key, cursor, 0, 0);
                break;
            }
        }
    }
    return tree;
}

BstNode* deleteNode(BstNode* tree, int key) {
    BstNode* target = search(tree, key);
    BstNode* root = tree;

    while (target != 0) {
        if (target->left == 0 && target->right == 0) {  // No children
            BstNode* parent = target->parent;
            if (parent) {
                if (parent->left == target) {
                    parent->left = 0;
                } else {
                    parent->right = 0;
                }
            } else {
                root = 0;
            }
            delete target;
            target = 0;
        } else if ((target->left == 0 && target->right != 0) ||
                   (target->left != 0 &&
                    target->right == 0)) {  // Have left or right child
            BstNode* parent = target->parent;
            BstNode* child = target->left ? target->left : target->right;
            if (parent) {
                if (parent->left == target) {
                    parent->left = child;
                } else {
                    parent->right = child;
                }
                child->parent = parent;

            } else {
                root = child;
                child->parent = 0;
            }
            delete target;
            target = 0;
        } else {  // Have both
            BstNode* replacement = successor(target);
            std::swap(target->key, replacement->key);
            target = replacement;
        }
    }
    return root;
}