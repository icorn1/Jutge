//Author: icorn1
#include "llista.hpp"
#include <iostream>

void Llista::separa(Llista &l2){

    if (_long > 0){

        nat i = 1;			//Usem aquesta variable per saber la posicio de la llista en la que estem

        node *aux1 = _prim;		//Usem aquest node per recorrer la llista.

        node *aux2 = l2._prim;	//Usem aquest node per recorrer l'altra llista.

        node *_aux1 = NULL;		//Usem aquest node com a auxiliar per encadenar la llista.

        while (aux1 != NULL){	

            if(i%2 == 0){	//Si posicio = senar.

                if(i == 2){         //Primera iteracio
                    l2._prim = aux1;
                    aux2 = l2._prim;
                }
                
                else{		     //Altres iteracions

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
                
                if(i != 1)
                	aux2->seg = NULL;   //li donem valor al seguent de aux2 en el cas de que no en tingui.
                
            }
            
    
            i++;        //S'incrementa i 
        }
        
    }

}