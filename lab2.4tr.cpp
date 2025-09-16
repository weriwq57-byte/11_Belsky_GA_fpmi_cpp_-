#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Введите натуральное число: ";
    cin >> n;
     for (int num = 1; num <= n; num++ ){
    int sum = 0;
 for(int i = 1; i < num; i++){
if (num % i ==0){
 sum += i;}}
if (sum == num){
cout << sum << std::endl;} }
    

    return 0;
}