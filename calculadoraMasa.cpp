#include <iostream>
#include <cstdlib>
//febrero 2025 hersongiron
using namespace std;

int main()
{
    float pesoLibras=0;
    float pesoKilogramos=0;
    float alturaMetros=0;
    float alturaPulgadas=0;
    int opcionSeleccionada;
    float resultadoCalculadora;
    char salidaMenu;

    do
    {
        system("cls");
        opcionSeleccionada=0;
        resultadoCalculadora=0;
        cout << "Bienvenido/a a la calculadora de masa corporal (IMC)" << endl;
        cout << "ingrese la opción que desee: " << endl;
        cout << "1. Ingresar peso en kilogramos" << endl;
        cout << "2. Ingresar peso eso en libras" << endl;
        cout << "   Opcion: "<<endl;
        cin >> opcionSeleccionada;

        if (opcionSeleccionada==1)
        {
            cout << "Ingrese su peso en kilogramos"<<endl;
            cin >> pesoKilogramos;
            cout << "Ingrese altura en metros" << endl;
            cin >> alturaMetros;
        } else if (opcionSeleccionada==2)
        {
            cout<< "Ingrese su peso en libras"<<endl;
            cin >> pesoLibras;
            cout << "Ingrese su altura en pulgadas"<<endl;
            cin>> alturaPulgadas;
        }
        switch  (opcionSeleccionada)
        {
            case 1:
                resultadoCalculadora = pesoKilogramos/(alturaMetros*alturaMetros);
                break;
            case 2:
                resultadoCalculadora = (pesoLibras*703)/(alturaPulgadas*alturaPulgadas);
                break;
            default:
                cout << "Error en la opción seleccionada" << endl;
        }

        if (resultadoCalculadora<18.5)
        {
            cout<<"Tiene un bajo peso "<<resultadoCalculadora<<" de IMC"<<endl;
        }else
        if (resultadoCalculadora<25 && resultadoCalculadora>18.4)
        {
            cout<<"Tiene un peso normal "<<resultadoCalculadora<<" de IMC"<<endl;
        }else
        if (resultadoCalculadora<30 && resultadoCalculadora>24)
        {
            cout<<"Tiene sobrepeso "<<resultadoCalculadora<<" de IMC" <<endl;
        }else if (resultadoCalculadora>29)
        {
            cout<<"Tiene obesidad "<<resultadoCalculadora<<" de IMC"<<endl;
        }
        cout << "Desea realizar otra operacion Si=S o No=N" << endl;
        cin >> salidaMenu;
    } while (salidaMenu == 's' || salidaMenu == 'S');
    return 0;
}
