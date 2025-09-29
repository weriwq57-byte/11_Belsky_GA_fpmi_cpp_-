#include <iostream>
#include <random>

int main () {
    
    int n, method;
    const int max_el = 10000;
    std::cout << "Введите количество элементов массива, не привышающих " << max_el << ": ";
    std::cin >> n;

     while (std::cin.fail() || n < 1 || n > 10000) {
         std::cout << "Некорректный размер массива. Введите количество элементов массива ещё раз:\n";
         std::cin >> n;
        }
    double mas[max_el];
    
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
 double minZn = mas[0];
    int minInd = 0;
    for (int i = 1; i < n; ++i) {
        if (mas[i] <= minZn) {
            minZn = mas[i];
            minInd = i;
        }
    }
    std::cout << "\nМаксимальный индекс минимального элемента: " << minInd << '\n';


    int firstNeg = -1, lastNeg = -1;
    for (int i = 0; i < n; ++i) {
        if (mas[i] < 0) {
             firstNeg = i;
            lastNeg = i;
        }
    }

    if (firstNeg == -1 || lastNeg == -1 || firstNeg == lastNeg) {
        std::cout << "Недостаточно отрицательных элементов для вычисления суммы.\n";
    } else {
        double sum = 0;
        for (int i = firstNeg + 1; i < lastNeg; ++i) {
            sum += mas[i];
        }
        std::cout << "Сумма между первым и последним отрицательными элементами: " << sum << '\n';
    }

    
double X;
std::cout << "\nВведите значение X: ";
std::cin >> X;

double temp[max_el];
int index = 0;

for (int i = 0; i < n; ++i) {
    if (std::abs(mas[i]) <= X) {
        temp[index++] = mas[i];
    }
}

for (int i = 0; i < n; ++i) {
    if (std::abs(mas[i]) > X) {
        temp[index++] = mas[i];
    }
}

for (int i = 0; i < n; ++i) {
    mas[i] = temp[i];
}

std::cout << "Преобразованный массив:\n";
for (int i = 0; i < n; ++i) {
    std::cout << "Элемент " << i << ": " << mas[i] << '\n';
}

    return 0;
}