#include "rbt.h"

// ===================
// =======Query=======
// ===================

void preorder(RbtNode* tree, const std::function<void(RbtNode*)>& action) {
    if (tree == 0) return;
    action(tree);
    preorder(tree->left, action);
    preorder(tree->right, action);
}
void inorder(RbtNode* tree, const std::function<void(RbtNode*)>& action) {
    if (tree == 0) return;
    inorder(tree->left, action);
    action(tree);
    inorder(tree->right, action);
}
void postorder(RbtNode* tree, const std::function<void(RbtNode*)>& action) {
    if (tree == 0) return;
    postorder(tree->left, action);
    postorder(tree->right, action);
    action(tree);
}

RbtNode* search(RbtNode* tree, int key) {
    while (tree != nullptr && tree->key != key) {
        if (key < tree->key)
            tree = tree->left;
        else
            tree = tree->right;
    }
    return tree;
}

RbtNode* min(RbtNode* tree) {
    while (tree->left) {
        tree = tree->left;
    }
    return tree;
}
RbtNode* max(RbtNode* tree) {
    while (tree->right) {
        tree = tree->right;
    }
    return tree;
}

RbtNode* successor(RbtNode* tree) {
    if (tree->right) {  // successor is in right subtree
        return min(tree->right);
    }
    // successor is in ancestor
    RbtNode* parent = tree->parent;
    while (parent != nullptr && tree != parent->left) {
        tree = parent;
        parent = parent->parent;
    }
    return parent;
}
RbtNode* predecessor(RbtNode* tree) {
    if (tree->left) {  // predecessor is in left subtree
        return max(tree->left);
    }
    // predecessor is in ancestor
    RbtNode* parent = tree->parent;
    while (parent != nullptr && tree != parent->right) {
        tree = parent;
        parent = parent->parent;
    }
    return parent;
}

// ===================
// ===Insert/Delete===
// ===================

inline int getColor(RbtNode* node) {
    return node == 0 ? RbtNode::BLACK : node->color;
}
inline int isBlack(RbtNode* node) { return getColor(node) == RbtNode::BLACK; }
inline int isRed(RbtNode* node) { return getColor(node) == RbtNode::RED; }

RbtNode* leftRotate(RbtNode* node) {
    if (node == 0 || node->right == 0) {
        return node;
    }
    RbtNode *x = node->right, *y = node, *z = node->parent;

    y->parent = x;
    y->right = x->left;
    if (x->left) x->left->parent = y;

    x->parent = z;
    x->left = y;

    if (z) {
        if (y == z->left)
            z->left = x;
        else
            z->right = x;
    }
    return y;
}
RbtNode* rightRotate(RbtNode* node) {
    if (node == 0 || node->left == 0) {
        return node;
    }
    RbtNode *x = node->left, *y = node, *z = node->parent;

    y->parent = x;
    y->left = x->right;
    if (x->right) x->right->parent = y;

    x->right = y;
    x->parent = z;

    if (z) {
        if (y == z->left)
            z->left = x;
        else
            z->right = x;
    }
    return y;
}

RbtNode* simpleInsert(RbtNode* tree, RbtNode* target) {
    if(tree == 0){
        return target;
    }
    int key = target->key;
    RbtNode* cursor = tree;

    while (cursor != nullptr && tree->key != key) {
        if (key < cursor->key) {
            if (cursor->left) {
                cursor = cursor->left;
            } else {
                cursor->left = target;
                target->parent = cursor;
                break;
            }
        } else {
            if (cursor->right) {
                cursor = cursor->right;
            } else {
                cursor->right = target;
                target->parent = cursor;
                break;
            }
        }
    }

    return tree;
}

RbtNode* insertNode(RbtNode* tree, RbtNode* target) {
    tree = simpleInsert(tree, target);
    target->color = target->parent ? RbtNode::RED : RbtNode::BLACK;

    // Rebalance
    while (target->parent != 0 && isRed(target->parent)) {
        RbtNode* parent = target->parent;
        RbtNode* grandParent = parent->parent;
        RbtNode* uncle = 0;

        if (parent == grandParent->left) {
            uncle = grandParent->right;
            if (isRed(uncle)) {
                // propagation
                grandParent->color = RbtNode::RED;
                parent->color = uncle->color = RbtNode::BLACK;

                target = grandParent;
            } else {
                if (target == parent->right) {  // left-rotate
                    leftRotate(parent);
                    std::swap(target, parent);
                }
                // right-rotate
                rightRotate(grandParent);
                parent->color = RbtNode::BLACK;
                grandParent->color = RbtNode::RED;
                if (parent->parent == 0) {
                    tree = parent;
                }
            }
        } else {
            uncle = grandParent->left;
            if (isRed(uncle)) {
                // propagation
                grandParent->color = RbtNode::RED;
                parent->color = uncle->color = RbtNode::BLACK;

                target = grandParent;
            } else {
                if (target == parent->left) {  // right-rotate
                    rightRotate(parent);
                    std::swap(target, parent);
                }
                // left-rotate
                leftRotate(grandParent);
                parent->color = RbtNode::BLACK;
                grandParent->color = RbtNode::RED;
                if (parent->parent == 0) {
                    tree = parent;
                }
            }
        }
    }
    tree->color = RbtNode::BLACK;
    return tree;
}

RbtNode* deleteFixup(RbtNode* tree, RbtNode* target) {
    while (target->parent != 0 && isBlack(target)) {
        RbtNode* parent = target->parent;
        if (target == parent->left) {
            RbtNode* sibling = parent->right;
            if (isRed(sibling)) { // Ensure sibling is Black
                parent->color = RbtNode::RED;
                sibling->color = RbtNode::BLACK;

                RbtNode* node = leftRotate(parent);
                if(node->parent == 0) {
                    tree = node;
                }
                sibling = parent->right;
            } 
            if(isBlack(sibling->left) && isBlack(sibling->right)){
                sibling->color = RbtNode::RED;
                target = parent;
                continue;
            } 

            if(isBlack(sibling->right)){ // Ensure sibling's right is Red
                sibling->color = RbtNode::RED;
                sibling->right->color = RbtNode::BLACK;
                sibling = rightRotate(sibling);
            } 
            sibling->color = parent->color;
            parent->color = RbtNode::BLACK;
            sibling->right->color = RbtNode::BLACK;
            parent = leftRotate(parent);
            if(parent->parent == 0){
                tree = parent;
            }
            break;
        } else {
            RbtNode* sibling = parent->left;
            if (isRed(sibling)) { // Ensure sibling is Black
                parent->color = RbtNode::RED;
                sibling->color = RbtNode::BLACK;

                RbtNode* node = rightRotate(parent);
                if(node->parent == 0) {
                    tree = node;
                }
                sibling = parent->left;
            } 
            if(isBlack(sibling->right) && isBlack(sibling->left)){
                sibling->color = RbtNode::RED;
                target = parent;
                continue;
            } 

            if(isBlack(sibling->left)){ // Ensure sibling's left is Red
                sibling->color = RbtNode::RED;
                sibling->left->color = RbtNode::BLACK;
                sibling = leftRotate(sibling);
            } 
            sibling->color = parent->color;
            parent->color = RbtNode::BLACK;
            sibling->left->color = RbtNode::BLACK;
            parent = rightRotate(parent);
            if(parent->parent == 0){
                tree = parent;
            }
            break;
        }
    }
    target->color = RbtNode::BLACK;
    return tree;
}

RbtNode* deleteNode(RbtNode* tree, RbtNode* target) {
    RbtNode* victim = 0;  // Find real deleted target
    if (target->left == 0 || target->right == 0) {
        victim = target;
    } else {
        victim = successor(target);
    }
    target->key = victim->key;

    RbtNode* subTree = 0;  // Join sub-tree after deleted
    if (victim->left) {
        subTree = victim->left;
    } else if (victim->right) {
        subTree = victim->right;
    }

    if (subTree) {
        subTree->parent = victim->parent;
    }
    if (victim->parent == 0) {
        tree = subTree;
    } else if (victim == victim->parent->left) {
        victim->parent->left = subTree;
    } else {
        victim->parent->right = subTree;
    }

    if (victim->color == RbtNode::BLACK) {
        tree = deleteFixup(tree, subTree);
    }
    delete victim;
    return tree;
}