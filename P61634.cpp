//Author: icorn1
#include <iostream>
using namespace std;

bool es_any_traspas (int y){
	return ((y % 4 == 0) and (y % 100 != 0)) or (y % 400 == 0);
}

int main(){

	int any;
	cin >> any;

	if(es_any_traspas(any)) cout << "YES\n";
	else cout << "NO\n";

}