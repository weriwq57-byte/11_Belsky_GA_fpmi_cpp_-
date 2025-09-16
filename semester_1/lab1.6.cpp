#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Введите количество всех нечётных чисел: ";
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++){
    sum += 2*i+1;}
cout << "Сумма равна " << sum << std::endl;


return 0;
}