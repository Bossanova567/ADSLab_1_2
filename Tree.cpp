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
        if (pNode->key == data)
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
void InsertNodeBST(Node* pNode, datatype data){
    if (SearchNodeBST(pNode, data) != NULL){
        cout << "The element you want to insert already exists" << endl;
    }
    else {
        Node *pNew = new Node;
        pNew->key = data;
        pNew->parent = pNew->left = pNew->right = NULL;
        Node* previous;
        while (pNode != NULL) {
            previous = pNode;
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
Node* PredecessorNodeBST(Node* pNode){
    if (pNode->left != NULL){
        Node* previous;
        previous = pNode->left;
        while (previous->right != NULL)
            previous = previous->right;
        return previous;
    }
    else {
        Node* previous;
        previous = pNode->parent;
        while (previous != NULL && pNode == previous->left){
            pNode = previous;
            previous = previous->parent;
        }
        return previous;
    }
}
void DeleteNodeBST(Node* delNode, Node* root){
    if (SearchNodeBST(delNode, delNode->key) == NULL)
        cout << "The element you want to delete doesn't exist" << endl;
    else
    {
        if (delNode->left == NULL && delNode->right == NULL)
        {
            if (delNode == root)
                delete root;
            else if ((delNode->parent)->left == delNode)
                (delNode->parent)->left = NULL;
            else if ((delNode->parent)->right == delNode)
                (delNode->parent)->right = NULL;
        }
        else if (delNode->left != NULL && delNode->right != NULL)
        {
            Node* term;
            term = SuccessorNodeBST(delNode);
            delNode->key = term->key;
            DeleteNodeBST(term, root);
        }
        else if (delNode->left != NULL || delNode->right != NULL){
            Node* next;
            if (delNode->left != NULL)
                next = delNode->left;
            else
                next = delNode->right;
            if (delNode == root) {
                root = next;
                delete delNode;
            }
            else {
                if ((delNode->parent)->left == delNode)
                    (delNode->parent)->left = next;
                else if ((delNode->parent)->right == delNode)
                    (delNode->parent)->right = next;
                next->parent = delNode->parent;
                delete delNode;
            }
        }
    }
}