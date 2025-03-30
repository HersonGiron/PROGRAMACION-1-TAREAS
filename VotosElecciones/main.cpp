#include "Votos.h"
#include <iostream>


using namespace std;

int main()
{
    Votos eleccionesCandidatos;
    eleccionesCandidatos.ingresarCandidatos();
    eleccionesCandidatos.ingresarVotos();
    eleccionesCandidatos.mostrarResultados();
    eleccionesCandidatos.determinarGanador();
}
