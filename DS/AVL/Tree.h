#ifndef TREE_H_
#define TREE_H_
#include <functional>
#include <iostream>

template<typename Key_ty>
class Tree {
public:
    virtual void Insert(const Key_ty& key) = 0;
    virtual void Delete(const Key_ty& key) = 0;
    virtual bool Contain(const Key_ty& key) = 0;

    virtual void PreOrder(std::function<void(const Key_ty&)> action) = 0;
    virtual void PostOrder(std::function<void(const Key_ty&)> action) = 0;
    virtual void InOrder(std::function<void(const Key_ty&)> action) = 0;
};
#endif