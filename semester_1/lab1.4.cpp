#include <iostream>
using namespace std;

int main () {
    int k;
cout << "Введите число k: ";
cin >> k;
if (k < 0) {
exit(0);}
if (k == 0) {
cout << "k!!=0";
exit(0);}
int ch;
int fch = 1;
for (ch = 2 ; ch <= k ; ch +=2 ) {
    fch *= ch;
}
int nech;
int fnech = 1;
for(nech = 1; nech <= k ; nech +=2){
fnech *= nech;}
cout << "!Чётных: " << fch << "\n" << "!Нечётных: " << fnech << "\n";
return 0;
}