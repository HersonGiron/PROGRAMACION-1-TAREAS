#include "Calculadora.h"

using namespace std;

int main() {
    int operacion;
    float num1, num2, resultadoNumeros;

    do {
        cout << "CALCULADORA DE OPERACIONES BASICA" <<endl;
        cout << "Coloque el numero 1 se desea realizar una suma" <<endl;
        cout << "Coloque el numero 2 se desea realizar una resta" <<endl;
        cout << "Coloque el numero 3 se desea realizar una multiplicacion" <<endl;
        cout << "Coloque el numero 4 se desea realizar una division" <<endl;
        cout << "Seleccione la operacion basica que desee realizar: ";
        cin >> operacion;

        if (operacion >= 1 && operacion <= 4) {
            cout << "Ingrese el primer número que desee operar: ";
            cin >> num1;
            cout << "Ingrese el segundo número que desee operar: ";
            cin >> num2;
        }

        switch (operacion) {
            case 1:
                resultadoNumeros = Calculadora::sumar(num1, num2);
                cout << "El resultado de la suma entre dos cantidades es: " << resultadoNumeros << endl;
                break;
            case 2:
                resultadoNumeros = Calculadora::restar(num1, num2);
                cout << "El resultado de la resta entre dos cantidades es: " << resultadoNumeros << endl;
                break;
            case 3:
                resultadoNumeros = Calculadora::multiplicar(num1, num2);
                cout << "El resultado de la multiplicación entre dos cantidades es: " << resultadoNumeros << endl;
                break;
            case 4:
                resultadoNumeros = Calculadora::dividir(num1, num2);
                cout << "El resultado de la división entre dos cantidades es: " << resultadoNumeros << endl;
                break;
            default:
                cout << "Esta opcion no existe, coloque una opcion correcta." << endl;
        }
    } while (operacion != 5);

    return 0;
}
