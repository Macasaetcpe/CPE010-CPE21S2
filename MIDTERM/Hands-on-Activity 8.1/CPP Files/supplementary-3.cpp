#include<iostream>
#include<cstdlib>
#include "sortingAlgo.h"

const int newSize = 15;

void displayArr(int arr[]);

int main(){

    int newArr[newSize] = {4,34,29,48,53,87,12,30,44,25,93,67,43,19,74};
    std::cout<<"New Array: \n";
    displayArr(newArr);
    std::cout<<"\nQuick Sort: \n";
    quickSort(newArr, 0, newSize - 1);
    displayArr(newArr);
    //SUPPLEMENTARY PROB 1: USING MERGE SORT INSTEAD
    //OF QUICK SORT
    std::cout<<"\nMerge Sort with partition: \n";
    partitionMergeSort(newArr, 0, newSize - 1);
    displayArr(newArr);



}

void displayArr(int arr[]){
    for(int i = 0;i < newSize; i++ ){
        std::cout<< arr[i] << " ";
    }
    std::cout<<std::endl;
}