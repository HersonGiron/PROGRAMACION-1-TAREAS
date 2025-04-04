#include "Juego.h"
#include <fstream>
#include <unistd.h>
//agregado por Xander reyes
#include <chrono>

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

Juego::Juego(Tablero tablero, int cantidadMinas,string nombreUsuario)
{
	this->tablero = tablero;
	this->cantidadMinas = cantidadMinas;
	this->score = 0;
	this->nombreUsuario = nombreUsuario;
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
    cout << "Persona que esta jugando: " << this->nombreUsuario << " ¡Buena suerte!\n";
	int fila, columna;
	auto inicio = std::chrono::high_resolution_clock::now(); // Se guarda el tiempo de inicio

	while (this->vidasTablero > 0)
	{
		this->tablero.imprimir();
		//realizado por Herson Giron
		cout << "Puntaje actual: " << this->score << "\n";

		fila = this->solicitarFilaUsuario();
		columna = this->solicitarColumnaUsuario();

		bool respuestaAUsuario = this->tablero.descubrirMina(columna, fila);
		if (!respuestaAUsuario)
		{
		    //realizado por: Xander Reyes
			this->vidasTablero--;
			cout << "Te quedan " << this->vidasTablero << " vidas\n";

			if (this->vidasTablero == 0)
			{
				cout << "Perdiste el Juego\n";
				//realizado por Herson Giron
				cout << "Tu puntaje final fue: " << this->score << "\n";
				this->tablero.setModoDesarrollador(true);
				this->tablero.imprimir();
                //realizado por: Xander Reyes
				// Calculamos el tiempo total jugado
				auto fin = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> duracion = fin - inicio;
				int totalSegundos = static_cast<int>(duracion.count());
				int minutos = totalSegundos / 60;
				int segundos = totalSegundos % 60;

				//realizado por Xander reyes
				cout << "Tiempo total jugado: " << minutos << " min " << segundos << " seg\n";
				break;
			}
		}
		else
		{
		    //realizado por Herson Giron
			this->score += 1;
		}

		if (this->jugadorGana())
		{
			cout << "Ganaste el Juego\n";
			//realizado por Herson Giron
			cout << "Tu puntaje final fue de: " << this->score << "\n";
			this->tablero.setModoDesarrollador(true);
			this->tablero.imprimir();

			//realizado por: Xander Reyes
			// Calculamos el tiempo total jugado
			auto fin = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> duracion = fin - inicio;
			int totalSegundos = static_cast<int>(duracion.count());
			int minutos = totalSegundos / 60;
			int segundos = totalSegundos % 60;
            //realizado por: Xander Reyes
			cout << "Tiempo total jugado: " << minutos << " min " << segundos << " seg\n";
			break;
		}
	}
}
