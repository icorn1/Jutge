//Author: icorn1
#include "llista.hpp"
#include <iostream>

using namespace std;

void Llista::fusiona_suma(Llista &l2, nat n){

    int suma = 0;

    node *aux1 = _prim->seg;

    node *aux2 = l2._prim->seg;

    node *help;

    int max;

    if(_long > l2._long){   //Hem de restablir n per ajustar el maxim de iteracions a la longitud de llista maxima
        max = _long;
    }
    else
        max = l2._long;

    if (n > max) n = max;

    int i = 1;

    node *pant = NULL; //Aquest node en servira en cas de que l2 sigui mes llarga que el parametre implicit.

    //Fem la suma dels nodes.
    while(aux1 != NULL){
        suma += aux1->info;
        aux1 = aux1->seg;
    } aux1 = _prim->seg;
    while(aux2 != NULL){
        suma += aux2->info;
        aux2 = aux2->seg;
    } aux2 = l2._prim->seg;

    while (aux1 != NULL && aux2 != NULL){
        pant = aux1;
        for (; i < n && aux1 != NULL; i++){
            aux1 = aux1->seg;
        }
        i = 0;
        if (aux1 == NULL) break; // cas en que l2._long > _long i n = 1; cal sortir del bucle.

        help = aux1->seg;
        for (int i = 0; i < n && aux2 != NULL; i++){
            node *p = new node;
            p->info = aux2->info;
            p->seg = NULL;
            
            aux1->seg = p;
            aux1 = aux1->seg;
            
            aux2 = aux2->seg;
            _long++;
        }
        aux1->seg = help;
    }

    node *ps = new node;    //inserim la suma al principi
    ps->info = suma;
    ps->seg = _prim->seg;
    _prim->seg = ps;
    _long++;

    if(pant == NULL) pant = _prim->seg;

    while (aux2 != NULL){

        node *p = new node;

        p->info = aux2->info;

        p->seg = NULL;
        
        pant->seg = p;

        pant = pant->seg;

        aux2 = aux2->seg;   

        _long++;

    }   
    
    aux2 = l2._prim->seg;  //esborrem l2
    l2._prim->seg = NULL;
    l2._long = 0;

    /*
    while (aux2 != NULL){
        node *pelim = aux2;
        aux2 = aux2->seg;
        delete pelim;
        --l2._long;
    }
    */
    











    /*

    int suma = 0;

    node *aux1 = _prim;

    node *aux2 = l2._prim;

    node *help = NULL;

    int cont = 0;
    node *it = NULL;
    while (aux1 != NULL && aux2 != NULL){



        
        for (int i = 0; i < n && aux1->seg != NULL; i++){
            if(cont != 0)
                aux1 = aux1->seg;
           
        }

        cont++;
        
        for (int j = 0; j < n && aux2 != NULL; j++){
             cout << "flag\n";
            if(j == 0){
                aux1->seg = aux2;
                it = aux1->seg;
                aux1 = aux1->seg;
            }
            else{
                it->seg = aux2;
                it = it->seg;
                aux1 = aux1->seg;
            }
            aux2 = aux2->seg;
            _long++;
        }
        cout << "\n\n";

        if(aux1->seg == NULL){
            help = aux1;
        }
    }

    while (aux2 != NULL){

        if(help != NULL){
        cout << "flag\n";
        help->seg = aux2;
        help = help->seg;
        help->seg = NULL;   //aux1 no hauria de tenir seguent si entra al while
        aux2 = aux2->seg;
        }

    }

    node *ps = new node;    //inserim la suma al principi
    ps->info = suma;
    ps->seg = _prim;
    _prim = ps;
    _long++;
    
    
    aux2 = l2._prim;  //esborrem l2
    while (aux2 != NULL){
        node *pelim = aux2;
        aux2 = aux2->seg;
        delete pelim;
    }
    */

}
