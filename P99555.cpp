//Author: icorn1
//Aquest problema crec que fallava en privat, et toca fer-lo a tu tet
#include <iostream>
#include <vector>
using namespace std;

typedef vector <int> Fila;
typedef vector <Fila> Matriu;

bool horitzontal(const int& n, const Matriu& a){
    //PRE: Matriu a de nxn 
    //POST: Retorna si la suma dels elements horitzontals es igual en totes les files.
    int suma = 0;
    
    vector <int> sumes(n, 0);
    bool trobat = false;
    for (int i = 0; i < n; i++){
        suma = 0;
        for (int j = 0; j < n; j++){
            suma += a[i][j];
        }
        sumes[i] = suma;
    }
    int i = 0;
    while (i < n and not trobat){
        
        if ((i+1 < n) and (sumes[i] != sumes[i+1])) trobat = true;
        else i++;
    }
    return not trobat;
}
bool vertical(const int& n, const Matriu& a){
    //PRE: Matriu a de nxn 
    //POST: Retorna si la suma dels elements verticals es igual en totes les columnes.
    int suma = 0;
    int i = 0;
    vector <int> sumes(n, 0);
    bool trobat = false;
    for (int i = 0; i < n; i++){
        suma = 0;
        for (int j = 0; j < n; j++){
            suma += a[j][i];
        }
        sumes[i] = suma;
    }
    while (i < n and not trobat){
        
        if ((i+1 < n) and (sumes[i] != sumes[i+1])) trobat = true;
        else i++;
    }
    return not trobat;
}
bool diagonals(const int& n, const Matriu& a){
    //PRE: Matriu a de nxn 
    //POST: Retorna si la suma dels elements diagonals es igual en totes les files i columnes.
    int suma1 = 0;
    int suma2 = 0;
    bool trobat = false;
    for (int i = 0; i < n; i++){
  
        for (int j = 0; j < n; j++){
            if (i == j) suma1 += a[i][j];
        }
    }
    for (int i = 0; i < n; i++){

        for (int j = 0; j < n; j++){
            if (i == (n - j - 1)) suma2 += a[i][j];
        }
    }   
    if ((suma1 != suma2)) trobat = true;
        
    
    return not trobat;
}
bool es_magic(const Matriu& a, const int& n){
    if(horitzontal(n, a) and vertical(n, a) and diagonals(n, a)) return true;
    else return false;
}
int main(){
    int n;

    while (cin >> n){
        Matriu a(n, Fila(n));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> a[i][j];
            }   
        }
        if(es_magic(a, n)) cout << "yes\n";
        else cout << "no\n";
    }
}