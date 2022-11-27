//Author: icorn1
#include <iostream>
#include <vector>

using namespace std;

void min_heap(vector<int>& arr, int i, int tam)
{
    int min, e = (2*i) + 1, d = e + 1;

    if(e < tam && arr[e] < arr[i])
        min = e;
    else
        min = i;

    if(d < tam && arr[d] < arr[min])
        min = d;

    if(min != i)
    {
        int aux = arr[i];
        arr[i] = arr[min];
        arr[min] = aux;
        min_heap(arr, min, tam);
    }
}

void crea_min_heap(vector<int>& arr)
{
    for(int i = (arr.size() / 2); i >= 0; --i)
    min_heap(arr, i, arr.size());
}

void heap_sort_min(vector<int>& arr)
{
   crea_min_heap(arr);
   int sz = arr.size();
   for(int i = arr.size() - 1; i > 0; --i)
   {
        int aux = arr[0];
        arr[0] = arr[i];
        arr[i] = aux;
        sz--;
        min_heap(arr, 0, sz);
    }
}


void max_heap(vector<int>& arr, int i, int tam)
{
    int max, e = (2*i) + 1, d = e + 1;

    if(e < tam && arr[e] > arr[i])
        max = e;
    else
        max = i;

    if(d < tam && arr[d] > arr[max])
        max = d;

    if(max != i)
    {
        int aux = arr[i];
        arr[i] = arr[max];
        arr[max] = aux;
        max_heap(arr, max, tam);
    }
}

void crea_max_heap(vector<int>& arr)
{
    for(int i = (arr.size() / 2); i >= 0; --i)
        max_heap(arr, i, arr.size());
}

void heap_sort_max(vector<int>& arr)
{
   crea_max_heap(arr);
   int sz = arr.size();
   for(int i = arr.size()-1; i > 0; --i)
   {
        int aux = arr[0];
        arr[0] = arr[i];
        arr[i] = aux;
        sz--;
        max_heap(arr, 0, sz);
    }
}

int main()
{
    int elem;
    vector<int> arr1, arr2;
    while(cin >> elem){
        arr1.push_back(elem);
    }
    arr2 = arr1;
    heap_sort_max(arr1);
    
    if(arr1.size() > 0) cout << arr1[0];
    for(int i = 1; i < arr1.size(); i++)
    {
        cout << " "  << arr1[i];
    }
    cout << "\n";

    heap_sort_min(arr2);
    
    if(arr2.size() > 0) cout << arr2[0];
    for(int i = 1; i < arr2.size(); i++)
    {
        cout << " "  << arr2[i];
    }
    cout << "\n";
}