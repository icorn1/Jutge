//Author: icorn1
#include <iostream>

using namespace std;

int main(){

    int n, x, cont = 0;
    char aOb = '_';
    cin >> n;
    n *= 2;

    int r, digitCentral, digitControl, aux, contAux;
    while (n > 0){
        cin >> x;
        aux = x;
        cont++;
        contAux = 0;

        while (aux > 0){

            contAux++;
            aux /= 10;
        }  //cout << contAux << endl;
        if (contAux == 0) r = 0;
        else {
            if (contAux % 2 == 1) digitCentral = (contAux / 2) +1;
            else {
                
                if (cont%2 == 0)aOb = 'A';
                else aOb = 'B';
                break;
            }
        

            //cout << digitCentral << endl;
            while (digitCentral > 0){
                r = x%10;
                x = x / 10;
                digitCentral--;

            }  
        }
        //cout << r << endl;
        if (cont == 1) digitControl = r;
        
        if (r != digitControl) {
            if (cont%2 == 0)aOb = 'A';
            else aOb = 'B';
            break;
        }

        n--;
    }  

    if (aOb == '_') cout << "=" << endl;
    else cout << aOb << endl;


}