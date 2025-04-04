#include "Juego.h"
#include <fstream>
#include <unistd.h>

int Juego::aleatorio_en_rango(int minimo, int maximo)
{
	return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

int Juego::filaAleatoria()
{
	return this->aleatorio_en_rango(0, this->tablero.getAlturaTablero() - 1);
}

int Juego::columnaAleatoria()
{
	return this->aleatorio_en_rango(0, this->tablero.getAnchoTablero() - 1);
}

Juego::Juego(Tablero tablero, int cantidadMinas)
{
	this->tablero = tablero;
	this->cantidadMinas = cantidadMinas;
	this->score = 0;
	this->colocarMinasAleatoriamente();
}

void Juego::colocarMinasAleatoriamente()
{
	int x, y, minasColocadas = 0;

	while (minasColocadas < this->cantidadMinas)
	{
		x = this->columnaAleatoria();
		y = this->filaAleatoria();
		if (this->tablero.colocarMina(x, y))
		{
			minasColocadas++;
		}
	}
}

int Juego::solicitarFilaUsuario()
{
	int fila = 0;
	cout << "Ingresa la FILA en la que desea jugar: ";
	cin >> fila;
	return fila - 1;
}

int Juego::solicitarColumnaUsuario()
{
	int columna = 0;
	cout << "Ingresa la COLUMNA en la que desea jugar: ";
	cin >> columna;
	return columna - 1;
}

bool Juego::jugadorGana()
{
	int conteo = this->tablero.contarCeldasSinMinasYSinDescubrir();
	return conteo == 0;
}

void Juego::iniciar()
{
	int fila, columna;
	while (this->vidasTablero > 0)
	{
		this->tablero.imprimir();
		cout << "Puntaje actual: " << this->score << "\n";

		fila = this->solicitarFilaUsuario();
		columna = this->solicitarColumnaUsuario();

		bool respuestaAUsuario = this->tablero.descubrirMina(columna, fila);
		if (!respuestaAUsuario)
		{
			this->vidasTablero--;
			cout << "Te quedan " << this->vidasTablero << " vidas\n";

			if (this->vidasTablero == 0)
			{
				cout << "Perdiste el Juego\n";
				cout << "Tu puntaje final fue: " << this->score << "\n";
				this->tablero.setModoDesarrollador(true);
				this->tablero.imprimir();
				break;
			}
		}
		else
		{
			this->score += 1;
		}

		if (this->jugadorGana())
		{
			cout << "Ganaste el Juego\n";
			cout << "Tu puntaje final fue de: " << this->score << "\n";
			this->tablero.setModoDesarrollador(true);
			this->tablero.imprimir();
			break;
		}
	}
}

