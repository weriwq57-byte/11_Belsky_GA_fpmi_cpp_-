
#include <iostream>


int main() {
    int n;

    std::cout << "Введите натуральное число: ";
    std::cin >> n;

    if (n <= 0) {
         std::cout << "Нужно ввести натуральное число!\n";
         return 1;
    }

    std::cout << "\nСовершенные числа от 1 до " << n << ":\n";

    for (int num = 1; num <= n; num++) {
        int sum = 0;

        for (int i = 1; i < num; i++) {
            if (num % i == 0) {
                sum += i;
            }
        }

        if (sum == num) {
            std::cout << num <<  ";\n";
        }
    }

    return 0;
}
