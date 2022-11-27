//Author: icorn1
#include <iostream>
using namespace std;

int absolute (int n){

    if (n >= 0)
        return n;
    else
        return (0 - n);
}

int main(){
    
    int n;
    cin >> n;
    cout << absolute(n) << endl;
    

}