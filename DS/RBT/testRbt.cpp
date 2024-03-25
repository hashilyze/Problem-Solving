#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include "rbt.h"

const char COLOR_INITIAL[] = { 'B', 'R' };

void showTree(RbtNode* root){
        std::cout << "Preorder: ";
        preorder(root, [](RbtNode* node) { std::cout << node->key << "(" << COLOR_INITIAL[node->color]<< ")" << ", "; });
        std::cout << "\nInorder : ";
        inorder(root, [](RbtNode* node) { std::cout << node->key << "(" << COLOR_INITIAL[node->color]<< ")" << ", "; });
        std::cout << "\n";
}

int main(void) {
    char command;
    int key;

    RbtNode* root = 0;
    while(std::cin >> command >> key){
        if(key < 0){
            break;
        }

        switch(command){
        case 'i':{
            root = insertNode(root, new RbtNode(key));
        } break;
        case 'd':{
            root = deleteNode(root, search(root, key));
        } break;
        case 'c':{
            RbtNode* item = search(root, key);
            std::cout << "color(" << key << "): " 
                << (item->color == RbtNode::BLACK ? "BLACK" : "RED")
                << '\n';
        } break;
        }
        showTree(root);
    }
    return 0;
}