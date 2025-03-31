//realizado por: Herson Giron
#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
int n;
int repetir;
    do{
    n=rand()%2+1;
    cout<<"Variable con numeros aleatorios entre 1 y 2: "<<n<<endl;
    n=rand()%100+1;
    cout<<"Variable con numeros aleatorios entre 1 y 100: "<<n<<endl;
    n=rand()%9+0;
    cout<<"Variable con numeros aleatorios entre 0 y 9: "<<n<<endl;
    n=rand()%1112+1000;
    cout<<"Variable con numeros aleatorios entre 1000 y 1112: "<<n<<endl;
    n=rand()%1+-1;
    cout<<"Variable con numeros aleatorios entre -1 y 1: "<<n<<endl;
    n=rand()%11+-3;
    cout<<"Variable con numeros aleatorios entre -3 y 11: "<<n<<endl;

     cout<<"¿Desea repetir? "<<endl;
     cin>>repetir;
    }while (repetir!=0);
    return 0;
}
