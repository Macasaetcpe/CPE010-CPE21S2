#ifndef GENERALTREELL_H
#define GENERALTREELL_H
#include <iostream>
template <typename T>
class Node{
    public:
       T key;
       Node* firstChild;
       Node* nextSibling;

    Node(T data){
       key = data;
       firstChild = nullptr;
       nextSibling = nullptr;
    }
};

template <typename T>
void displayRoot(Node<T>* root){
    if(root != nullptr){
        std::cout<<"Root Node: "<<root->key<<std::endl;
    }
}

template <typename T>
void setRoot(Node<T>*& rootPtr, T val){
    rootPtr = new Node<T>(val);
}
//findNode function so that you don't have to change the value of a root 
//everytime you want to create children of a child of root. 
template <typename T>
Node<T>* findNode(Node<T>* current, T target) {
    if (current == nullptr){
        return nullptr;
    }
    if (current->key == target){
        return current;
    }

    Node<T>* found = findNode(current->firstChild, target);
    if (found != nullptr){
        return found;
    }

    return findNode(current->nextSibling, target);
}

template <typename T>
void addChild(Node<T>* root, T parent, T child){
    Node<T>* newNode = new Node<T>(child);
    Node<T>* parentNode = findNode(root, parent);
    if(parentNode != nullptr){
        if(parentNode->firstChild == nullptr){
        parentNode->firstChild = newNode;
        }else{
           Node<T>* temp = parentNode->firstChild;
           while(temp->nextSibling != nullptr){
               temp = temp->nextSibling;
           }
           temp->nextSibling = newNode;
        }
    }
}

template <typename T>
void displayTree(Node<T>* root, T target) {
    Node<T>* targetNode = findNode(root, target);
    if (targetNode == nullptr) {
        std::cout << "Node " << target << " not found." << std::endl;
        return;
    }

    std::cout << "Children of Node " << targetNode->key << ": ";
    Node<T>* current = targetNode->firstChild;
    while (current != nullptr) {
        std::cout << current->key << " ";
        current = current->nextSibling;
    }
    std::cout << std::endl;
}

template <typename T>
void preOrder(Node<T>* current) {
    if (current == nullptr) return;

    std::cout << current->key << " ";

    preOrder(current->firstChild);

    preOrder(current->nextSibling);
}

template <typename T>
void inOrder(Node<T>* current) {
    if (current == nullptr) return;

    inOrder(current->firstChild);

    std::cout << current->key << " ";

    inOrder(current->nextSibling);
}

template <typename T>
void postOrder(Node<T>* current) {
    if (current == nullptr) return;

    postOrder(current->firstChild);

    std::cout << current->key << " ";

    postOrder(current->nextSibling);
}

template <typename T>
bool searchPreOrder(Node<T>* current, T key) {
    if (current == nullptr){
        return false;
    }
    if (current->key == key){
        return true;
    }
    if (searchPreOrder(current->firstChild, key)){
        return true;
    }
    return searchPreOrder(current->nextSibling, key);
}

template <typename T>
bool searchInOrder(Node<T>* current, T key) {
    if (current == nullptr){
        return false;
    }
    if (searchInOrder(current->firstChild, key)){
        return true;
    }
    if (current->key == key){
        return true;
    }
    return searchInOrder(current->nextSibling, key);
}

template <typename T>
bool searchPostOrder(Node<T>* current, T key) {
    if (current == nullptr){
        return false;
    }
    if (searchPostOrder(current->firstChild, key)){
        return true;
    }
    if (searchPostOrder(current->nextSibling, key)){
        return true;
    }
    return current->key == key;
}

template <typename T>
void findData(Node<T>* root, int choice, T key) {
    bool found = false;

    switch (choice) {
        case 1: // Pre-order
            found = searchPreOrder(root, key);
            break;
        case 2: // In-order
            found = searchInOrder(root, key);
            break;
        case 3: // Post-order
            found = searchPostOrder(root, key);
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
            return;
    }

    if (found) {
        std::cout << "Node " <<key << " was found!" << std::endl;
    }
}
#endif
