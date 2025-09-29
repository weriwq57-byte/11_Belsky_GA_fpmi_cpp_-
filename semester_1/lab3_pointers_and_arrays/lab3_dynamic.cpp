#include <iostream>
#include <random>
#include <cmath>

int main () {
    
    int n, method;
    
    std::cout << "Введите количество элементов массива: ";
    std::cin >> n;



     while (std::cin.fail() || n <= 0) {
         std::cout << "Введите количество элементов массива ещё раз:\n";
         std::cin >> n;
        }
    
        double* mas = new double[n];
    
    std::cout << "Выберите способ заполнения элементов массива:\n";
    std::cout << "1 - Ввод с клавиатуры\n";
    std::cout << "2 - Рандом\n";
    std::cin >> method;
    if (method == 1) {
        for (int i = 0; i < n; ++i) {
            std::cout << "Элемент " << i << ": ";
            std::cin >> mas[i];
        }
    }
    else if (method == 2) {
        double a, b;
        std::cout << "Введите границы интервала [a, b]:\n";
        std::cout << "a = "; std::cin >> a;
        std::cout << "b = "; std::cin >> b;
        if (a > b) std::swap(a, b);
       
        std::random_device rd;
        std::mt19937 gen(353453);
        std::uniform_real_distribution<> dist(a, b);

        for (int i = 0; i < n; ++i) {
       mas[i] = dist(gen);
       std::cout << "Элемент " << i << ": " << mas[i] << "\n";
     }
    } else {
        std::cout << "Неверный выбор.\n";
        return 1;
    }
    int kol_ynik = 0;
    for (int i = 0; i < n; ++i) {
        bool ynik = true;
        for (int j = 0; j < i; ++j) {
            if (std::fabs(mas[i] - mas[j]) < 1e-9) {
                ynik = false;
                break;
            }
        }
        if (ynik) ++kol_ynik;
    }
    std::cout << "\nКоличество уникальных элементов: " << kol_ynik << '\n';


    int minIndex = 0;
    double minEL = std::fabs(mas[0]);
    
    for (int i = 1; i < n; i++) {
        double fabsEL = std::fabs(mas[i]);
        if (fabsEL < minEL) {
            minEL = fabsEL;
            minIndex = i;
        }
    }
    
    std::cout << "Минимальный по модулю элемент: " << mas[minIndex] 
              << " (индекс: " << minIndex << ")\n";
    
    
    if (minIndex == 0) {
        std::cout << "Минимальный элемент первый - нет элементов перед ним\n";
        return 0;
    }
    
    double product = 1;
    std::cout << "Элементы до минимального: ";
    for (int i = 0; i < minIndex; i++) {
        std::cout << mas[i];
        if (i < minIndex - 1) std::cout << " * ";
        product *= mas[i];
    }
    std::cout << " = " << product << std::endl;


    std::cout << "\nПреобразованный массив:\n";

    
    for (int i = 0; i < n; ++i) {
        if (mas[i] < 0)
            std::cout << mas[i] << " " ;
    }
        std::cout << '\n';


    for (int i = 0; i < n; ++i){
        if (std::fabs(mas[i]) < 1e-9) 
            std::cout << mas[i] << " " ;
    }

        std::cout << '\n';

    for (int i = 0; i < n; ++i) {
        if (mas[i] > 0)
            std::cout << mas[i] << " " ;
    }

    std::cout << '\n';
    

    
    delete[] mas;
    return 0;
}