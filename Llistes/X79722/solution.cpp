//Author: icorn1
#include "llista.hpp"
#include <iostream>

void Llista::separa(Llista &l2, int x){
//Pre: l2 es buida.
//Post: separa els elements del p.i. mes grans que x en la llista l2, els menors de x resten al p. i.
    
    if (_long > 0){
    
        node *aux = _prim->seg;
        node *aux2 = l2._prim->seg;

        while (aux != _prim){
            
            if(aux->info > x){
                node *p = new node;

                p->info = aux->info;

                if(l2._long > 0)
                    aux2->seg->ant = p;
                else
                    aux2->ant = p;

                p->seg = aux2->seg;
                p->ant = aux2;

                aux2->seg = p;
                aux2 = aux2->seg;
                
                node *pelim = aux;

                aux->seg->ant = aux->ant;
                aux->ant->seg = aux->seg;
                aux = aux->seg;

                delete pelim;
                l2._long++;
                _long--;

            }
            else if (aux->info < x){
                aux = aux->seg; //en el cas de que aux->info < x, nomes cal aquesta instruccio
            }
            else{
                node *pelim = aux;

                aux->seg->ant = aux->ant;
                aux->ant->seg = aux->seg;
                aux = aux->seg;

                delete pelim;
                --_long;
            }
            
        }

    }

}