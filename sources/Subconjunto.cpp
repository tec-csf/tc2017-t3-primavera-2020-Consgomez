#include <iostream>
#include <array>
#include <vector>

#define ARRAYSIZE(a) (sizeof(a))/(sizeof(a[0]))

using namespace std;

class Subconjunto{
    public:
    bool exito; 
    bool done;
    vector<int> solucion;

    void suma(int pos, int sum, int n, int conjunto[], int cant){
        done = true;
        if(sum>cant){
            exito = false;
            done = false;
        }
        if(sum == cant){
            exito = true;
            imprimir();
            done = false;
        }
        for(int i=pos; i<n; ++i){
            solucion.push_back(conjunto[i]);
            if(sum<cant){
                suma(i+1, sum+conjunto[i], n, conjunto, cant);
                done = true;
            }
            if(exito == false){
                solucion.pop_back();
            }
        }
        done = false;
    }

    void imprimir(){
        cout<<"[";
        while(!solucion.empty()){
            cout<<solucion.back()<<" ";
            solucion.pop_back();
        }
        cout<<"]"<<endl;
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