#ifndef NODE_H
#define NODE_H
template<typename T>
struct Node{
    Node<T>* left, right, next;
    T value;

    Node(T val):value{val},left{nullptr},right{nullptr},next{nullptr}{};
    ~Node<T>(){};
};
#endif
