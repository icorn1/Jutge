//Author: icorn1
#include "llista.hpp"
#include <iostream>

void Llista::duplica(){

    node *aux = _prim->seg;

    while (aux != _prim){

        node *p = new node;

        p->info = aux->info;    //copiem el valor del node

        p->seg = aux->seg;      //copiem el valor del camp seg d'aux al de "seg" de p.

        aux->seg->ant = p;      //Assignem p com el element anterior al seguent del node aux original

        aux->seg = p;           //posicionem el node nou a la llista.

        p->ant = aux;           //Assignem el anterior de p com al auxiliar 

        aux = aux->seg->seg; //saltem dos posicions perque acabem d'inserir un nou element

        _long++;             // augmentem la longitud de la llista.

    }

}