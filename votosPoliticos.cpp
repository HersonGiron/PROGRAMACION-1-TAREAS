#include <iostream>
#include <string>
using namespace std;

// Herson y Xander

int main() {
    string nombres[5];
    int datos[6][5] = {0};
    int votos, maxVotos, minVotos, ganador, perdedor;

    // en este apartado colocamos que ingresaran los nombres de los candidatos y se guardaran en la matriz
    for (int i = 0; i < 5; i++) {
        cout << "Ingrese nombre del candidato " << i + 1 << ": ";
        cin >> nombres[i];
    }

    // en este apartado nos permite ingresar los votos en las 5 rondas para cada candidato
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << "Ingrese votos de la ronda " << i + 1 << " para el candidato " << nombres[j] << ": ";
            cin >> votos;
            datos[i][j] = votos;
            datos[5][j] += votos;
        }
    }

    // aqui solamente nos permite mostrar la tabla con los datos
    cout << "\nCandidatos y sus votos en cada ronda:" << endl;
    cout << "        ";
    for (int i = 0; i < 5; i++) {
        cout << nombres[i] << "    ";
    }
    cout << endl;

    for (int i = 0; i < 5; i++) {
        cout << "Ronda " << i + 1 << "  ";
        for (int j = 0; j < 5; j++) {
            cout << datos[i][j] << "        ";
        }
        cout << endl;
    }

    cout << "Total:    ";
    for (int i = 0; i < 5; i++) {
        cout << datos[5][i] << "       ";
    }
    cout << endl;

    //Aqui lo que realizamos con Xander fue determinar el ganador y el perdedor
    maxVotos = datos[5][0];
    minVotos = datos[5][0];
    ganador = 0;
    perdedor = 0;

    for (int i = 1; i < 5; i++) {
        if (datos[5][i] > maxVotos) {
            maxVotos = datos[5][i];
            ganador = i;
        }
        if (datos[5][i] < minVotos) {
            minVotos = datos[5][i];
            perdedor = i;
        }
    }

    cout << "\nEl candidato que ganó las elecciones es: " << nombres[ganador] << " con " << maxVotos << " votos." << endl;
    cout << "El candidato que menos votos tuvo es: " << nombres[perdedor] << " con " << minVotos << " votos." << endl;

    return 0;
}
