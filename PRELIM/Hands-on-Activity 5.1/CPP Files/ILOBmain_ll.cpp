#include <iostream>
#include "queuell.h"

int main(){
    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    enqueue('J', &front, &back);
    std::cout<<"front: "<< front->data << " "<<"back: "<<back->data<<std::endl;
    enqueue('O', &front, &back);
    std::cout<<"front: "<< front->data << " "<<"back: "<<back->data<<std::endl;
    enqueue('H', &front, &back);
    std::cout<<"front: "<< front->data << " "<<"back: "<<back->data<<std::endl;
    enqueue('N', &front, &back);
    std::cout<<"front: "<< front->data << " "<<"back: "<<back->data<<std::endl;

    //testing of displayall
    std::cout<<"\nTesting of displayAll operator\n";
    displayQ(&front, &back);
    std::cout<<std::endl;

    std::cout<<"Testing the dequeue operator\n";
    dequeue(&front, &back);
    std::cout<<"front: "<< front->data << " "<<"back: "<<back->data<<std::endl;
    dequeue(&front, &back);
    std::cout<<"front: "<< front->data << " "<<"back: "<<back->data<<std::endl;
    dequeue(&front, &back);
    std::cout<<"front: "<< front->data << " "<<"back: "<<back->data<<std::endl;
    dequeue(&front, &back);
    dequeue(&front, &back);
    std::cout<<std::endl;
    
    std::cout<<"Testing of isEmpty operator\n";
    if(isEmpty(&front, &back)){
        std::cout<<"The queue is empty\n";
    }else{
        std::cout<<"The queue is not empty\n";
    }
    return 0;
}