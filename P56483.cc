//Author icorn1
#include <iostream>
#include <vector>
#include <list>
using namespace std;

typedef unsigned int nat;

void DFS(int v, const int desti, vector< pair <vector<nat >, bool> > &llista, bool &trobat)
{
    // Mark the current node as visited and
    llista[v].second = true;
    if(v == desti){
        trobat = true;
    }
    // Recur for all the vertices adjacent
    // to this vertex
    if(!trobat){
        for(nat i = 0; i < llista[v].first.size(); ++i){
            int vert = llista[v].first[i];
            if(!llista[vert].second){
                DFS(vert, desti, llista, trobat);
            }

        }
    }
}

int main(){

    nat nvertex, narcs;
    cin >> nvertex >> narcs;

    vector< pair <vector<nat >, bool> > llista(nvertex);
    //El bool representa "vist" per cada vertex

    // Llegim les m arestes
    nat u, v;
    for(nat i = 0; i < narcs; i++) {
        cin >> u >> v; // Aresta que connecta vèrtex u amb vèrtex v
        llista[u].first.push_back(v);
        llista[u].second = false;
    }

    int x, y;
    cin >> x >> y;

    bool trobat = false;
    DFS(x,y,llista, trobat);
    if(!trobat)
        cout << "no\n";
    else cout << "yes\n";

}



