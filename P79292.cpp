//Author: icorn1
//Crec que no funcionava aquest, pero estava aprop
#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

bool sortbysec(const pair<string,int> &a, const pair<string,int> &b)
//Pre: a i b no son buits
//Post: retorna si a > b, ens serveix per ordenar les sortides.
{
    return (a.second > b.second);
}




vector < queue < pair <string, int> > > llegir_cues(const int &num_cues){
//Pre: per cada nom introduit hi ha una categoria valida
// Post: retorna un vector de cues amb el nom i la categoria de cada integrant de cada cua.
	int int_categoria = -1;

	string s;

	pair <string, int> persona;

	vector < queue < pair <string, int> > > cues (num_cues);

    getline(cin, s);

	for (int i = 0; i < num_cues; i++) {

		getline(cin, s);

		istringstream ss(s);

		string nom, categoria;

		while(ss >> nom >> categoria) {

            persona.first = nom;

            if (categoria == "soldat") int_categoria = 0;
            else if (categoria == "sergent") int_categoria = 1;
            else if (categoria == "capita") int_categoria = 2;
            else if (categoria == "coronel") int_categoria = 3;
            else int_categoria = -1;

            persona.second = int_categoria;

            cues[i].push(persona);
			
		
			
		}

	}

	return cues;

}

void missatge_final(queue <string> sortides, vector < queue <pair <string, int>> > cues){
//Pre: cert
//Post: escriu per pantalla les sortides que hi han hagut, i el contingut de cada cua, amb els membres ordenats per ordre de sortida

	cout << "SORTIDES" << endl << "--------" << endl;
    	int n = sortides.size();
    	for (int i = 0; i < n; ++i) {
        	cout << sortides.front() << endl;
        	sortides.pop();
    	} cout << endl;
    	
    	cout << "CONTINGUTS FINALS" << endl << "-----------------" << endl;
    	
	int n2 = cues.size();
		
    	for (int i = 0; i < n2; ++i) {
    		cout << "cua " << i+1 << ":";

			if(cues[i].size() > 0) cout << " ";

			vector <pair <string, int>> auxiliar;

			for (queue <pair <string, int> > dump = cues[i]; !dump.empty(); dump.pop()){
				auxiliar.push_back(dump.front());
			} 

			sort(auxiliar.begin(), auxiliar.end(), sortbysec);
			
			for (unsigned int j = 0; j < auxiliar.size(); j++) {
				
				cout << auxiliar[j].first;

				if (j + 1 < auxiliar.size()) cout << " ";

			}
		
			cout << endl;

		
    	}

}

int main(){

	int num_cues;

	cin >> num_cues;
	
	if (num_cues > 0){

	string s;

	vector < queue <pair <string, int>> > cues = llegir_cues(num_cues);
	
    queue <string> sortides;

	while(getline(cin, s)){

		istringstream ss(s);

		string ordre; 

		ss >> ordre;

		if (ordre == "SURT"){

			int nc;
			
            string persona_que_surt;

			ss >> nc;
			

			if (nc > 0 and nc <= num_cues and (cues[nc-1].size() > 0)){
				
                int cat_maxima = -1;

				//Primer for per obtenir categoria maxima de la cua.
				
                for(queue <pair <string, int>> dump = cues[nc-1]; !dump.empty(); dump.pop()){
                    
                    if (dump.front().second > cat_maxima) {
                        
                        cat_maxima = dump.front().second;
                        persona_que_surt = dump.front().first;
                    }
                   

                }
			
                sortides.push(persona_que_surt);

                queue <pair <string, int>> aux;
                
				for(queue <pair <string, int>> dump = cues[nc-1]; !dump.empty(); dump.pop()){

                        if (dump.front().first != persona_que_surt)          //Queda fer que tregui els memebres de la cua que no son els que 
                            aux.push(dump.front());  
						                        
                }
				
				
				cues[nc-1] = aux;
				

			}
		}
		
		else if (ordre == "ENTRA"){
			
			string nom, categoria;

			int cua, int_categoria;
			
			pair <string, int> persona;

			ss >> nom >> categoria >> cua;
				
			if(cua > 0 and cua <= num_cues){
				
				persona.first = nom;

				if (categoria == "soldat") int_categoria = 0;
                else if (categoria == "sergent") int_categoria = 1;
                else if (categoria == "capita") int_categoria = 2;
                else if (categoria == "coronel") int_categoria = 3;
                else int_categoria = -1;

				persona.second = int_categoria;

				cues[cua-1].push(persona);
				
			}
			
		}
		
	}

	missatge_final(sortides, cues);
	}

}