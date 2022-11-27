#include "llista.hpp"
#include <iostream>

void Llista::separa(Llista &l2){

    if (_long > 0){

        nat i = 1;

        node *aux1 = _prim;

        node *aux2 = l2._prim;

        node *_aux1 = NULL;

        while (aux1 != NULL){

            if(i%2 == 0){

                if(i == 2){         //Primera iteracio
                    l2._prim = aux1;
                    aux2 = l2._prim;
                }
                
                else{

                    aux2->seg = aux1;
                    aux2 = aux2->seg;
                
                }

                _aux1->seg = aux1->seg; //El node seguent de la posicio senar anterior es el seguent del node actual.

                aux1 = aux1->seg;       //Avancem el while

                _long--;                //Reduim la longitud original
                l2._long++;             //Augmentem la longitud de la nova llista
            
            }
            else{
                
                _aux1 = aux1;           //guardem el node
               
                aux1 = aux1->seg;       //Avancem el while
                
            }
            
    
            i++;        //S'incrementa i 
        }
        
    }

}