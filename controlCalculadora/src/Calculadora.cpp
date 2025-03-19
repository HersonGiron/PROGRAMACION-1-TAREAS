#include "Calculadora.h"

using namespace std;

float Calculadora::sumar(float num1, float num2) {
    return num1 + num2;
}

float Calculadora::restar(float num1, float num2) {
    return num1 - num2;
}

float Calculadora::multiplicar(float num1, float num2) {
    return num1 * num2;
}

float Calculadora::dividir(float num1, float num2) {
    if (num2 == 0) {
        cout << "Operacion erronea, no se puede dividir dentro de cero" << endl;
        return 0;
    }
    return num1 / num2;
}
