#include <iostream>
#include <sstream>
#include "llista.hpp"

int main() {
  string linea;
  while (getline(cin, linea)) {
    vector<int> v;
    istringstream ss(linea);
    int n;
    while (ss >> n) {
      v.push_back(n);
    }
    Llista l(v);
    Llista l2;
    cin >> n;
    getline(cin, linea); // Per llegir final de línia
    l.separa(l2, n);

    cout << l.longitud() << " ";
    l.mostra();
    cout << " ";
    l.mostra_invertida();
    cout << endl;

    cout << l2.longitud() << " ";
    l2.mostra();
    cout << " ";
    l2.mostra_invertida();
    cout << endl;
  }
}
