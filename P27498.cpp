//Author: icorn1
#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > Matriu;

void swap (int& a, int& b){
    int c = a;
    a = b;
    b = c;
}
 	
void transposa(Matriu& m){
    int s = m.size();
    for (int i = 0; i < s - 1; i++){

        for (int j = i+1; j < s; j++){
            swap(m[i][j], m[j][i]);
        }
    }
     
}

int main(){
     int n = 1;
     int x;
     cin >> x;
     Matriu m(x, vector <int >(x));
    for (int i = 0; i < x; i++){
        for (int j = 0; j < x; j++){
            m[i][j] = n;
            n++;
        }
    }

     transposa(m);

     Matriu k = m;

     for (int i = 0; i < x; i++){
        for (int j = 0; j < x; j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < x; i++){
        for (int j = 0; j < x; j++){
            cout << k[i][j] << " ";
        }
        cout << endl;
    }

}