#include <iostream>

#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H


template<typename T>
int linearSearchArr(int size,T item,T array[]){
    int repeating = 0;
    for (int i = 0; i < size;i++){
        if(array[i] == item){
            repeating++; 
        }
        else if(array[i] > 5){
            std::cout<<"ERROR: Only numbers 1-5 are allowed";
        }
    }
    return repeating;
}



#endif