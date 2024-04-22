#ifndef AVL_H_
#define AVL_H_
#include "Tree.h"
#include <stdexcept>

template<typename Key_ty>
class AVL : public Tree<Key_ty> {
public:
    struct AVLNode{
    public:
        AVLNode() { }
        AVLNode(const Key_ty& key) : _key(key) { }
    public:
        Key_ty _height = 1;
        Key_ty _key;
        AVLNode* _parent = 0;
        AVLNode* _left = 0;
        AVLNode* _right = 0;
    };
public:
    void Insert(const Key_ty& key);
    void Delete(const Key_ty& key);
private:
    static void SetChild(AVLNode* parent, AVLNode*& placeHolder, AVLNode* child);
    static void SetLeftChild(AVLNode* parent, AVLNode* child);
    static void SetRightChild(AVLNode* parent, AVLNode* child);

    static inline int GetLeftHeight(AVLNode* node) { return node->_left != nullptr ? node->_left->_height : 0; }
    static inline int GetRightHeight(AVLNode* node) { return node->_right != nullptr ? node->_right->_height : 0; }
    static inline int GetBalance(AVLNode* node) { return GetLeftHeight(node) - GetRightHeight(node); }
    static inline int GetHeight(AVLNode* node) { return std::max(GetLeftHeight(node), GetRightHeight(node)) + 1; }
    
    void Rebalance(AVLNode* node);
    static AVLNode* RotateLeft(AVLNode* node);
    static AVLNode* RotateRight(AVLNode* node);

public:
    bool Contain(const Key_ty& key) { return Search(key) != nullptr; }
private:
    static AVLNode* GetPredecessor(AVLNode* node);
    static AVLNode* GetSuccessor(AVLNode* node);
    AVLNode* Search(const Key_ty& key);

public:
    void PreOrder(std::function<void(const Key_ty&)> action) { AVL::PreOrder(_root, action); }
    void PostOrder(std::function<void(const Key_ty&)> action) { AVL::PostOrder(_root, action); }
    void InOrder(std::function<void(const Key_ty&)> action) { AVL::InOrder(_root, action); }
private:
    static void PreOrder(AVLNode* node, std::function<void(const Key_ty&)> action);
    static void PostOrder(AVLNode* node, std::function<void(const Key_ty&)> action);
    static void InOrder(AVLNode* node, std::function<void(const Key_ty&)> action);

private:
    AVLNode* _root = 0;
};

// Update
template<typename Key_ty>
void AVL<Key_ty>::SetChild(AVLNode* parent, AVLNode*& placeHolder, AVLNode* child){
    placeHolder = child;
    if(child != nullptr){
        child->_parent = parent;
    }
    parent->_height = GetHeight(parent);
}
template<typename Key_ty>
void AVL<Key_ty>::SetLeftChild(AVLNode* parent, AVLNode* child){ SetChild(parent, parent->_left, child); }
template<typename Key_ty>
void AVL<Key_ty>::SetRightChild(AVLNode* parent, AVLNode* child){ SetChild(parent, parent->_right, child); }

// Update
template<typename Key_ty>
void AVL<Key_ty>::Insert(const Key_ty& key){
    if(_root == nullptr){
        _root = new AVLNode(key);
        return;
    }

    AVLNode* ptr = _root;
    while(true){
        AVLNode** placeHolder;
        if(key < ptr->_key){
            placeHolder = &ptr->_left;
        } else if (key > ptr->_key){
            placeHolder = &ptr->_right;
        } else{
            throw std::overflow_error("Already inserted item");
        }

        if(*placeHolder == nullptr){
            SetChild(ptr, *placeHolder, new AVLNode(key));
            Rebalance(ptr);
            return;
        }
        ptr = *placeHolder;
    }
}

template<typename Key_ty>
void AVL<Key_ty>::Delete(const Key_ty& key){
    AVLNode* target = Search(key);
    if(target == nullptr){
        return;
    }
    AVLNode* replacement;
    AVLNode* rebalancePointer;
    if(target->_left == nullptr && target->_right == nullptr){ // leaf node
        replacement = nullptr;
        rebalancePointer = target->_parent;
    } else if(target->_left != nullptr && target->_right != nullptr){
        AVLNode* prev = GetPredecessor(target);
        replacement = prev;
        if (prev == target->_left) {
            rebalancePointer = prev;
			SetRightChild(prev, target->_right);
        } else {
            rebalancePointer = prev->_parent;
            SetRightChild(prev->_parent, prev->_left);

            SetLeftChild(prev, target->_left);
            SetRightChild(prev, target->_right);
        }
    } else {
        rebalancePointer = target->_parent;
		if(target->_left != nullptr) {
            replacement = target->_left;
        } else {
            replacement = target->_right;
        }
    }
	
    if(target == _root){
        _root = replacement;
		if(replacement != nullptr){
            replacement->_parent = nullptr;
        }
    } else {
        if(target->_parent->_left == target){
            SetLeftChild(target->_parent, replacement);
        } else {
            SetRightChild(target->_parent, replacement);
        }
    }
	if(rebalancePointer != nullptr){
		Rebalance(rebalancePointer);
	}

    delete target;
}

template<typename Key_ty>
void AVL<Key_ty>::Rebalance(AVLNode* node){
    while(node != nullptr){
        int balance = GetBalance(node);
        if(balance <= -2){ // RR or RL
            AVLNode* newRoot;
            AVLNode* rightNode = node->_right;
            if(GetBalance(rightNode) < 0){ // RR
                newRoot = RotateLeft(node);
            } else { // RL
                RotateRight(node->_right);
                newRoot = RotateLeft(node);
            }

            if(node == _root){
                _root = newRoot;
            }
            node = newRoot;
        } else if(balance >= 2){ // LL or LR
            AVLNode* newRoot;
            AVLNode* leftNode = node->_left;
            if(GetBalance(leftNode) > 0){ // LL
                newRoot = RotateRight(node);
            } else { // LR
                RotateLeft(node->_left);
                newRoot = RotateRight(node);                            
            }

            if(node == _root){
                _root = newRoot;
            }
            node = newRoot;
        } else{
            node = node->_parent;
        }
    }
}

template<typename Key_ty>
auto AVL<Key_ty>::RotateLeft(AVLNode* node) -> AVLNode*{
    AVLNode* newLeft = node;
    AVLNode* newRoot = node->_right;
    AVLNode* newRight = node->_right->_right;
    AVLNode* parent = node->_parent;

    SetRightChild(newLeft, newRoot->_left);
    SetLeftChild(newRoot, newLeft);
    if(parent){
        if(parent->_left == newLeft){
            SetLeftChild(parent, newRoot);
        } else{
            SetRightChild(parent, newRoot);
        }
    }
    return newRoot;
}
template<typename Key_ty>
auto AVL<Key_ty>::RotateRight(AVLNode* node) -> AVLNode*{
    AVLNode* newLeft = node->_left->_left;
    AVLNode* newRoot = node->_left;
    AVLNode* newRight = node;
    AVLNode* parent = node->_parent;

    SetLeftChild(newRight, newRoot->_right);
    SetRightChild(newRoot, newRight);
    if(parent){
        if(parent->_left == newRight){
            SetLeftChild(parent, newRoot);
        } else{
            SetRightChild(parent, newRoot);
        }
    }
    return newRoot;
}

// Search
template<typename Key_ty>
auto AVL<Key_ty>::Search(const Key_ty& key) -> AVLNode*{
    AVLNode* ptr = _root;
    while(ptr != nullptr){
        if(key < ptr->_key){
            ptr = ptr->_left;
        } else if(key > ptr->_key){
            ptr = ptr->_right;
        } else{
            break;
        }
    }
    return ptr;
}
template<typename Key_ty>
auto AVL<Key_ty>::GetPredecessor(AVLNode* root) -> AVLNode*{
    AVLNode* prev = root->_left;
    if(prev){
        while(prev->_right != nullptr){
            prev = prev->_right;
        }
    }
    return prev;
}
template <typename Key_ty>
auto AVL<Key_ty>::GetSuccessor(AVLNode* root) -> AVLNode* {
    AVLNode* next = root->_right;
    if (next) {
        while (next->_left != nullptr) {
            next = next->_left;
        }
    }
    return next;
}

// Traverses
template<typename Key_ty>
void AVL<Key_ty>::PreOrder(AVLNode* node, std::function<void(const Key_ty&)> action) { 
    if(node == nullptr) return;
    action(node->_key);
    PreOrder(node->_left, action);
    PreOrder(node->_right, action);
}
template<typename Key_ty>
void AVL<Key_ty>::PostOrder(AVLNode* node, std::function<void(const Key_ty&)> action) { 
    if(node == nullptr) return;
    PostOrder(node->_left, action);
    PostOrder(node->_right, action);
    action(node->_key);
}
template<typename Key_ty>
void AVL<Key_ty>::InOrder(AVLNode* node, std::function<void(const Key_ty&)> action) { 
    if(node == nullptr) return;
    InOrder(node->_left, action);
    action(node->_key);
    InOrder(node->_right, action);
}
#endif