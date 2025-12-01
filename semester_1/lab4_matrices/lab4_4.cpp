#include <iostream>
#include <random>
#include <algorithm>
#include <iomanip>


void fromKeyboard(int** matrix, int rows, int cols) {
    std::cout << "Введите " << rows * cols << " элементов матрицы:\n";
    for (int i = 0; i < rows; i++) {
        std::cout << "Строка " << i << ": ";
        for (int j = 0; j < cols; j++) {
            while (!(std::cin >> matrix[i][j])) {
                std::cout << "Ошибка! Введите целое число: ";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }  
        }      
    }          
}
   
void randMatrix(int** matrix, int rows, int cols, int min_val, int max_val) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min_val, max_val);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
        matrix[i][j] = dist(gen);
        }
    }
}

void printMatrix(int** matrix, int rows, int cols) {
std::cout << "\nМатрица " << rows << "x" << cols << ":\n";
    std::cout << "     ";
    for (int j = 0; j < cols; j++) {
        std::cout << "[" << j << "] ";
    }
    std::cout << std::endl;
     
    for (int i = 0; i < rows; i++) {
        std::cout << "[" << i << "] ";
        for (int j = 0; j < cols; j++) {
            std::cout << std::setw(5) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


long long sumWithZero(int** matrix, int rows, int cols) {
   
    long long sum = 0;
    for (int j = 0; j < cols; j++) {
         bool look_for_zero = false;
        for (int i = 0; i < rows; i++) {    
            if (matrix[i][j] == 0) {
            look_for_zero = true;
            break;
            }
        }
        if (look_for_zero == true) {
            for (int i = 0; i < rows; i++) {
                sum += matrix[i][j]; 
            
            }
        }
    }

    return sum;
}
#if 1
void insertionSort(int arr[], int n, bool ascending) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && 
               ((ascending && arr[j] > key) ||
                (!ascending && arr[j] < key))) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void sortRows(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        if (i % 2 == 0) { 
            insertionSort(matrix[i], cols, true);    
        } else { 
            insertionSort(matrix[i], cols, false);   
        }
    }
}
#endif

#if 0
void merge(int arr[], int left, int mid, int right, bool ascending) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int* leftArr = new int[n1];
    int* rightArr = new int[n2];
    
    for (int     i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];
    
    int i = 0;
    int j = 0;
    int k = left;
    
    while (i < n1 && j < n2) {
        if (ascending) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                j++;
            }
        } else {
            if (leftArr[i] >= rightArr[j]) {
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                j++;
            }
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
    
    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(int arr[], int left, int right, bool ascending) {
    if (left >= right) return;
    
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid, ascending);
    mergeSort(arr, mid + 1, right, ascending);
    merge(arr, left, mid, right, ascending);
}

void sortRows(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        if (i % 2 == 0) { 
            mergeSort(matrix[i], 0, cols - 1, true);
        } else { 
            mergeSort(matrix[i], 0, cols - 1, false);
        }
    }
}
#endif

int** createMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for(int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

void deleteMatrix(int** matrix, int rows) {
    for(int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}


int main() {
    int rows, cols, method;
    std::cout << "Введите количество строк в прямоугольной матрице: "; std::cin >> rows; 
    std::cout << "Введите количество столбцов в прямоугольной матрице: "; std::cin >> cols; 
    while (!(std::cin) || rows < 1 || cols < 1) {
        std::cout << "Введите количество количество строк, затем столбцов ещё раз:\n";
        std::cin.clear(); 
        std::cin.ignore(10000, '\n'); 
        std::cin >> rows >> cols;
    }

    do {
        std::cout << "Выберите способ заполнения (1 - с клавиатуры, 2 - случайные числа): ";
        std::cin >> method;
        if (!(std::cin) || (method != 1 && method != 2)) {
            std::cout << "Ошибка! Введите 1 или 2.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

    } while (method != 1 && method != 2);
    int** matrix = createMatrix(rows, cols);

    if (method == 1) {
        fromKeyboard(matrix, rows , cols);
    }
    else if (method == 2) { 
        int a, b;
        std::cout << "Введите первую границу интервала (a;b): "; 
        std::cin >> a;
        std::cout << "Введите вторую границу интервала (a;b): ";
        std::cin >> b;
        while (!(std::cin)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка! Введите целые числа: ";
            std::cin >> a >> b;
        }
        if (a > b) std::swap(a, b);
        randMatrix(matrix, rows, cols, a, b);
    }

    std::cout << "Матрица перед преобразованиями: \n";
    printMatrix(matrix, rows, cols);

    long long sum = sumWithZero(matrix, rows, cols);
    if (sum == 0) {
        std::cout << "\nВ матрице нет столбцов с нулевыми элементами" << std::endl;
    } else {
        std::cout << "\nСумма элементов в столбцах с нулями: " << sum << std::endl;
    }
   
    sortRows(matrix, rows, cols);
    std::cout << "Матрица после преобразований: \n";
    printMatrix(matrix, rows, cols);

    deleteMatrix(matrix, rows);
    return 0;
}
