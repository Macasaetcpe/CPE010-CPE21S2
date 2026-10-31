#include<iostream>
#include<cstdlib>
#include "sortingAlgo.h"


const int max_size = 100;

void displayArr(int arr[]);

int main(){
    //create an array with unsorted list
    int unsortedArr[max_size];
    //use time (0) as seed
    srand(time(0));
    //populate the array
    
    for(int i=0; i < max_size; i++){
        unsortedArr[i] = rand()%100;
    }
    std::cout<<"Unsorted Array: \n";
    displayArr(unsortedArr);
    
    std::cout<<"\nShell Sort: \n";
    shellSort(unsortedArr, max_size);
    displayArr(unsortedArr);

    std::cout<<"\nMerge Sort: \n";
    mergeSort(unsortedArr, 0, max_size - 1);
    displayArr(unsortedArr);

    std::cout<<"\nQuick Sort: \n";
    quickSort(unsortedArr, 0, max_size - 1);
    displayArr(unsortedArr);


}

void displayArr(int arr[]){
    for(int i = 0;i <max_size; i++ ){
        std::cout<< arr[i] << " ";
    }
    std::cout<<std::endl;
}