//Author: icorn1
#include "llista.hpp"
#include <iostream>

void Llista::duplica(){

    node *aux = _prim;

    while (aux != NULL){

        node *p = new node;

        p->info = aux->info;    //copiem el valor del node

        p->seg = aux->seg;      //copiem el valor del camp seg d'aux al de "seg" de p.

        aux->seg = p;           //posicionem el node nou a la llista.

        aux = aux->seg->seg; //saltem dos posicions perque acabem d'inserir un nou element

        _long++;             // augmentem la longitud de la llista.

    }

}