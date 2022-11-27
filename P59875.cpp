//Author: icorn1
#include <iostream>
using namespace std;

int main(){

    int num1, num2;

    cin >> num1 >> num2;

    if (num1 > num2){

        for (int i = num1; i >= num2; i--)
            cout << i << endl;

    }
    else if (num2 > num1){

        for (int i = num2; i >= num1; i--)
            cout << i << endl;

    }
    else cout << num1 << endl;



}