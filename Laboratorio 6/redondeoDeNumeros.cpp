//realizado por Herson Giron
#include <cmath>
#include <iostream>
using namespace std;
float numero;
float redondearEntero (float numero){
    float entero;
    entero= floor(numero*1+0.5)/1;
    return entero;
}
float redondearDecimas (float numero){
    float decimas;
    decimas= floor(numero*1+0.5)/10;
    return decimas;
}
float redondearCentesimas (float numero){
    float centesimas;
    centesimas= floor(numero*1+0.5)/100;
    return centesimas;
}
float redondearMilesimas (float numero){
    float milesimas;
    milesimas= floor(numero*1+0.5)/1000;
    return milesimas;
}

int main (){
    cout<<"Ingrese el numero que desee redondear"<<endl;
    cin>> numero;
    cout<<"el numero " << numero << " ha sido redondeado a entero "<<redondearEntero(numero)<<endl;
    cout<<"el numero " << numero << " ha sido redondeado a decimas "<<redondearDecimas(numero)<<endl;
    cout<<"el numero " << numero << " ha sido redondeado a centesimas "<<redondearCentesimas(numero)<<endl;
    cout<<"el numero " << numero << " ha sido redondeado a milesimas "<<redondearMilesimas(numero)<<endl;
}

