//Author: icorn1
#include "llista.hpp"
#include <iostream>

Llista::Llista(const vector<int> &v){
	
	if(v.size() == 0){
		
		_prim = NULL;
		_long = 0;
	
	}	
	else{	
		_prim = NULL;
		_long = 0;
		node *aux = NULL;
	
		for(int i = 0; i < v.size(); i++){
		
			node *p = new node;
			p->info = v[i];
            p->seg = NULL;
			
			if (_prim == NULL){
			
				_prim = p;
				aux = _prim;
			
			}
			else if (aux != NULL){
			
				aux->seg = p;
				aux = aux->seg;
			
			}
		
		
		
			_long++;
		}
	
	
	}
	
}








/*
#include "llista.hpp"
#include <iostream>

Llista::Llista(const vector<int> &v){

    if(v.size() == 0) {
        _prim = NULL;
        _long = 0;
    }
    else {

        _long = 0;

        node* aux = NULL;

        for(int i = int(v.size())-1; i >= 0; i--){  //Fem un for que recorri el vector de forma descendent, seguint el ordre dels nodes de la llista
            
            node* p = new node; 
            
            p->info = v[i];     //Aquesta instrucció es repeteix sempre, juntament amb long++.
            
            if(i == int(v.size())-1 && v.size() == 1){      //Cas 1: que el vector sigui mida 1: p es l'unic element, p->seg null i _prim = p.
                
                p->seg = NULL;
                _prim = p;
                
            }
            else if(i == 0){          //Cas 2: i == 0. En aquest cas, _prim es igual a p.

                _prim = p;
                p->seg = aux;

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

*/

