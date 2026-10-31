#include<iostream>
#include<cstdlib>
#include "sortingAlgo.h"
#include "searchingAlgo.h"


const int max_size = 100;

void displayArr(int arr[]);

int main(){
    //create an array with unsorted list
    int unsortedArr[max_size];
    //use time (0) as seed
    srand(time(0));
    //populate the array
    for(int i=0; i < max_size; i++){
        unsortedArr[i] = (rand() % 5) + 1;
    }
    std::cout<<"Unsorted Votes: \n";
    displayArr(unsortedArr);
    

    std::cout<<"\nSorted using Insertion Sort: \n";
    insertionSort(unsortedArr, max_size);
    displayArr(unsortedArr);

    std::cout<<"\nTally of Votes: ";
    std::cout<<"\nCandidate 1: Bo Dalton Capistrano: "<<linearSearchArr(max_size, 1, unsortedArr);
    std::cout<<"\nCandidate 2: Cornelius Raymon Agustin: "<<linearSearchArr(max_size, 2, unsortedArr);
    std::cout<<"\nCandidate 3: Deja Jayla Banaga: "<<linearSearchArr(max_size, 3, unsortedArr);
    std::cout<<"\nCandidate 4: Lalla Brielle Yabut: "<<linearSearchArr(max_size, 4, unsortedArr);
    std::cout<<"\nCandidate 5: Franklin Relano Castro: "<<linearSearchArr(max_size, 5, unsortedArr);

    int totalVotes[5];
    int tempArr[5];
    for(int i=0; i < 5; i++){
        totalVotes[i] = linearSearchArr(max_size, i+1, unsortedArr);
        tempArr[i] = totalVotes[i];
    }
    insertionSort(totalVotes, 5);
    std::cout<<std::endl;
    for(int i=0; i<5;i++){
        if(tempArr[i] == totalVotes[4]){
            std::cout<< "\nWINNER: Candidate "<< i+1<< std::endl;
        }
    }
}


void displayArr(int arr[]){
    for(int i = 0;i <max_size; i++ ){
        std::cout<< arr[i] << " ";
    }
    std::cout<<std::endl;
}


