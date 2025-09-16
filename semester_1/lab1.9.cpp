#include <iostream>
using namespace std;
int main(){
    int a;
cout << "Введите четырёхзначное число: ";
cin >> a;
if (a < 1000 || a > 9999){
cout << "Неправильное число.\n";
exit(0);}
int n4 = a / 1000;
int n3 = (a % 1000) / 100;
int n2 = (a % 100) / 10;
int n1 = a % 10;

if (n4 == n1 && n3 == n2){
cout << "Число является палиндромом.\n";
}
else {cout << "Число не является палиндромом.\n";
}

return 0;
}