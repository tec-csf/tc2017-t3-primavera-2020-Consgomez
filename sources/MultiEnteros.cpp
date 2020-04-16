/*
    MultiEnteros.cpp
    Multiplica dos números enteros grandes, con la técnica de divide y vencerás
    Constanza Gómez Sánchez
    14 de abril de 2020
*/
#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

/*MultiEnteros: this class defines the methods to find the solution*/
class MultiEnteros{
    public:
    string strA, strB, mayor;

    /*multiplicacion: this method finds the product of the numbers we give the code in the main
    * @param integer a, integer b and int n which is the length of the numbers
    * @return the product
    */
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

    /*tam: this method finds the length of the number
    * @param integer a and integer b
    * @return size of the biggest number
    */
    int tam(int a, int b){
        int size = 0;
        strA = to_string(a);
        strB = to_string(b);
        mayor = encontrar(strA, strB);
        mayor = resize(mayor);
        size = pow(2, mayor.size()/2);
        return size;
    }

    /*resize: this method adds 0 to the left of the number if it's not a multiple of 2
    * @param string mayor
    * @return the arranged string
    */
    string resize(string mayor){
        string temp = "0";
        while(mayor.size()%2!=0){
            mayor.insert(0, temp);
        }
        return mayor;
    }

    /*encontrar: this method compares both numbers given to find the biggest one
    * @param string strA and string strB
    * @return the biggest string
    */
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