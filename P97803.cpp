//Author: icorn1
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

void invertir_pila(stack <string> &pila){

	stack <string> aux;
    for (stack <string> dump = pila; !pila.empty(); pila.pop()){
        aux.push(pila.top());
    }
    pila = aux;

}

vector < stack <string> > llegir_piles(const int &num_piles){
	string s;
	vector < stack <string> > piles (num_piles);
	getline(cin, s);

	for (int i = 0; i < num_piles; i++) {
		getline(cin, s);
		istringstream ss(s);
		string llibre;
		
		while(ss >> llibre) {
			
			piles[i].push(llibre);
		
		}
	}

	return piles;
}

void missatge_final(vector < stack <string> > piles){

	for (unsigned int i = 0; i < piles.size(); i++){

        cout << "Pila " << i+1 << ":";
		if(piles[i].size() > 0) cout << " ";

		invertir_pila(piles[i]);
        for (stack <string> dump = piles[i]; !dump.empty(); dump.pop()){
            cout << dump.top();
            if (dump.size() > 1) cout << " ";
        
        }
	
		cout << endl;
    }
}

int main(){

	int num_piles;
	cin >> num_piles;
	string s;
	vector < stack <string> > piles = llegir_piles(num_piles);

	//getline(cin, s);
	while(getline(cin, s)){
		istringstream ss(s);
		string ordre; 
		ss >> ordre;
		if (ordre == "PRESTEC"){
			int nc;
			ss >> nc;
			if (nc > 0 and nc <= num_piles and (piles[nc-1].size() > 0)){
				piles[nc-1].pop();
			}
		}
		
		else if (ordre == "RETORN"){
			string llibre;
			int nc;
			ss >> llibre;
			
            ss >> nc;
	
			if (nc > 0 and nc <= num_piles){
				piles[nc-1].push(llibre);
			}
		}
	}
	
	missatge_final(piles);

}