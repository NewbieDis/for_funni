#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDE

#include <cstdio>
#include <queue>

using namespace std;

class BinaryNode{
protected:
    int data;
    BinaryNode* left;
    BinaryNode* right;
public:
    BinaryNode(int val=0, BinaryNode* l=NULL,BinaryNode* r=NULL)
        :data(val), left(l), right(r) {};
    void setData(int val) {data = val;}
    void setLeft(BinaryNode *l) {left= l;}
    void setRight(BinaryNode *r) {right=r;}
    int getData() {return data;}
    BinaryNode* getLeft() {return left;}
    BinaryNode* getRight() {return right;}
    bool isLeaf() {return left==NULL && right==NULL;}
};

class BinaryTree{
    BinaryNode* root;
public:
    BinaryTree(): root(NULL) { }
    void setRoot(BinaryNode* node) {root = node;}
    BinaryNode* getRoot() { return root;}
    bool isEmpty() {return root==NULL;}

    void inorder() {printf("\n inorder:"); inorder(root);}
    void inorder(BinaryNode *node){
        if(node != NULL){
            inorder(node->getLeft());
            printf(" [%c] ",node->getData());
            inorder(node->getRight());
        }
    }

    void preorder() {printf("\n preorder:"); preorder(root);}
    void preorder(BinaryNode* node){
        if(node != NULL){
            printf(" [%c] ",node->getData());
            preorder(node->getLeft());
            preorder(node->getRight());
        }
    }

    void postorder() { printf("\n postorder: "); postorder(root);}
    void postorder(BinaryNode *node){
        if(node != NULL) {
            postorder(node->getLeft());
            postorder(node->getRight());
            printf(" [%c] ",node->getData());
        }
    }

    void levelorder(){
        printf("\nlevelorder: ");
        if(!isEmpty()){
            queue<BinaryNode*> q;
            q.push(root);
            while(!q.empty()){
                BinaryNode* n = q.front();q.pop();
                if(n != NULL){
                    printf(" [%c] ",n->getData());
                    q.push(n->getLeft());
                    q.push(n->getRight());
                }
            }
        }
    }

    int getCount() {return isEmpty()? 0 : getCount(root);}

    int getCount(BinaryNode *node){
        if(node==NULL) return 0;
        return 1 + getCount(node->getLeft())
                 + getCount(node->getRight());
    }

    int getLeafCount(){ return isEmpty() ? 0 : getLeafCount(root);}
    int getLeafCount(BinaryNode* node){
        if(node == NULL) return 0;
        if(node->isLeaf()) return 1;
        else return getLeafCount(node->getLeft())
                    + getLeafCount(node->getRight());
    }

    int getHeight() {return isEmpty() ? 0 : getHeight(root);}

    int getHeight(BinaryNode *node){
        if(node == NULL) return 0;
        int hLeft = getHeight(node->getLeft());
        int hRight = getHeight(node->getRight());
        return (hLeft>hRight) ? hLeft+1 : hRight+1;
    }
};

BinaryNode* searchIter(BinaryNode *n,int key){
    while(n != NULL){
        if(key == n->getData())
            return n;
        else if(key < n->getData())
            n = n->getLeft();
        else
            n = n->getRight();
    }
}

void insertRecur(BinaryNode* r,BinaryNode* n){
    if(n->getData() == r->getData())
        return;
    else if(n->getData() < r->getData()){
        if(r->getLeft() == NULL)
            r->setLeft(n);
        else
            insertRecur(r->getLeft(),n);
    }
    else {
        if(r->getRight() == NULL)
            r->setRight(n);
        else
            insertRecur(r->getRight(),n);
    }
}

void remove(BinaryNode *parent, BinaryNode *node){
    BinaryNode* replacewith = NULL;
    BinaryNode* rwparent = NULL;
    bool isLeft = (parent->getLeft() == node);

    if(node->getRight() == NULL){
        rwparent = node
        replacewith = node->getLeft();
        while(node->getRight() != NULL){
            printf("%d");
        }
    }
}

#endif // BINARYTREE_H_INCLUDED
