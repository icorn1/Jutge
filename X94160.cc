//Author icorn1
#include <iostream>
#include <stack>
using namespace std;

template <typename T>
stack<T> reversa(stack<T> p){
    stack<T> aux;
    while(!p.empty()) {
        T element = p.top();
        p.pop();
        aux.push(element);
    }
   return aux;
}

template <typename T>
void ordena(stack<T>& p){
    int sz = p.size();
    if(sz > 1){
        int m = sz/2;
        int n = sz-m;                                
        stack<T> p1, p2;
        for(int i = 0; i < m; i++){
            p1.push(p.top());
            p.pop();
        }
        for(int i = 0; i < n; i++){
            p2.push(p.top());
            p.pop();
        }
        ordena(p1);
        ordena(p2);
        p1 = reversa(p1);
        p2 = reversa(p2);
        while(!p1.empty() && !p2.empty()){
            if(p1.top() < p2.top()){
                p.push(p2.top());
                p2.pop();
            }
            else{
                p.push(p1.top());
                p1.pop();
            }
        }
        while(!p1.empty()){
            p.push(p1.top());
            p1.pop();
        }
        while(!p2.empty()){
            p.push(p2.top());
            p2.pop();
        }

    }
}

/* COMPILACIO JUTGE
template <typename T>
void mostra(stack<T> p) {
  while (not p.empty()) {
    cout << p.top() << ' ';
    p.pop();
  }
  cout << endl;
}

int main() {
  int n;
  while (cin >> n) {
    stack<double> p;
    for (int i=0; i<n; ++i) {
      double x;
      cin >> x;
      p.push(x);
    }

    ordena<double>(p);

    mostra<double>(p);
  }
  return 0;
}
*/