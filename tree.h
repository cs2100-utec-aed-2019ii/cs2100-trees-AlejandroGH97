#ifndef TREE_H
#define TREE_H

#include "node.h"

using namespace std;

template<typename T>
class Tree{
    private:
    Node<T>* root;

    public:

    Tree():root{nullptr};
    Tree(T& val){
        root = new Node<T>(val);
    }

    ~Tree(){};

    void insert(T& val){
        if(root){
            insert(root,val);       
        }
        else{
            root = new Node<T>(val);
        }
    }//end insert

    void insert(Node<T>* temp, T& val){
        if(val > temp->value){
            if(temp->right){
                insert(temp->right, val);
            }
            else{
                temp->right = new Node<T>(val);
            }
        }
        else if(val < temp->value){
            if(temp->left){
                insert(temp->left, val);
            }
            else{
                temp->left = new Node<T>(val);
            }        
        }
        else{
            cout<<"Key already in use."<<endl;
            return;
            }
    }//end insert

    void deleteNode(T& val){
        
    }//end deleteNode



};


#endif
