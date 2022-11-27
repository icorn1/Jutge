//Author: icorn1
//Es pot optimizar bastant crec
#include "llista.hpp"
#include <iostream>

void Llista::duplica_positius_elimina_negatius(){

    if (_long > 0){

        node *aux1 = _prim;		//Usem aquest node per recorrer la llista.

        node *help = NULL;        //Node auxiliar

        while (aux1 != NULL){	

            if(aux1->info > 0){	//Si element = positiu.
            
				node *p = new node;	//Creem el nou node que inserirem devant del auxiliar
				
				p->info = aux1->info;
				
				p->seg = aux1->seg;
				
				aux1->seg = p;

                help = p;
				
				aux1 = aux1->seg->seg;		//avançem dos poscions ja que acabem d'inserir un element
				
				_long++;			//augmentem la longitud.
            
        	}
            else if (aux1->info < 0) {			//si element = negatiu
            
            	node *pelim = aux1;

                if(help != NULL){

                    help->seg = aux1->seg;
                }

                else{

                    _prim = aux1->seg;

                }

                aux1 = aux1->seg;       //Avancem el while

                delete pelim;

                _long--;                //Reduim la longitud original
                
            }
            else {
                help = aux1;
                aux1 = aux1->seg;
            }
 
            
        }
        
        
    }

}

