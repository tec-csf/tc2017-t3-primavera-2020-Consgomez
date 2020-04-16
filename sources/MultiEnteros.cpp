#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;


class MultiEnteros{
    public:
    int n, s;
    int a1, a2, b1, b2;
    int pot;
    int w, x, y, z;
    int aux;
    int resultado;
    string strA, strB;

    int multiplicacion(int a, int b){
        strA = to_string(a);
        strB = to_string(b);
        strA = resize(strA);
        strB = resize(strB);
        n = strA.size();
        if(pequeño(strA, strB) == true){
            return a*b;
        } else{
            s = n/2;
            pot = pow(10, s);
            a1 = a/pot;
            a2 = a%pot;
            b1 = b/pot;
            b2 = b%pot;
            w = multiplicacion(a1, b1);
            x = multiplicacion(a1, b2);
            y = multiplicacion(a2, b1);
            z = multiplicacion(a2, b2);
            aux = x+y;
            w = w * pow(10, 2*s);
            aux = aux * pow(10, s);
            resultado = w + aux;
            resultado = resultado + z;
            return resultado;
        }
        return 0;
    }

    string resize(string mayor){
        string temp = "0";
        while(mayor.size()%2!=0){
            mayor.insert(0, temp);
        }
        return mayor;
    }

    bool pequeño(string a, string b){
        if((a.size()<=2)&&(b.size()<=2)){
            return true;
        }else
            return false;
        return false;
    }
};

int main(){
    int a = 9999;
    int b = 9999;
    int resultado;
    MultiEnteros m;
    resultado = m.multiplicacion(a, b);
    cout<<resultado<<endl;

    return 0;
}