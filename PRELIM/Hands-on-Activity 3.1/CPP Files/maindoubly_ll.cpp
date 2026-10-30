#include <iostream>
#include "singly_ll.h"
#include "doubly_ll.h"


int main(){
    // create a playlist
    DoubleList<char>* head = CreateNewNode('C');
    DoubleList<char>* second = CreateNewNode('P');
    DoubleList<char>* third = CreateNewNode('E');

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    //traversal
    std::cout<<"Testing the DLL Traversal"<<std::endl;
    dllTraverse(head);

    //testing the insert at the head
    std::cout<<"\nTesting the insertion at the head node"<<std::endl;
    dllInsertHead('X', &head);
    dllTraverse(head);

    std::cout<<"\nTesting the insertion at the end"<<std::endl;
    dllInsertEnd('0', head);
    dllTraverse(head);

    std::cout << "\nTesting of dllGeneralInsert\n";
    dllGeneralInsert('J', head->next); 
    dllTraverse(head);

    std::cout<<"\nTesting of dllDeleteNode\n";
    dllDeleteNode('C', &head);
    dllTraverse(head);
}