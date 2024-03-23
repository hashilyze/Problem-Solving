#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

struct BstNode {
    BstNode() : key(0) {}
    BstNode(int key) : key(key) {}
    BstNode(int key, BstNode* parent, BstNode* left, BstNode* right)
        : key(key), parent(parent), left(left), right(left) {}

    int key;
    BstNode* parent = 0;
    BstNode* left = 0;
    BstNode* right = 0;
};

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

// Get node whose key is equal to given parameter
// If not find, return nullptr
BstNode* search(BstNode* tree, int key) {
    while (tree != nullptr && tree->key != key) {
        if (key < tree->key)
            tree = tree->left;
        else
            tree = tree->right;
    }
    return tree;
}

// Get minimum node from given tree
BstNode* min(BstNode* tree) {
    while (tree->left) {
        tree = tree->left;
    }
    return tree;
}

// Get maximum node from given tree
BstNode* max(BstNode* tree) {
    while (tree->right) {
        tree = tree->right;
    }
    return tree;
}

// Get next node from given tree
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

// Get previous node from given tree
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

// Insert the key and then return changed root node
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

// Delete the key and then return changed root node
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
        } else if (target->left == 0 && target->right ||
                   target->left &&
                       target->right == 0) {  // Have left or right child
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
            BstNode* parent = target->parent;
            BstNode* replacement = successor(target);
            std::swap(target->key, replacement->key);
            target = replacement;
        }
    }
    return root;
}

int main(void) {
    const int TEST_SIZE = 10;

    std::vector<int> items;
    for (int i = 0; i < TEST_SIZE; ++i) {
        items.push_back(i);
    }
    std::random_shuffle(items.begin(), items.end());

    std::cout << "Sequence of insertion\n";
    std::for_each(items.cbegin(), items.cend(),
                  [](int elem) { std::cout << elem << ", "; });
    std::cout << "\n";

    BstNode* root = 0;
    for (int item : items) {
        if (root) {
            insertNode(root, item);
        } else {
            root = new BstNode(item);
        }
    }

    std::cout << "\nTree Structure\n";
    std::cout << "Preorder: ";
    preorder(root, [](BstNode* node) { std::cout << node->key << ", "; });
    std::cout << "\nInorder : ";
    inorder(root, [](BstNode* node) { std::cout << node->key << ", "; });
    std::cout << "\n";

    std::cout << "\nQuery\n";
    std::cout << "max: " << max(root)->key << '\n';
    std::cout << "min: " << min(root)->key << '\n';

    BstNode* cursor = 0;
    std::cout << "\nAscending Iteration(Successor)\n";
    cursor = min(root);
    while (cursor) {
        std::cout << cursor << ": " << cursor->key << '\n';
        cursor = successor(cursor);
    }
    std::cout << "\nDescending Iteration(Predecessor)\n";
    cursor = max(root);
    while (cursor) {
        std::cout << cursor << ": " << cursor->key << '\n';
        cursor = predecessor(cursor);
    }

    std::random_shuffle(items.begin(), items.end());
    std::cout << "Sequence of deletion\n";
    std::for_each(items.cbegin(), items.cend(),
                  [](int elem) { std::cout << elem << ", "; });
    std::cout << "\n\n";

    for (int item : items) {
        root = deleteNode(root, item);
        std::cout << "delete(" << item << "): ";
        inorder(root, [](BstNode* node) { std::cout << node->key << ", "; });
        std::cout << '\n';
    }

    return 0;
}