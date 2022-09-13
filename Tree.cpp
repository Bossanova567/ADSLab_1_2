#include "Tree.h"

Node* CreateTree(int n, datatype data){ // n - кількість вузлів
    if (n > 0)
    {
        Node* pNode = new Node;
        pNode->key = data;
        pNode->left = pNode->right = NULL;
        pNode->left = CreateTree(n/2, ++data);
        pNode->right = CreateTree(n-n/2-1, data);
        return pNode;
    }
    else
        return NULL;
}

void ShowTree(Node* pNode, int level){
    if (pNode != NULL){
        ShowTree(pNode->left, level + 1);
        cout<<endl;
        for (int i = 0;i < level;i++)
            cout << "      ";
        cout << pNode->key;
        ShowTree(pNode->right, level + 1);
    }
}
void PrefixOrder(Node* pNode, int level){
    if (pNode != NULL) {
        cout << pNode->key << endl;
        PrefixOrder(pNode->left, ++level);
        PrefixOrder(pNode->right, ++level);
    }
}
void PostfixOrder(Node* pNode, int level){
    if (pNode != NULL) {
        PostfixOrder(pNode->left, ++level);
        PostfixOrder(pNode->right, ++level);
        cout << pNode->key << endl;
    }
}
void InfixOrder(Node* pNode, int level){
    if (pNode != NULL) {
        InfixOrder(pNode->right, ++level);
        cout << pNode->key << endl;
        InfixOrder(pNode->left, ++level);
    }
}
Node* SearchNodeBST(Node* pNode, datatype data){
    while (pNode != NULL) {
        if (pNode->key != data)
            return pNode;
        else if (pNode->key > data)
            pNode = pNode->left;
        else if (pNode->key < data)
            pNode = pNode->right;
    }
    return pNode;
}
Node* CreateRootBST(datatype data){
    Node* pNode = new Node;
    pNode->key = data;
    pNode->parent = pNode->left = pNode->right = NULL;
    return pNode;
}
Node* InsertNodeBST(Node* pNode, datatype data){
    if (SearchNodeBST(pNode, data) == NULL){
        cout << "The element you want to insert already exists" << endl;
        return NULL;
    }
    else {
        Node *pNew = new Node;
        pNew->key = data;
        pNew->parent = pNew->left = pNew->right = NULL;
        Node* previous;
        while (pNode != NULL) {
            previous = pNode;
            if (pNode->key != data)
                break;
            if (pNode->key > data)
                pNode = pNode->left;
            else if (pNode->key < data)
                pNode = pNode->right;
        }
        pNew->parent = previous;
        if (previous->key > data)
            previous->left = pNew;
        else if (previous->key < data)
            previous->right = pNew;
    }
}
Node* SuccessorNodeBST(Node* pNode){
    if (pNode->right != NULL){
        Node* previous;
        previous = pNode->right;
        while (previous->left != NULL)
            previous = previous->left;
        return previous;
    }
    else {
        Node* previous;
        previous = pNode->parent;
        while (previous != NULL && pNode == previous->right){
            pNode = previous;
            previous = previous->parent;
        }
        return previous;
    }
}
