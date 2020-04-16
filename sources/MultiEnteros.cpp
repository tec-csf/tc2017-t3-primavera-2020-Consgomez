#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;


class MultiEnteros{
    public:
    string strA, strB, mayor;

    long multiplicacion(int a, int b, int n){
        if((a<100)&&(b<100)){
            return a*b;
        } else{
            long s = n/2;
            long pot = pow(10, s);
            long a1 = a/pot;
            long a2 = a%pot;
            long b1 = b/pot;
            long b2 = b%pot;
            long w = multiplicacion(a1, b1, s);
            long x = multiplicacion(a1, b2, s);
            long y = multiplicacion(a2, b1, s);
            long z = multiplicacion(a2, b2, s);
            long aux = x+y;
            w = w * pow(10, 2*s);
            aux = aux * pow(10, s);
            long resultado = w + aux;
            resultado = resultado + z;
            return resultado;
        }
        return 0;
    }

    int tam(int a, int b){
        int size = 0;
        strA = to_string(a);
        strB = to_string(b);
        mayor = encontrar(strA, strB);
        mayor = resize(mayor);
        size = pow(2, mayor.size()/2);
        return size;
    }

    string resize(string mayor){
        string temp = "0";
        while(mayor.size()%2!=0){
            mayor.insert(0, temp);
        }
        return mayor;
    }

    string encontrar(string strA, string strB){
        if((strA.size()>strB.size()) || (strA.size()==strB.size())){
            return strA;
        } else if(strB.size()>strA.size()){
            return strB;
        }
        return ".";
    }

};

int main(){
    int a = 5200585;
    int b = 154321;
    long resultado;
    int n;
    MultiEnteros m;
    n = m.tam(a,b);
    resultado = m.multiplicacion(a, b, n);
    cout<<resultado<<endl;

    return 0;
}