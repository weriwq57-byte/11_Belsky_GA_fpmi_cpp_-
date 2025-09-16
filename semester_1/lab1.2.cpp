
#include <iostream>

int main() {
    int n;

    std::cout << "Введите количество чисел. n = ";
    std::cin >> n;
    int sumch=0;
    long sumnech=1;
for(int i=1; i <= n; ++i){
    if(i%2==0){sumch+=i;
    }
    else {sumnech *= i;
    }

}
std::cout <<"Сумма чётных: "<< sumch << "\n";

 std::cout <<"Произведение нечётных: "<< sumnech << "\n";

    return 0;
}
