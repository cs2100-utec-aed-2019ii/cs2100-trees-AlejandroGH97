#include<iostream>
#include "tree.h"

using namespace std;

int main(){

    Tree<int>* tree = new Tree<int>;
    Tree<int>* tree2 = new Tree<int>;
    
    tree->deleteNode(60);
    tree->insert(60);
    cout<<tree->getRoot()->value<<endl;
    tree->deleteNode(60);
    tree->insert(40);
    //cout<<tree->getRoot()->value<<endl;

    //Height tests
    //cout<<tree->height()<<endl; //Height = 0
    //tree->insert(20);
    //cout<<"Height: "<<tree->height()<<endl; //Height = 1
    //tree->deleteNode(20);
    //cout<<"Height: "<<tree->height()<<endl; // Height = 0

    /*
                        40
            20                    60
        12      28            55      64
                    37     52    56

    */

    tree->insert(20);
    tree->insert(60);
    tree->insert(55);
    tree->insert(56);
    //tree->insert(57);
    tree->insert(52);
    tree->insert(64);
    tree->insert(28);
    tree->insert(37);
    tree->insert(12);

    cout<<tree->heightBalanced()<<endl;
    //tree->deleteNode(40);
    //cout<<tree->getRoot()->value<<endl; //new node 37

    tree->inOrder();
    cout<<endl;
    tree->postOrder();
    cout<<endl;
    tree->preOrder();
    cout<<endl;
    tree->ancestors(52);
    cout<<endl;
    cout<<tree->equalTrees(tree);
    cout<<endl;
    tree->rootToLeaf();
    cout<<endl;
    cout<<tree->isBST()<<endl;

    tree2->insert(20);

    tree2->getRoot()->right = new Node<int>(10); //Not a BST
    
    cout<<tree2->isBST()<<endl;

    //cout<<tree->getRoot()->right->left->right->next->value<<endl; //56->next = 37

    cout<<tree->next(20)<<endl; 

    /*BT structure
                        20
                  40        10
              13      8  32    38
    */

    tree2->getRoot()->left = new Node<int>(40);
    tree2->getRoot()->left->left = new Node<int>(13);
    tree2->getRoot()->left->right = new Node<int>(8);
    tree2->getRoot()->right->left = new Node<int>(32);
    tree2->getRoot()->right->right = new Node<int>(38);

    tree2->inOrder();
    cout<<endl;
    tree2->convert();
    tree2->inOrder();
    cout<<endl;

    if(tree->complete()){
        cout<<"Tree1 is complete\n";
    }
    else{
        cout<<"Tree1 not complete\n";
    }

    tree2->insert(5);

    if(tree2->complete()){
        cout<<"Tree2 is complete\n";
    }
    else{
        cout<<"Tree2 not complete\n";
    }


    return 0;
}