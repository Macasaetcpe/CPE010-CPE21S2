#include <iostream>
#include "BST.h"
#include "generalTreeLL.h"

int main(){
    //create a root node
    BinarySearchTree<int> tree(2);
    tree.insert(3);
    tree.insert(9);
    tree.insert(18);
    tree.insert(0);
    tree.insert(1);
    tree.insert(4);
    tree.insert(5);

    std::cout<<"preOrder: ";
    tree.preOrder();
    std::cout<<std::endl;
    std::cout<<"inOrder: ";
    tree.inOrder();
    std::cout<<std::endl;
    std::cout<<"postOrder: ";
    tree.postOrder();
    std::cout<<std::endl;
    
    
    //GENERAL TREE
    //creates the children of root A
    Node<char>* root = new Node<char>('A');
    displayRoot<char>(root);
    addChild<char>(root, 'A', 'B');
    addChild<char>(root, 'A','C');
    addChild<char>(root, 'A','D');
    addChild<char>(root, 'A', 'E');
    addChild<char>(root, 'A', 'F');
    addChild<char>(root, 'A', 'G');
    displayTree<char>(root, 'A');
    //creates the children of node D
    addChild<char>(root, 'D', 'H');
    displayTree<char>(root, 'D');
    //creates the children of node E
    addChild<char>(root,'E', 'I');
    addChild<char>(root,'E', 'J');
    displayTree<char>(root, 'E');
    //creates the children of node F
    addChild<char>(root,'F', 'K');
    addChild<char>(root,'F', 'L');
    addChild<char>(root,'F', 'M');
    displayTree<char>(root, 'F');
    //creates the children of node G
    addChild<char>(root,'G', 'N');
    displayTree<char>(root, 'G');
    //creates the children of node J
    addChild<char>(root,'J', 'P');
    addChild<char>(root,'J', 'Q');
    displayTree<char>(root, 'J');
    
    std::cout << "Pre-order: ";
    preOrder(root);
    std::cout << std::endl;

    std::cout << "In-order: ";
    inOrder(root);
    std::cout << std::endl;

    std::cout << "Post-order: ";
    postOrder(root);
    std::cout << std::endl;

    findData<char>(root, 1, 'G');
    findData<char>(root, 2, 'D');
    findData<char>(root, 3, 'F');

    addChild<char>(root, 'G', 'O');
    displayTree<char>(root, 'G');
    findData<char>(root, 1, 'O');
    
    return 0;
}