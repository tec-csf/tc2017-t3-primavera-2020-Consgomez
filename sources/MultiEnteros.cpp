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
    //int i=0;
    int resultado;
    string strA;

    int multiplicacion(int a, int b){
        //i++;
        //cout<<i<<endl;
        strA = to_string(a);
        strA = resize(strA);
        n = strA.size();
        //cout<<"n: "<<n<<endl;
        if(n<=2){
            return a*b;
        } else if (n>2){
            s = n/2;
            pot = pow(10, s);
            w = a/pot;
            x = a%pot;
            y = b/pot;
            z = b%pot;
            r = multiplicacion(w+x, y+z);
            //cout<<"r: "<<r<<endl;
            p = multiplicacion(w, y);
            //cout<<"p: "<<p<<endl;
            q = multiplicacion(x, z);
            //cout<<"q: "<<q<<endl;
            return ((p*pow(10, 2*s)) + ((r-p-q)*pow(10, s)) + q);
        }
        return 0;
    }

    string resize(string mayor){
        string temp = "0";
        while(mayor.size()%2!=0){
            mayor.insert(0, temp);
            //cout<<mayor<<"."<<endl;
        }
        return mayor;
    }
};

int main(){
    int a = 8910;
    int b = 8911;
    int resultado;
    MultiEnteros m;
    resultado = m.multiplicacion(a, b);
    cout<<resultado<<endl;

    return 0;
}