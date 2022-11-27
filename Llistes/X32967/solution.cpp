//Author: icorn1
#include "llista.hpp"
#include <iostream>

Llista::Llista(const vector<int> &v){

    if(v.size() == 0) {

        _prim = new node;   //_prim es el fantasma

        _prim->seg = _prim;  

        _prim->ant = _prim;

        _long = 0;
    }
    else {

        _long = v.size();
        _prim = new node; 
        _prim->seg = _prim;
        _prim->ant = _prim;

        node *p_ant = _prim;

        for (int i = 0; i < int(v.size()); i++) {

            node *p = new node;

            p->info = v[i];

            p->ant = p_ant;

            p_ant->seg = p;

            p->seg = _prim;

            _prim->ant = p;

            p_ant = p;
        }
    }
            
}