#include <cstddef>
#include <iostream>
#ifndef SORTINGALGO_H
#define SORTINGALGO_H

template<typename T>
void bubbleSort(T arr[], size_t arrSize){
    //step 1: fr i = 0 to N -1 repeat inner loop
    for(int i = 0; i < arrSize; i++){
        //step 2: inner loop that for K = i+1 to N-I repeat
            for(int j=i+1; j<arrSize; j++){
                //step 3 swap if the arr[j] > arr[i]
                if(arr[i] > arr[j]){
                    std::swap(arr[i], arr[j]);
                }
            }
    }     
}

template <typename T>
//array, current index, size of array
int routineSmallest(T arr[], int K, const int arrSize){
    int position, j;
    T smallest = arr[K];
    for(int j= K+1; j<arrSize; j++){
        if(arr[j] < smallest){
            smallest = arr[j];
            position = j;
        }
    }
    return position;
}

template <typename T>
void selectionSort(T arr[], size_t arrSize){
    int pos, temp, pass;
    for(int i=0; i<arrSize; i++){
        pos = routineSmallest(arr, i, arrSize);
        //swapping
        temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
        pass++;
        //for verification and count number of passes
    }
}

template <typename T>
void insertionSort(T arr[], size_t arrSize){
    int K = 0, J, temp;
    while(K < arrSize){
        temp = arr[K];
        J = K-1;

        while(J >= 0 && temp <= arr[J]){
            arr[J+1] = arr[J];
            J--;
        }
        arr[J+1] = temp;
        K++;
    }
}

template <typename T>
void shellSort(T arr[], size_t arrSize){
    for (int gap = arrSize / 2; gap > 0; gap /= 2) {
        
        for (int i = gap; i < arrSize; i++) {
            int temp = arr[i];
            int j;
            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            
            arr[j] = temp;
        }
    }
}

template <typename T>
void merge(T arr[], int left, int middle, int right) {
    int n1 = middle - left + 1; //Calculates the number of items in the left side
    int n2 = right - middle; //Calculates the number of items in the right side
    //temporary arrays to store left and right side elements
    int L[n1];
    int R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[middle + 1 + j];
    }

    int i = 0;    // Initial index of left side array
    int j = 0;    // Initial index of right side array
    int k = left; // Initial index of merged

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[] if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[] if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

template <typename T>
void mergeSort(T arr[], int left, int right) {
    // If left < right, then N > 1 (base condition to recurse)
    if (left < right) {
        // Find middle point
        int middle = (left + right) / 2;

        // Sort first half 
        mergeSort(arr, left, middle);

        // Sort second half 
        mergeSort(arr, middle + 1, right);

        // Merge sorted halves
        merge(arr, left, middle, right);
    }
}


// function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function and using the last element as the pivot
template <typename T>
int partition(T arr[], int low, int high) {
    int pivot = arr[high]; // Select the last element as pivot
    int i = low - 1;     // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    // Place pivot in its correct position
    swap(arr[i + 1], arr[high]);
    return (i + 1); 
}

template <typename T>
void quickSort(T arr[], int low, int high) {
    if (low < high) {
        // Find pivot such that elements smaller than pivot are on left
        // and elements greater than pivot are on right
        int pivot = partition(arr, low, high);
        //Recursive call on the left of pivot
        quickSort(arr, low, pivot - 1);
        // Recursive call on the right of pivot
        quickSort(arr, pivot + 1, high);
    }
}

template <typename T>
void partitionMergeSort(T arr[], int low, int high) {
    if (low < high) {
        // Find pivot such that elements smaller than pivot are on left
        // and elements greater than pivot are on right
        int pivot = partition(arr, low, high);
        //Recursive call on the left of pivot
        mergeSort(arr, low, pivot - 1);
        // Recursive call on the right of pivot
        mergeSort(arr, pivot + 1, high);
    }
}

#endif