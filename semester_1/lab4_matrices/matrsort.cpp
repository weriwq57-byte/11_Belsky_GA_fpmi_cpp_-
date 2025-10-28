#include <iostream>
#include <random>

void bubbleSortMatrix(int** matrix, int rows, int cols, bool ascending) {
    for (int i = 0; i < rows; i++) {
        for (int pass = 0; pass < cols - 1; pass++) {
            for (int j = 0; j < cols - pass - 1; j++) {
                bool needSwap;
                if (ascending) {
                    needSwap = (matrix[i][j] > matrix[i][j + 1]);
                } else {
                    needSwap = (matrix[i][j] < matrix[i][j + 1]);
                }
                
                if (needSwap) {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[i][j + 1];
                    matrix[i][j + 1] = temp;
                }
            }
        }
    }
}

void selectionSortMatrix(int** matrix, int rows, int cols, bool ascending) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols - 1; j++) {
            int extremeIndex = j;
            
            for (int k = j + 1; k < cols; k++) {
                bool isMoreExtreme;
                if (ascending) {
                    isMoreExtreme = (matrix[i][k] < matrix[i][extremeIndex]);
                } else {
                    isMoreExtreme = (matrix[i][k] > matrix[i][extremeIndex]);
                }
                
                if (isMoreExtreme) {
                    extremeIndex = k;
                }
            }
            
            if (extremeIndex != j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][extremeIndex];
                matrix[i][extremeIndex] = temp;
            }
        }
    }
}

void insertionSortMatrix(int** matrix, int rows, int cols, bool ascending) {
    for (int i = 0; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            int current = matrix[i][j];
            int k = j - 1;
            
            if (ascending) {
                while (k >= 0 && matrix[i][k] > current) {
                    matrix[i][k + 1] = matrix[i][k];
                    k--;
                }
            } else {
                while (k >= 0 && matrix[i][k] < current) {
                    matrix[i][k + 1] = matrix[i][k];
                    k--;
                }
            }
            
            matrix[i][k + 1] = current;
        }
    }
}


void sortMatrix(int** matrix, int rows, int cols, int sortType, bool ascending) {
    switch (sortType) {
        case 1:
            bubbleSortMatrix(matrix, rows, cols, ascending);
            break;
        case 2:
            selectionSortMatrix(matrix, rows, cols, ascending);
            break;
        case 3:
            insertionSortMatrix(matrix, rows, cols, ascending);
            break;
    }
}


void printMatrix(int** matrix, int rows, int cols) {
    std::cout << "\nМатрица " << rows << "x" << cols << ":\n";
    for (int i = 0; i < rows; i++) {
        std::cout << "Строка " << i << ": ";
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


void inputMatrix(int** matrix, int rows, int cols) {
    std::cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < rows; i++) {
        std::cout << "Строка " << i << ": ";
        for (int j = 0; j < cols; j++) {
            std::cin >> matrix[i][j];
        }
    }
}

void randomMatrix(int** matrix, int rows, int cols, int a, int b) {
    std::random_device rd;
    std::mt19937 gen(353453);
    std::uniform_int_distribution<> dist(a, b);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
        matrix[i][j] = dist(gen);
        }
    }
}

int main() {
    int rows, cols;
    std::cout << "Введите количество строк: ";
    std::cin >> rows;
    std::cout << "Введите количество столбцов: ";
    std::cin >> cols;
    
    
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    
    
    int fillMethod;
    std::cout << "\nВыберите способ заполнения:\n";
    std::cout << "1 - Ввод с клавиатуры\n";
    std::cout << "2 - Случайные числа\n";
    std::cin >> fillMethod;
    
    if (fillMethod == 1) {
        inputMatrix(matrix, rows, cols);
    } else {
        int minVal, maxVal;
        std::cout << "Введите минимальное значение: ";
        std::cin >> minVal;
        std::cout << "Введите максимальное значение: ";
        std::cin >> maxVal;
        randomMatrix(matrix, rows, cols, minVal, maxVal);
    }
    
    std::cout << "\nИСХОДНАЯ МАТРИЦА:";
    printMatrix(matrix, rows, cols);
  
    int sortType;
    std::cout << "\nВыберите тип сортировки:\n";
    std::cout << "1 - Пузырьковая\n";
    std::cout << "2 - Выбором\n";
    std::cout << "3 - Вставками\n";
    std::cin >> sortType;
    
   
    int order;
    std::cout << "\nВыберите порядок сортировки:\n";
    std::cout << "1 - По возрастанию\n";
    std::cout << "2 - По убыванию\n";
    std::cin >> order;
    
    bool ascending = (order == 1);
    
    std::cout << "\nИСХОДНАЯ МАТРИЦА:";
    printMatrix(matrix, rows, cols);

    sortMatrix(matrix, rows, cols, sortType, ascending);
    
    std::cout << "\nОТСОРТИРОВАННАЯ МАТРИЦА:";
    printMatrix(matrix, rows, cols);
    

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    
    return 0;
}