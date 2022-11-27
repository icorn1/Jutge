//Author: icorn1
#include "llista.hpp"
#include <iostream>

Llista::Llista(const vector<int> &v){

    if(v.size() == 0) {
        _prim = new node;
        _prim->seg = NULL;
        _long = 0;
    }
    else {

        _long = 0;

        node* aux = NULL;

        _prim = new node;   //Inicialitzacio dels atributs

        for(int i = int(v.size()-1); i >= 0; i--){  //Fem un for que recorri el vector de forma descendent, seguint el ordre dels nodes de la llista
            
            node* p = new node; 

            p->info = v[i];     //Aquesta instrucció es repeteix sempre, juntament amb long++.
            
            if(i == int(v.size()-1) && v.size() == 1){      //Cas 1: que el vector sigui mida 1: p es l'unic element, p->seg null i _prim = p.
                
                p->seg = NULL;
                _prim->seg = p;
                
            }
            else if(i == 0){          //Cas 2: i == 0. En aquest cas, _prim es igual a p.

                p->seg = aux;
                _prim->seg = p;
                
            }

            else if (i == int(v.size())-1){ //Cas 3: i == ultim element del vector: el seguent de p es null.

                p->seg = NULL;

            }

            else{       //Cas base: assigna a p->seg el node p de la iteracio anterior.
                
                p->seg = aux;
                
            }
            
            aux = p;    //Aqui es guarda el node de la iteracio anterior.
           
            _long++;
        }
        
    }
            
}