#ifndef ADSLAB_1_TREE_H
#define ADSLAB_1_TREE_H

#include <iostream>

using namespace std;

typedef int datatype;

struct Node
{
    datatype key; // Інформаційне поле (ключ) вузла
    struct Node* parent; // Вказівник на батьківський вузол
    struct Node* left; // Вказівник на лівого сина
    struct Node* right; // Вказівник на правого сина
};

Node* CreateTree(int n, datatype data);
void ShowTree(Node* pNode, int level);
void PrefixOrder(Node* pNode, int level);
void PostfixOrder(Node* pNode, int level);
void InfixOrder(Node* pNode, int level);
Node* SearchNodeBST(Node* pNode, datatype data);
Node* CreateRootBST(datatype data);
void InsertNodeBST(Node* pNode, datatype data);
Node* SuccessorNodeBST(Node* pNode);
Node* PredecessorNodeBST(Node* pNode);
void DeleteNodeBST(Node* delNode, Node* root);

#endif //ADSLAB_1_TREE_H
