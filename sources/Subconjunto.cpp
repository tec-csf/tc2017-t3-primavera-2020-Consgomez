/*
    Subconjunto.cpp
    Encuentra el subconjunto que al sumarse, nos da como resultado un número deseado
    Constaza Gómez Sánchez
    12 de abril de 2020
*/
#include <iostream>
#include <array>
#include <vector>

#define ARRAYSIZE(a) (sizeof(a))/(sizeof(a[0]))

using namespace std;

/* Subconjunto: this class defines the methods to find the subset
*/
class Subconjunto{
    public:
    vector<int> solucion;

    /* suma: this method finds the numbers that will be part of the solution
    * @param position, sum of numbers, size of array, array and the sum we are looking for
    * @return true when solutions are found
    */
    bool suma(int pos, int sum, int n, int conjunto[], int cant){
        if(sum>cant){
            return false;
        }
        if(sum == cant){
            imprimir();
            return false;
        }
        for(int i=pos; i<n; ++i){
            solucion.push_back(conjunto[i]);
            if(suma(i+1, sum+conjunto[i], n, conjunto, cant)){
                return true;
            }
            solucion.pop_back();
        }
        return false;
    }

    /* imprimir: this method prints out a vector when a solution is found
    * @return void
    */
    void imprimir(){
        vector<int> temp;

        cout<<"[ ";
        while(!solucion.empty()){
            cout<<solucion.back()<<" ";
            temp.push_back(solucion.back());
            solucion.pop_back();
        }
        cout<<"]"<<endl;
        while(!temp.empty()){
            solucion.push_back(temp.back());
            temp.pop_back();
        }
    }
};

int main(){
    int conjunto[] = {2, 1, 3, 8, 9, 5};
    int cant = 10;
    int n = ARRAYSIZE(conjunto);
    Subconjunto s;
    cout<<"Los subconjuntos son: "<<endl;
    s.suma(0, 0, n, conjunto, cant);

    return 0;
}