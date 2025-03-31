//Realizado por: Herson Giron, 2025
#include <iostream>
#include <iomanip>
using namespace std;

double calcularCargos(double horasDeEstacionamiento) {
    double cargo;

    if (horasDeEstacionamiento <= 3){
        cargo = 2;
    }
    else if (horasDeEstacionamiento>=24){
        cargo = 10;
    }else{
        cargo = 2 + (horasDeEstacionamiento-3) * 0.50;
    }
    return cargo;
}

int main() {
    double horaUno, horasDos,horasTres, cargoUno, cargoDos, cargoTres;
    double total = 0;
    double totalHoras=0;

    cout << "Ingresa la cantidad de horas que se estaciono el primer cliente: "<<endl;
    cin >> horaUno;
    cout << "Ingresa la cantidad de horas que se estaciono el segundo cliente: "<<endl;
    cin >> horasDos;
    cout << "Ingresa la cantidad de horas que se estaciono el tercer cliente: "<<endl;
    cin >> horasTres;

    cargoUno = calcularCargos(horaUno);
    cargoDos = calcularCargos(horasDos);
    cargoTres = calcularCargos(horasTres);

    total = cargoUno + cargoDos + cargoTres;
    totalHoras=horaUno+horasDos+horasTres;
    cout<< fixed << setprecision(2);
    cout<< "Automovil       Horas     Cargo"<<endl;
    cout<< "Cliente 1       " << horaUno << "      $" << cargoUno << endl;
    cout<< "Cliente 2       " << horasDos << "      $" << cargoDos << endl;
    cout<< "Cliente 3       " << horasTres << "     $" << cargoTres << endl;
    cout<< "Total           " << totalHoras  << "     $" << total<<endl;
    return 0;
}
