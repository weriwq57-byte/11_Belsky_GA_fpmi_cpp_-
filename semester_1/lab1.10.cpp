#include <iostream>
using namespace std;
int main(){
    int a;
cout << "Введите шестизначное число: ";
cin >> a;
if (a < 100000 || a > 999999){
cout << "Неправильное число.\n";
exit(0);}
int n5 = a / 100000;
int n4 = (a % 100000) / 10000 ;
int n3 = (a % 10000) / 1000;
int n2 = (a % 1000) / 100;
int n1 = (a % 100) / 10;
int n0 = a % 10;

if ( n0 + n1 + n2 == n3 + n4 + n5){
cout << "Счастливое число.\n";}
else {
cout << "Несчастливое число.\n";}

return 0;
}