#include <iostream>
#include <algorithm>
#include <vector>
#include "bst.h"

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
            root = insertNode(root, item).first;
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
    std::cout << "\nSequence of deletion\n";
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