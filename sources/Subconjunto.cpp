#include <iostream>
#include <array>

#define ARRAYSIZE(a) (sizeof(a))/(sizeof(a[0]))

using namespace std;

template <class T>
class Nodo{
    public:
    T key;
    Nodo<T> *left, *right/**parent*/;

    Nodo(T valor){
        key = valor;
        left = NULL;
        right = NULL;
        //parent = NULL;
    }

    ~Nodo(){
        delete left;
        delete right;
        //delete parent;
    }
};

template <class T>
class AVLTree{
    public:
        Nodo<T> *raiz;

        AVLTree(){
            raiz = NULL;
        }

        void insertar(T value){
            Nodo<T> *nuevo = new Nodo<T>(value);
            Nodo<T> *temp = raiz;
            while(temp!=NULL){
                if(value < temp->value){
                    if(temp->left == NULL){
                        temp->left = nuevo;
                    }else{
                        temp = temp->left;
                        return;
                    }
                }
                else if(value > temp->value){
                    if(temp->right == NULL){
                        temp->right = nuevo;
                    }else{
                        temp = temp->right;
                        return;
                    }
                }
            }
        }

        /*void subconjuntoSuma(int conjuntos[], int pos, int cantidad, int suma, int nElementos, bool & val){
            int solucion[6];
            if(cantidad == suma){
                val = true;
            }
            for(int i = pos; i < nElementos; ++i){
                if(suma + conjuntos[i] <= cantidad){
                    suma += conjuntos[i];
                    subconjuntoSuma(conjuntos, i+1, cantidad, suma, nElementos, val);
                    suma -= conjuntos[i];
                    
                }
            }
        }*/
        
        void subconjuntoSuma(int solucion[], int init, int suma, int cantidad, int n, int conjunto[], int r){
            solucion[init] = 1;
            if(suma+conjunto[init] == cantidad){
                //guardar(init); //lo tengo que hacer
            } else if(init == n){
                return;
            } else if(suma+conjunto[init]+conjunto[init+1] <= cantidad){
                //cout<<suma+conjunto[init]<<endl;
                subconjuntoSuma(solucion, init+1, suma+conjunto[init], cantidad, n, conjunto, r-conjunto[init]);
                cout<<"no"<<endl;
            }
            if((suma+r-conjunto[init] >= cantidad) && (suma+conjunto[init+1] <= cantidad)){
                solucion[init] = 0;
                subconjuntoSuma(solucion, init+1, suma, cantidad, n, conjunto, r-conjunto[init]);
                cout<<"si"<<endl;
            }
        }
        void imprimir(int solucion[]){
            for(int i=0; i<6; ++i){
                cout<<solucion[i]<<", ";
            }
            cout<<endl;
        }

};

int main(){
    int cantidad = 10;
    int conjuntos[] = {2, 1, 3, 8, 9, 5};
    int solucion[6];
    int nElementos = ARRAYSIZE(conjuntos);
    int suma = 0;
    int resta = cantidad;
    bool val = false;
    AVLTree<int> s;
    //s.subconjuntoSuma(conjuntos, 0, cantidad, 0, nElementos, val);
    s.subconjuntoSuma(solucion, 0, suma, cantidad, nElementos, conjuntos, resta);
    s.imprimir(solucion);

    return 0;
}