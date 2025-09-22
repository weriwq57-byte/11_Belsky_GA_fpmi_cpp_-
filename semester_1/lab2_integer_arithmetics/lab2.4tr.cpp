
#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Введите натуральное число: ";
    cin >> n;

    if (n <= 0) {
         cout << "Нужно ввести натуральное число!\n";
         return 1;
    }

    cout << "\nСовершенные числа от 1 до " << n << ":\n";

    for (int num = 1; num <= n; num++) {
        int sum = 0;

        for (int i = 1; i < num; i++) {
            if (num % i == 0) {
                sum += i;
            }
        }

        if (sum == num) {
            cout << num <<  ";\n";
        }
    }

    return 0;
}
