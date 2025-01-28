// Author: Hoai Dinh

#include <chrono>
#include <iostream>
#include <sstream>
#include <algorithm>

#include "sorts.hpp"

std::string print_array(int array[], int size) {
    std::stringstream ss;

    ss << "{";
    for(int i = 0; i < size; i++) {
        ss << " " << array[i] << ((i != size-1) ? ", " : "");
    }
    ss << "}";

    return ss.str();
}

void copy_array(int dest[], const int src[], int size) {
    for(int i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}

void benchmark_sorts(int array[], int size, int cur_num) {
    int dupe_array[size];
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<double, std::milli> time_difference;

    std::string sort_names[] = {"Insertion Sort", "Selection Sort", "Bubble Sort"};
    std::function<void(int[], int)> sort_algos[] = {insertion_sort, selection_sort, bubble_sort};
    std::cout << "===== BENCHMARK " << cur_num << " =====\n"
              << ((size < 100) ? "Array: " + print_array(array, size) + "\n" : "")
              << "Size: " << size << "\n"
              << std::endl;
    
    for(int i = 0; i < 3; i++) {
        copy_array(dupe_array, array, size);
        std::cout << "--- " << sort_names[i] << " ---" << std::endl;
        start = std::chrono::high_resolution_clock::now();
        sort_algos[i](dupe_array, size);
        end = std::chrono::high_resolution_clock::now();
        time_difference = end - start;
        std::cout << ((size < 100) ? "Output: " + print_array(dupe_array, size) + "\n" : "")
                  << "Time to execute: " << time_difference.count() << "ms"
                  << std::endl;
    }
    std::cout << "\n\n";
}

int main() {
    int a1[] = {
        #include "../array_data/a1.txt"
    };
    int a2[] = {
        #include "../array_data/a2.txt"
    };
    int a3[] = {
        #include "../array_data/a3.txt"
    };
    int a4[] = {
        #include "../array_data/a4.txt"
    };
    int a5[] = {
        #include "../array_data/a5.txt"
    };
    int a6[] = {
        #include "../array_data/a6.txt"
    };


    int* arrays[] = {a1, a2, a3, a4, a5, a6};
    int sizes[] = {
        #include "../array_data/sizes.txt"
    };

    int i = 0;
    while(sizes[i] != -1) {
        benchmark_sorts(arrays[i], sizes[i], i+1);
        i++;
    }
    return 0;
}