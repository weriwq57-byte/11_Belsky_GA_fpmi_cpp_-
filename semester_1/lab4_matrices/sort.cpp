
#include <iostream>
#include <cmath>


bool compareDescByAbs(int a, int b) {
    return std::abs(a) < std::abs(b);
}


bool compareAscByAbs(int a, int b) {
    return std::abs(a) > std::abs(b);
}


void bubbleSort(int arr[], int size, bool (*compare)(int, int)) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (compare(arr[j], arr[j + 1])) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    int arr[] = {1, -5, 3, -6, 2, -4, 9, -3, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    std::cout << "Исходный массив: ";
    printArray(arr, size);
    

    bubbleSort(arr, size, compareDescByAbs);
    std::cout << "По убыванию модулей: ";
    printArray(arr, size);
    
   
    bubbleSort(arr, size, compareAscByAbs);
    std::cout << "По возрастанию модулей: ";
    printArray(arr, size);
    
    return 0;
}