#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;


class MultiEnteros{
    public:
    int pot;
    int resultado;
    string strA, strB, mayor;

    int multiplicacion(int a, int b, int n){
        if((n!=2)||(n%4!=0)||(n!=4)){
            n+=2;
        }
        //cout<<n<<endl;
        if((a<100)&&(b<100)){
            return a*b;
        } else{
            int s = n/2;
            pot = pow(10, s);
            int a1 = a/pot;
            int a2 = a%pot;
            int b1 = b/pot;
            int b2 = b%pot;
            int w = multiplicacion(a1, b1, s);
            int x = multiplicacion(a1, b2, s);
            int y = multiplicacion(a2, b1, s);
            int z = multiplicacion(a2, b2, s);
            int aux = x+y;
            w = w * pow(10, 2*s);
            aux = aux * pow(10, s);
            int resultado = w + aux;
            resultado = resultado + z;
            return resultado;
        }
        return 0;
    }

    int tamaño(int a, int b){
        strA = to_string(a);
        strB = to_string(b);
        mayor = encontrar(strA, strB);
        mayor = resize(mayor);
        return mayor.size();
    }

    string resize(string mayor){
        string temp = "0";
        while(mayor.size()%2!=0){
            mayor.insert(0, temp);
        }
        return mayor;
    }

    string encontrar(string strA, string strB){
        if(strA.size()>strB.size()){
            return strA;
        } else if(strB.size()>strA.size()){
            return strB;
        }
        return ".";
    }

};

int main(){
    int a = 59699;
    int b = 1968;
    int resultado;
    MultiEnteros m;
    int n = m.tamaño(a,b);
    resultado = m.multiplicacion(a, b, n);
    cout<<resultado<<endl;

    return 0;
}