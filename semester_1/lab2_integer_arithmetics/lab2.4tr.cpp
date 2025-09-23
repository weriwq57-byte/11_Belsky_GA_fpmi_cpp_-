
#include <iostream>


int main() {
    int n;

    std::cout << "Введите натуральное число: ";
    

    
        while (!(std::cin >> n) || n < 1) {
         std::cout << "Ошибка. Нужно ввести натуральное число!\n";
        
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
