//Author icorn1
#include <iostream>
using namespace std;

int main(){

    long long n, m;

    while(cin >> n >> m){

        if((n*(n-1))/2 < m){
            cout << "you've been trolled\n";
        }
        else if (n-1 > m){
            cout << "disconnected\n";
        }
        else if(n-2 >= ((n*(n-1))/2)-m){
            cout << "connected\n";
        }
        else cout << "impossible to know\n";

    }
}