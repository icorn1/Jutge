//Author: icorn1
#include "llista.hpp"
#include <iostream>

void Llista::separa(Llista &l2, int x){
//Pre: l2 es buida.
//Post: separa els elements del p.i. mes grans que x en la llista l2, els menors de x resten al p. i.
    
    if (_long > 0){
    
        node *aux = _prim;
        node *aux2 = l2._prim;
        node *help = NULL;
        node *help2 = NULL;

        while (aux != NULL){

            if(aux->info > x){
                node *p = new node;

                p->info = aux->info;

                p->seg = NULL;

                if (help != NULL)
                    help->seg = p;

                if (l2._prim == NULL){
                    l2._prim = p;
                }
                aux2 = p;
                
                help = aux2;

                aux2 = aux2->seg;

                if(help2 != NULL){//provisional
                    help2->seg = NULL;
                }

                node *pelim = aux;

                if(aux == _prim){
                    _prim = aux->seg;
                }

                aux = aux->seg;

                delete pelim;

                l2._long++;
                _long--;

            }
            else if (aux->info < x){
                if(help2 != NULL)
                    help2->seg = aux;

                help2 = aux;

                aux = aux->seg;

            }
            else{
                node *pelim = aux;

                if(aux == _prim){
                    _prim = aux->seg;
                }

                aux = aux->seg;

                if(help2 != NULL){//provisional
                    help2->seg = NULL;
                }

                delete pelim;

                --_long;
            }

        }

    }

}