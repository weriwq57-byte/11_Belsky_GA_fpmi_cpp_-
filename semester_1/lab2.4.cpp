#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Введите натуральное число: ";
    cin >> n;
    
    if (n < 1){
    cout << "Число не является натуральным." << std::endl;
exit(0);
}
int sumd = 0;
    for(int i = 1; i < n; i++){
       if ( n % i == 0 ){
        cout << "Делитель числа n: " << i << ";" << std::endl;
    sumd += i;
    }    
}
 cout << "(Не включая число n)" << std::endl;
if (sumd == n){
cout << "Число " << n << " является совершенным.";}
else {
    cout << "Число " << n << " не является совершенным.";
}
return 0;
}