//Author: icorn1
#include <iostream>
using namespace std;

void descompon(int n, int& h, int& m, int& s){

        if (n > 3599){

            h = n / 3600;
            m = (n % 3600) / 60;
            s = (n % 3600) % 60;
            //cout << h << " " << m << " " << s << endl;
        }
        else if (n < 3600 and n > 59) {
            h = 0;
            m = n / 60;
            s = (n % 60);
            //cout << h << " " << m << " " << s << endl;


        }
        else {
        	h = 0;
        	m = 0;
            s = n;
        	//cout << h << " " << m << " " << s << endl;
        	
        }

}


int main(){

int h = 0, m = 0, s = 0;
int num;
cin >> num;
 descompon(num, h, m, s);

 cin >> num;
 h = 0; m = 0; s = 0;
 descompon(num, h, m, s); 


}

// descompon(147) → 0 2 27
// descompon(100000) → 27 46 40