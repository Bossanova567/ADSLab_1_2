#include "Tree.h"

int main(){
    Node* root = NULL;
    int choice;
    cout << "Menu" << endl;
    cout << "1. Create a BST Root." << endl;
    cout << "2. Show the BST." << endl;
    cout << "3. Search for a node the BST." << endl;
    cout << "4. Insert a node in BST." << endl;
    cout << "5. Delete a node in BST." << endl;
    cout << "6. Search for a Successor node for a node in BST." << endl;
    cout << "7. Search for  a Predecessor node for a node in BST." << endl;
    cout << "0. Quit." << endl;
    label1:
    cout << endl;
    cout << "Your choice:";
    cin >> choice;
    if (choice == 0 || choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6 || choice == 7) {
        switch (choice) {
            case 0:
                return 0;
            case 1:
                if (root == NULL) {
                    int data;
                    cout << "Enter the data:";
                    cin >> data;
                    root = CreateRootBST(data);
                    ShowTree(root, 0);
                }
                else
                    cout << "Root has already been created" << endl;
                break;
            case 2:
                if (root){
                    ShowTree(root, 0);
                }
                else {
                    cout << "You didn't create a Root." << endl;
                }
                break;
            case 3:
                if (root != NULL){
                    int data;
                    cout << "Enter the data:";
                    cin >> data;
                    if (SearchNodeBST(root, data) != NULL)
                        cout << "The node has been found" << endl;
                    else
                        cout << "The node with such key doesn't exist" << endl;
                    ShowTree(root, 0);
                }
                else {
                    cout << "You didn't create a Root." << endl;
                }
                break;
            case 4:
                if (root != NULL){
                    int data;
                    cout << "Enter the data:";
                    cin >> data;
                    InsertNodeBST(root, data);
                    ShowTree(root, 0);
                }
                else {
                    cout << "You didn't create a Root." << endl;
                }
                break;
            case 5:
                if (root != NULL){
                    int data;
                    cout << "Enter the data:";
                    cin >> data;
                    DeleteNodeBST(SearchNodeBST(root, data), root);
                    ShowTree(root, 0);
                }
                else {
                    cout << "You didn't create a Root." << endl;
                }
                break;
            case 6:
                if (root != NULL){
                    int data;
                    cout << "Enter the data:";
                    cin >> data;
                    Node* temp = SuccessorNodeBST(SearchNodeBST(root, data));
                    cout << "The node with the key " << temp->key << " is a Successor node for node with the key " << data << endl;
                    ShowTree(root, 0);
                }
                else {
                    cout << "You didn't create a Root." << endl;
                }
                break;
            case 7:
                if (root != NULL){
                    int data;
                    cout << "Enter the data:";
                    cin >> data;
                    Node* temp = PredecessorNodeBST(SearchNodeBST(root, data));
                    cout << "The node with the key " << temp->key << " is a Predecessor node for node with the key " << data << endl;
                    ShowTree(root, 0);
                }
                else {
                    cout << "You didn't create a Root." << endl;
                }
                break;
        }
        goto label1;
    }
    else {
        cout << "You haven't chosen any of the available options. Please, try again." << endl;
        goto label1;
    }
}