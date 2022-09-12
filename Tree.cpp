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