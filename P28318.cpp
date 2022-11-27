//Author: icorn1
#include <iostream>
using namespace std;

int main (){
    int n, m;
    cin >> n >> m;
    int A[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> A[i][j];

    string opcio;
    while (cin >> opcio){
        int x, y;
        if (opcio == "fila"){
            cin >> x;
            cout << "fila " << x << ": "; 
            for (int i = 0; m > i; i++){
                cout << A[x-1][i];
                if (m-1 != i) cout << " ";
                
            }
            cout << endl;
        } 
        else if (opcio == "columna"){
            cin >> x;
            cout << "columna " << x << ": "; 
            for (int i = 0; n > i; i++){
                cout << A[i][x-1];
                if (n-1 != i) cout << " ";
                
            }
            cout << endl;
        }
        else if (opcio == "element"){
            cin >> x >> y;
            cout << "element " << x << " " << y << ": "; 
            cout << A[x-1][y-1];
            cout << endl;
        }
    }
}