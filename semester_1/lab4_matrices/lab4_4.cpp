#include <iostream>
#include <random>
void fromKeyboard(int** matrix, int a, int b) {
    for (int i = 0; i < a; i++) {
         for (int j = 0; j < b; j++) {
            int left = a * b - (i * b + j) ;
            std::cout << "Введите элементы матрицы(осталось ввести " << left << " эл.): \n";
            std::cin >> matrix[i][j];
         }
    }
}

void randMatrix(int** matrix, int rows, int cols, int a, int b) {
    std::random_device rd;
    std::mt19937 gen(353453);
    std::uniform_int_distribution<> dist(a, b);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
        matrix[i][j] = dist(gen);
        }
    }
}

void printMatrix(int** matrix, int rows, int cols) {
    
    for (int i = 0; i < rows; i++) {
        std::cout << "Стр " << i << ": ";
        for (int j = 0; j < cols; j++) {
            std::cout  << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


int sumWithZero(int** matrix, int rows, int cols) {
   
    int sum = 0;
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
void sortingEven(int** matrix, int rows, int cols) {
for (int i = 0; i < rows; i +=2) {
     for (int j = 0; j < cols - 1; j++) {
            for (int k = 0; k < cols - j - 1; k++) {
                if (matrix[i][k] > matrix[i][k + 1]) {
                
                    std::swap(matrix[i][k], matrix[i][k + 1]);
                }
            }
        }
    }
}

void sortUneven(int** matrix, int rows, int cols) {
for (int i = 1; i < rows; i +=2) {
    for (int j = 0; j < cols - 1; j++) {
            for (int k = 0; k < cols - j - 1; k++) {
                if (matrix[i][k] < matrix[i][k + 1]) {
                
                    std::swap(matrix[i][k], matrix[i][k + 1]);
                }
            }
        }
    }

}


int main() {
int rows, cols, method;
std::cout << "Введите количество строк в прямоугольной матрице: "; std::cin >> rows; 
std::cout << "Введите количество столбцов в прямоугольной матрице: "; std::cin >> cols; 
while (std::cin.fail() || rows < 1 || cols < 1) {
         std::cout << "Введите количество количество строк, затем столбцов ещё раз:\n";
          std::cin.clear(); 
        std::cin.ignore(10000, '\n'); 
         std::cin >> rows >> cols;
        }

std::cout << "Выберите способ заполнения матрицы(1 - c клавиатуры; 2 - рандом): ";
std::cin >> method;


int** matrix = new int*[rows];
for (int i = 0; i < rows; i++) {
    matrix[i] = new int[cols];
}

if (method == 1) {
    fromKeyboard(matrix, rows , cols);
    
}
else if (method == 2) { 
    int a, b;
    std::cout << "Введите границы интервала (a;b): "; std::cin >> a >> b;
    if (a > b) std::swap(a, b);
    randMatrix(matrix, rows, cols, a, b);
}
else {
    std::cout << "Введён неверный способ заполнения матрицы." << "\n";
    return 0;

}


std::cout << "Матрица перед преобразованиями: \n";
printMatrix(matrix, rows, cols);

int sum = sumWithZero(matrix, rows, cols);
    std::cout << "\nСумма элементов в столбцах с нулями: " << sum << std::endl;


sortingEven(matrix, rows, cols);
sortUneven(matrix, rows, cols);
std::cout << "Матрица после преобразований: \n";
printMatrix(matrix, rows, cols);


for (int i = 0; i < rows; i++) {
delete[] matrix[i];
}
delete[] matrix;
return 0;
}