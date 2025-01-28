// Author: Hoai Dinh

#include "sorts.hpp"

void insertion_sort(int array[], int size) {
    int i = 0;
    for(i = 1; i < size; i++) {
        int key = array[i];
        int j = i-1;

        while(j >= 0 && array[j] > key) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}

void selection_sort(int array[], int size) {
    int i = 0;
    int j = 0;
    for(i = 0; i < size-1; i++) {
        int min_idx = i;
        for(j = i+1; j < size; j++) {
            if(array[j] < array[min_idx]) {
                min_idx = j;
            }
        }

        if(min_idx != i) {
            SWAP(array[i], array[min_idx]);
        }
    }
}

void bubble_sort(int array[], int size) {
    bool did_swap = false;

    int i = 0;
    int r = size; // remaining elements to be sorted
    do {
        did_swap = false;
        for(i = 1; i < r; i++) {
            if(array[i-1] > array[i]) {
                SWAP(array[i-1], array[i]);
                did_swap = true;
            }
        }
        r--; // At least 1 element is palced in the correct spot after swaping
    } while(did_swap);
}