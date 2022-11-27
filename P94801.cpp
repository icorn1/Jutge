//Author: icorn1
#include <iostream>
#include <vector>
using namespace std;

bool es_triangle_rectangle(int a, int b, int c){
    if(((a*a) + (b*b)) != (c*c) and ((a*a) + (c*c)) != (b*b) and ((c*c) + (b*b)) != (a*a)) return false;
    return true;
}

int main(){
    int x;
    vector <int> elems;
    while(cin >> x){
        elems.push_back(x);
    }
    int triplets = 0;
    int i = 0, j = 1;
    for(int k =2; k < int(elems.size()); k++){
        if(es_triangle_rectangle(elems[i], elems[j], elems[k])) triplets++;
        i++;
        j++;
    }
    cout <<triplets << endl;
    /*
    PER FER C(elem.size, 3) iteracions:

    
    int triplets = 0;
    int k = 2;
    int j = 1;
    for(int i = 0; i < int(elems.size()); i++){
        j = i+1;
        for(; j < int(elems.size()); j++){

            k= j+1;
            for(; k < int(elems.size()); k++){

                if(es_triangle_rectangle(elems[i], elems[j], elems[k]))
                    triplets++;
                //cout << i << " " << j << " " << k << endl;
                
            }

        }

    }
    cout << triplets << endl;
    */

}