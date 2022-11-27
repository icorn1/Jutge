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
		node *aux = _prim;
	
		for(int i = 0; i < v.size(); i++){
		
		
			node *p = new node;
			p->info = v[i];
			
			if (aux == NULL){
			
				aux = p;
			
			}
			else{
			
				aux->seg = p;
				aux = aux->seg;
			
			}
		
		
		
			_long++;
		}
	
	
	}
	
}
