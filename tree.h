#ifndef TREE_H
#define TREE_H

#include "node.h"
#include <vector>
#include <queue>

using namespace std;

template<typename T>
class Tree{
    private:
    Node<T>* root;

    public:

    Tree():root{nullptr}{};

    ~Tree(){
        clear(root);
    };

    Node<T>* getRoot(){
        if(root){
        return root;
        }
        else{
            cout<<"Null root"<<endl;
            return root;
        }
    }

    void insert(T val){
        if(root != nullptr ){
            insert(root,val);       
        }
        else{
            cout<<"Inserted in root."<<endl<<endl;
            root = new Node<T>(val);
        }
        clear_LL();
        create_LL();
    }//end insert

    void insert(Node<T>* temp, T& val){
        if(val > temp->value){
            if(temp->right != nullptr){
                cout<<"Insert moved right from value: "<<temp->value<<endl;
                insert(temp->right, val);
            }
            else{
                cout<<"Inserted right of "<<temp->value<<endl<<endl;
                temp->right = new Node<T>(temp,val);
            }
        }
        else if(val < temp->value){
            if(temp->left != nullptr){
                cout<<"Insert moved left from value: "<<temp->value<<endl;
                insert(temp->left, val);
            }
            else{
                cout<<"Inserted left of "<<temp->value<<endl<<endl;
                temp->left = new Node<T>(temp,val);
            }        
        }
        else{
            cout<<"Key already in use."<<endl<<endl;
            return;
            }
    }//end insert

    Node<T>* findMax(Node<T>* temp){
        while(temp->right){
            temp = temp->right;
        }
        return temp;
    }

    void deleteNode(T val){
        if(!root){
            cout<<"Nothing to delete.\n"<<endl;
        }
        else{
            deleteNode(val, root);
            clear_LL();
            create_LL();
        }
        
    }

    void deleteNode(T val, Node<T>* temp){

        if(val > temp->value && temp->right){//go right
            cout<<"Delete moved right."<<endl;
            deleteNode(val,temp->right);
        }
        
        else if(val < temp->value && temp->left){//go left
            cout<<"Delete moved left."<<endl;
            deleteNode(val,temp->left);
        }

        else if(val == temp->value){//start delete

            if(!(temp->left) && !(temp->right)){//no child
            cout<<"No child delete with value: "<<temp->value<<endl<<endl;

                if(temp == root){
                    root = nullptr;
                }
                if(temp->parent){
                    if(temp->parent->right == temp){
                        temp->parent->right = nullptr;
                    }
                    else{
                        temp->parent->left = nullptr;
                    }
                }
                delete temp;
                temp = nullptr;
            }

            else if(temp->left && !(temp->right)){//only left child

                cout<<"Only left child delete.\n"<<endl;

                temp->left->parent = temp->parent;

                if(temp == root){
                    root = temp->left;
                    root->parent = nullptr;
                }
                else if(temp->parent->right == temp){
                    temp->parent->right = temp->left;
                }
                else{
                    temp->parent->left = temp->left;
                }

                delete temp;
                temp = nullptr;
            }
            else if(!(temp->left) && temp->right){//only right child

                cout<<"Only right child delete.\n"<<endl;

                temp->right->parent = temp->parent;

                if(temp == root){
                    root = temp->right;
                    root->parent = nullptr;
                }
                else if(temp->parent->right == temp){
                    temp->parent->right = temp->right;
                }
                else{
                    temp->parent->left = temp->right;
                }

                delete temp;
                temp = nullptr;
            }
            else{//has both childs
                cout<<"Both children"<<endl;

                Node<T>* replacement = findMax(temp->left);
                //cout<<"findmax"<<replacement->value<<"\n";

                if(replacement->left){//replacement has left child -> place in replacements place
                    replacement->parent->right = replacement->left;
                    replacement->left->parent = replacement->parent;
                }
                //--------place replacement in new spot
                if(temp == root){
                    root = replacement;
                }
                else if(temp->parent->right == temp){
                    temp->parent->right = replacement;
                }
                else{
                    temp->parent->left = replacement;

                }
                replacement->left = temp->left;
                replacement->right = temp->right;
                replacement->parent = temp->parent;
        
                delete temp;
                temp = nullptr;

                }
                
        }
        else{
            cout<<"Value not found."<<endl;
            
        }//end delete

    }//end deleteNode

    void clear(Node<T>* _root){

        if (_root) {
            clear(_root->left);
            clear(_root->right);

            delete _root;
        }
        root = nullptr;
    }

    int height(){
        int left = 0;
        int right = 0;

        if(root->left){
            //cout<<"Height root L"<<endl;
            left = 1 + height(root->left);
        }
        
        if(root->right){
            //cout<<"Height root R"<<endl;
            right = 1 + height(root->right);
        }
        
        return (right>left)?right:left;
    }

    int height(Node<T>* node){
        int left = 0;
        int right = 0;

        if(node->left){
            //cout<<"Height L"<<endl;
            left = 1 + height(node->left);
        }
        
        if(node->right){
            //cout<<"Height R"<<endl;
            right = 1 + height(node->right);
        }

        return (right>left)?right:left;
        
    }

    bool heightBalanced(){
        
            if(root->right && root->left){
                return height(root->right) == height(root->left);
            }
            else if(!root->right && !root->left){
                return true;
            }
            else{
                return false;
            }
        
    }

    void inOrder(){
        if(root){
            inOrder(root->left);
            cout<<root->value<<" ";
            inOrder(root->right);
        }
    }

    void inOrder(Node<T>* node){
        if(node){
            inOrder(node->left);
            cout<<node->value<<" ";
            inOrder(node->right);
        }
    }

    void postOrder(){
        if(root){
            postOrder(root->left);
            postOrder(root->right);
            cout<<root->value<<" ";
        }
    }

    void postOrder(Node<T>* node){
        if(node){
            postOrder(node->left);
            postOrder(node->right);
            cout<<node->value<<" ";
        }
    }

    void preOrder(){
        if(root){
            cout<<root->value<<" ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    void preOrder(Node<T>* node){
        if(node){
            cout<<node->value<<" ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }



    void ancestors(T val){
        Node<T>* temp = root;

        if(!root){
            cout<<"Empty tree."<<endl;
        }
        else if(val == root->value){
            cout<<"Root has no ancestors."<<endl;            
        }
        else{
            ancestors(val, root);
        } 
    }

    void ancestors(T val, Node<T>* temp){
        if(val > temp->value && temp->right){//go right
            cout<<"Ancestors moved right."<<endl;
            ancestors(val,temp->right);
        }
        
        else if(val < temp->value && temp->left){//go left
            cout<<"Ancestors moved left."<<endl;
            ancestors(val,temp->left);
        }
        else if(val == temp->value){

            while(temp != root){
                temp = temp->parent;
                cout<<temp->value<<" ";
            }
        }
        // else{
        //     cout<<"Value not found."<<endl;
        // }
    }

    bool equalTrees(Tree<T>* tree){
        return equalTrees(this->root,tree->root);
    }

    bool equalTrees(Node<T>* node1, Node<T>* node2){
        if(node1 && node2){

            if(node1->value == node2->value){

                if(node1->left && node2->left && node1->right && node2->right){
                    return equalTrees(node1->left,node2->left) && equalTrees(node1->right,node2->right); 
                }

                else if(node1->left && node2->left && !node1->right && !node2->right){
                    return equalTrees(node1->left,node2->left);
                }

                else if(!node1->left && !node2->left && node1->right && node2->right){
                    return equalTrees(node1->right,node2->right);
                }

                else if(!node1->left && !node2->left && !node1->right && !node2->right){
                    return true;
                }

                else{
                    return false;
                }

            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }

    void rootToLeaf(){
        if(root){
            rootToLeaf(root);
        }
        else{
            cout<<"Empty tree."<<endl;
        }
    }

    void rootToLeaf(Node<T>* node){
        if(node->left){
            rootToLeaf(node->left);
        }
        if(node->right){
            rootToLeaf(node->right);
        }
        if(!node->left && !node->right){
            leafToRoot(node);
        }
    }

    void leafToRoot(Node<T>* node){
        while(node != root){
            cout<<node->value<<" ";
            node = node->parent;
        }
        cout<<node->value<<endl;
    }

    bool isBST(){
        if(root){
            return isBST(root);
        }
        else{
            return true;
        }
    }
    
    bool isBST(Node<T>* node){
        Node<T>* tempNode = node;

        while(tempNode != root){
            if(tempNode == tempNode->parent->right && node->value < tempNode->parent->value){
                return false;
            }
            else if(tempNode == tempNode->parent->left && node->value > tempNode->parent->value){
                return false;
            }
            else{
                tempNode = tempNode->parent;
            }
        }

        if(node->left && node->right){
            node->left->parent = node;
            return isBST(node->left) && isBST(node->right);
        }
        else if(node->left){
            node->right->parent = node;
            return isBST(node->left);
        }
        else if(node->right){
            node->right->parent = node;
            return isBST(node->right);
        }
        else{
            return true;
        }

    }

    int level(Node<T>* node){
        int level = 0;

        while(node != root){
            node = node->parent;
            level++;
        }

        return level;

    }

    void create_LL(){
        vector<Node<T>*> llist;
        Node<T>* node = root;
        if(root){
            if(!node->left && !node->right){
                llist.push_back(node);
            }
            else{
                if(node->left){
                    create_LL(llist,node->left);
                }
                if(node->right){
                    create_LL(llist,node->right);
                }
            }
            cout<<"Creating Double Linked List:\n";
            if(llist.size() == 1){
                cout<<"0: "<<llist[0]->value<<endl;
                llist[0]->next = llist[0];
                llist[0]->prev = llist[0];
            }
            else{

                for(unsigned int i = 0 ; i < llist.size() - 1 ; i++){
                    cout<<i<<": "<<llist[i]->value<<" ";
                    llist[i]->next = llist[i+1];
                    llist[i+1]->prev = llist[i];
                }

                llist[0]->prev = llist[llist.size()-1];
                llist[llist.size()-1]->next = llist[0];
                cout<<llist.size()-1<<": "<<llist[llist.size()-1]->value<<" ";
            }
            cout<<endl;
        }

    }

    void create_LL(vector<Node<T>*> &llist, Node<T>* node){
        cout<<"Checking node "<<node->value<<endl;
        if(level(node) == height()){
            cout<<"pass"<<endl;
            llist.push_back(node);
        }
        else{
            cout<<"fail"<<endl;
            if(node->left){
                create_LL(llist,node->left);
            }
            if(node->right){
                create_LL(llist,node->right);
            }
            
        }
        
    }

    void clear_LL(){
        if(root){
            root->next = nullptr;
            root->prev = nullptr;
            if(root->right){
                clear_LL(root->right);
            }
            if(root->left){
                clear_LL(root->left);
            }
        }
     }

     void clear_LL(Node<T>* node){
         node->next = nullptr;
         node->prev = nullptr;
         if(node->right){
             clear_LL(node->right);
         }
         if(node->left){
             clear_LL(node->left);
         }
     }

     Node<T>* find(T val){
         if(root){
             if(root->value == val){
                 return root;
             }
             else{
                 return find(root, val);
             }
         }
         else{
             cout<<"Empty tree.\n";
             return nullptr;
         }
     }

     Node<T>* find(Node<T>* node, T val){
         if(node->value == val){
             return node;
         }
         else if(node->value > val && node->left){
             return find(node->left,val);
         }
         else if(node->value < val && node->right){
             return find(node->right, val);
         }
         else{
             cout<<"Node not found.\n";
             return nullptr;
         }
     }

     T next(T val){

         if(!find(val)){
             return -1;
         }
        int nLevel = level(find(val));

        queue<Node<T>*> nodeQueue;

        Node<T>* node;

        nodeQueue.push(root);

        while(!nodeQueue.empty()){

            node = nodeQueue.front();
            nodeQueue.pop();

            if(level(node) == nLevel){
                if(node->value > val){
                    return node->value;
                }
                else{
                    continue;
                }
            }
            if(node->left){
                nodeQueue.push(node->left);
            }
            if(node->right){
                nodeQueue.push(node->right);
            }
            
        }

        return -1;

     }

     void convert(){
         while(!isBST()){
            convert(root);
         }
         cout<<"Conversion complete.\n";
     }

     void convert(Node<T>* node){

        T tempVal = node->value;
        Node<T>* tempNode = node;


        if(node->left){
            node->left->parent = node;
            convert(node->left);
        }
        if(node->right){
            node->right->parent = node;
            convert(node->right);
        }

        while(tempNode != root){
            if(tempNode == tempNode->parent->right && node->value < tempNode->parent->value){
                node->value = tempNode->parent->value;
                tempNode->parent->value = tempVal;
                break;
            }
            else if(tempNode == tempNode->parent->left && node->value > tempNode->parent->value){
                node->value = tempNode->parent->value;
                tempNode->parent->value = tempVal;
                break;
            }
            else{
                tempNode = tempNode->parent;
            }
        }
     }

     int count(){
         if(root){
             return count(root);
         }
         else{
             return 0;
         }
     }

     int count(Node<T>* node){
        if(!node){
            return 0;
        }
        else{
            return 1 + count(node->right) + count(node->left);
        }
     }

     bool complete(){
         if(!root){
             return true;
         }
         else{
             return complete(root,0,count());
         }
     }

     bool complete(Node<T>* node, int index, int numNodes){
         if(!node){
             return true;
         }
         else if(index >= numNodes){
             return false;
         }
         else{
             return complete(node->left,index*2+1,numNodes) && complete(node->right,index*2+2,numNodes);
         }
     }
     

};


#endif
