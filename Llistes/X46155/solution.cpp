//Author: icorn1
#include "llista.hpp"
#include <iostream>

void Llista::eliminaposicionsparells(){

    if (_long > 0){

        nat i = 1;			//Usem aquesta variable per saber la posicio de la llista en la que estem

        node *aux1 = _prim;		//Usem aquest node per recorrer la llista.

        node *aux = NULL;

        while (aux1 != NULL){	

            if(i%2 == 0){	//Si posicio = parell.

                node *pelim = aux1;

                aux->seg = aux1->seg;

                aux1 = aux1->seg;       //Avancem el while

                delete pelim;

                _long--;                //Reduim la longitud original
            
            }
            else{

                aux = aux1;
                
                aux1 = aux1->seg;
                
            }
            
    
            i++;        //S'incrementa i 
        }
        
    }

}

