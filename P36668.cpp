//Author: icorn1
#include <iostream>
using namespace std;

int main(){

    int n;

    cin >> n;

    int suma = 0;

    for (int i = 1; i <= n; i++){
        suma += i*i;  
    }
    cout << suma << endl;
}