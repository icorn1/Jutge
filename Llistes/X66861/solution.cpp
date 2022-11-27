//Author: icorn1
#include "llista.hpp"
#include <iostream>

void Llista::duplica_majors_elimina_menors(){

    if (_long > 0 && _prim->seg != NULL){

        node *aux1 = _prim->seg->seg;		//Usem aquest node per recorrer la llista.

		node *pant = new node;

		pant->info = _prim->seg->info;

        while (aux1 != _prim){	

            if(pant->info < aux1->info){	//Si element anterior < actual.
            
				node *p = new node;	//Creem el nou node que inserirem devant del auxiliar
				
				p->info = aux1->info;
				
				p->seg = aux1->seg;
				
				p->ant = aux1;

				aux1->seg->ant = p;
				
				aux1->seg = p;

				pant->info = aux1->info;
				
				aux1 = aux1->seg->seg;		//avançem dos poscions ja que acabem d'inserir un element
				
				_long++;			//augmentem la longitud.

            
        	}
            else if (pant->info > aux1->info){			//si element = senar
            
            	node *pelim = aux1;

				pant->info = aux1->info;

				aux1->ant->seg = aux1->seg;

				aux1->seg->ant = aux1->ant;

                aux1 = aux1->seg;       //Avancem el while

                delete pelim;

                _long--;                //Reduim la longitud original
                
                
            }
			else if (pant->info == aux1->info){

				pant->info = aux1->info;
				
				aux1 = aux1->seg;

			}
 
            
        }
        
        
    }

}

