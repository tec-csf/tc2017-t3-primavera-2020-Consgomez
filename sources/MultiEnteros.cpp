#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;


class MultiEnteros{
    public:
    int n, s;
    int w, x, y, z;
    int pot;
    double r, p, q;

    int multiplicacion(int a, int b){
        tamaño(a, b);
        cout<<n<<endl;
        if(n<=2){
            return a*b;
        } else{
            s = n/2;
            pot = pow(10, s);
            w = a/pot;
            x = a%pot;
            y = b/pot;
            z = b%pot;
            r = multiplicacion(w+x, y+z);
            //cout<<r<<endl;
            //p = multiAux(w, y);
            //q = multiAux(x, z);
            //return ((p*pow(10, 2*s)) + ((r-p-q)*pow(10, s)) + q);
        }
        return 0;
    }

    void tamaño(int a, int b){
        string strA = to_string(a);
        string strB = to_string(b);
        if(strA.size()>strB.size()){
            n = strA.size();
        } else if(strB.size()>strA.size()){
            n = strB.size();
        }
    }
};

int main(){
    int a = 1234;
    int b = 981;
    int resultado;
    MultiEnteros m;
    resultado = m.multiplicacion(a, b);
    cout<<resultado<<endl;

    return 0;
}