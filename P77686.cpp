//Author: icorn1
#include <iostream>
using namespace std;

bool es_capicua(int n){

    int n2 = n, n1 = 0, residu;

    while (n2 > 0){

        residu = n2%10;
        
        n2 /= 10;

        n1 = n1*10+residu;
    }

    return (n1 == n ? true : false);
}


int main(){

    int n;
    while(cin >> n){
        if(es_capicua(n)) cout << "a\n";
    }

}