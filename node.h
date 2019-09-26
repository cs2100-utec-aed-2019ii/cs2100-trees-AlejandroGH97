#ifndef NODE_H
#define NODE_H
template<typename T>
struct Node{

    Node<T>* left;
    Node<T>* right;
    Node<T>* next;
    Node<T>* prev;
    Node<T>* parent;
    T value;

    Node(T val):value{val},left{nullptr},right{nullptr},next{nullptr},prev{nullptr},parent{nullptr}{};

    Node(Node<T>* parent, T val):value{val},left{nullptr},right{nullptr},next{nullptr},prev{nullptr},parent{parent}{};

    ~Node<T>(){};
};
#endif
