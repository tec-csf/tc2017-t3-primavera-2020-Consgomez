#include <iostream>
#include <array>

#define ARRAYSIZE(a) (sizeof(a))/(sizeof(a[0]))

using namespace std;

template <class T, class V, class S>
class Nodo{
    public:
    T key;
    V value;
    S sum;
    Nodo<T,V,S> *left, *right/**parent*/;

    Nodo(T llave, V val, S suma){
        key = llave;
        value = val;
        sum = suma;
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

template <class T, class V, class S>
class AVLTree{
    public:
        Nodo<T, V, S> *raiz;
        int sumatoria;

        AVLTree(){
            raiz = NULL;
        }

        void insertar(T llave, V val){
            if(llave == 1){
                sumatoria += val;
            } else if(llave == 0){
                sumatoria += 0;
            }
            Nodo<T,V,S> *nuevo = new Nodo<T,V,S>(llave, val, sumatoria);
            if(raiz == NULL){
                raiz = nuevo;
            }else{
                Nodo<T,V,S> *temp = raiz;
                //cout<<nuevo->value<<endl;
                while(temp!=NULL){
                    if(llave == 1){
                        if(temp->left == NULL){
                            temp->left = nuevo;
                        }else{
                            temp = temp->left;
                            return;
                        }
                    }
                    else if(llave == 0){
                        if(temp->right == NULL){
                            temp->right = nuevo;
                        }else{
                            temp = temp->right;
                            return;
                        }
                    }
                }
            }
        }

        void postorden(){
            postordenAux(raiz);
            cout<<endl;
        }

        void postordenAux(Nodo<T,V,S> *actual){
            if(actual==NULL){
                return;
            }
            postordenAux(actual->left);
            cout<<"(";
            cout<<actual->key;
            cout<<", ";
            cout<<actual->value;
            cout<<", ";
            cout<<actual->sum;
            cout<<") ";
            postordenAux(actual->right);
        }

        void suma(int conjuntos[], int suma, int init, int n){
            int valor;
            for(int i=init; i<n; ++i){
                valor = conjuntos[init];
            }
            insertar(-1,-1);
            insertar(0, valor);
            insertar(1, valor);
            insertar(1, 3);
        }

        void subconjuntoSuma(int solucion[], int init, int suma, int cantidad, int n, int conjunto[], int r){
            solucion[init] = 1;
            if(suma+conjunto[init] == cantidad){
                //guardar(init); //lo tengo que hacer
            } else if(init == n){
                return;
            } else if(suma+conjunto[init]+conjunto[init+1] <= cantidad){
                //cout<<suma+conjunto[init]<<endl;
                subconjuntoSuma(solucion, init+1, suma+conjunto[init], cantidad, n, conjunto, r-conjunto[init]);
                cout<<"no suma: "<<suma<<endl;
            }
            if((suma+r-conjunto[init] >= cantidad) && (suma+conjunto[init+1] <= cantidad)){
                solucion[init] = 0;
                subconjuntoSuma(solucion, init+1, suma, cantidad, n, conjunto, r-conjunto[init]);
                cout<<"si suma: "<<suma<<endl;
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
    AVLTree<int, int, int> s;
    s.subconjuntoSuma(solucion, 0, 0, cantidad, nElementos, conjuntos, resta, val);
    //s.subconjuntoSuma(solucion, 0, suma, cantidad, nElementos, conjuntos, resta);
    //s.suma(conjuntos, suma, 0, nElementos);
    //s.postorden();
    //s.imprimir(solucion);

    return 0;
}