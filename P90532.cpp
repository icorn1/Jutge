//Author: icorn1
//Aquest problema fallava, F
#include <iostream>
#include <vector>

using namespace std;


struct Provincia {
         string nom;
         string capital;
         int habitants;
         int area;
         double pib;
     };
struct Pais {
         string nom;
         string capital;
         vector<Provincia> provs;
     };

typedef vector<Pais> Paisos;
// la suma dels productes interiors bruts de totes les 
// provÃ­ncies amb densitat estrictament superior a d de 
//tots els paisos en p que comencin per la lletra c.


/* El codi fet per mi no funciona. Desconec perque.

double pib(const Paisos& p, char c, double d){
   double suma = 0.0;
    for (unsigned int i = 0; i < p.size(); i++){

        if(p[i].nom[0] == c){
            for (unsigned int j = 0; j < p[i].provs.size(); j++){

                if ((p[i].provs[j].habitants/p[i].provs[j].area) > d) suma += p[i].provs[j].pib;
                
            }
        }
    }
    return suma;
}

int main(){}
*/
double pib(const Paisos& p, char c, double d) {
    int n = p.size();
    double suma = 0.0;
    for (int i = 0; i < n; ++i) {
        if (p[i].nom[0] == c) {
            int tamprov = p[i].provs.size();
            for (int j = 0; j < tamprov; ++j) {
                double hab = p[i].provs[j].habitants;
                double area = p[i].provs[j].area;
                if (hab/area > d) suma += p[i].provs[j].pib;
            }
        }
    }
    return suma;
}
