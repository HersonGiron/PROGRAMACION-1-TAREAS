//inclusion de bibliotecas
#include <iostream>
#include <unistd.h>
#include "Config.h"
using namespace std;

Config::Config(int filasTablero, int columnasTablero, int minasTablero, bool modoDesarrolladorTablero, int vidasTablero) //Inicializa el constructor sobrecargado
{
    this->filasTablero = filasTablero;
    this->columnasTablero = columnasTablero;
    this->minasTablero = minasTablero;
    this->modoDesarrolladorTablero = modoDesarrolladorTablero;
    this->vidasTablero = vidasTablero;
}
//Crea un constructor para la lista de configuración
void Config::menuConfiguracion()
{
    int opciones;
    int valorIngresado;
    bool repetir = true;
    do
    {
        system("cls");
        cout << "\n\n\t\tCONFIGURACION ACTUAL -Menu-" << endl;
        cout << "\t\t-------------------"<< endl;
        cout << "\t\t1. Filas del Tablero ----> " << this->getfilasTablero() << endl;
        cout << "\t\t2. Columnas del Tablero -> " << this->getcolumnasTablero() << endl;
        cout << "\t\t3. Minas del Tablero ----> " << this->getminasTablero() << endl;
        cout << "\t\t4. Modo del Juego -------> " << this->getmodoDesarrolladorTablero() << endl;
        cout << "\t\t5. Vidas del Jugador ----> " << this->getvidasTablero() << endl;
        cout << "\t\t6. Regresar al menu general" << endl;
        cout << "\n\t\tIngrese una opcion: ";
        cin >> opciones;
        if (opciones!=6) //Condición para salir o seguir en la configuración
        {
            cout << "\n\tIngrese el valor que desea cambiar: ";
            cin >> valorIngresado;
        }
        switch (opciones) //Muestra las distintass configuraciones a petición del usuario
        {
        case 1:
            {
                this->setfilasTablero(valorIngresado);
                cout << "Filas del Tablero actualizadas" << endl;
                break;
            }
        case 2:
            {
                this->setcolumnasTablero(valorIngresado);
                cout << "Columnas del Tablero actualizadas" << endl;
                break;
            }
        case 3:
            {
                this->setminasTablero(valorIngresado);
                cout << "Minas del Tablero actualizadas" << endl;
                break;
            }
        case 4:
            {
                this->setmodoDesarrolladorTablero(valorIngresado);
                cout << "Modo del Juego actualizado" << endl;
                break;
            }
        case 5:
            {
                this->setvidasTablero(valorIngresado);
                cout << "Vidas del Juego actualizadas" << endl;
                break;
            }
        case 6: repetir = false;
                break;
        }system("pause");
        }
         while (repetir);
}
//Metodo para obtener el numero de filas del tablero
int Config::getfilasTablero()
{
    return this->filasTablero;  //Devuelve el valor de filasTablero
}
//Metodo para establecer el numero de filas del tablero
int Config::setfilasTablero(int filasTablero)
{
    this->filasTablero=filasTablero; //Asigna el valor recibido al atributo filasTablero
}
//Metodo para la obtener el numero de columnas del tablero
int Config::getcolumnasTablero()
{
    return this->columnasTablero; //Devuelve el valor de columnasTablero
}
//Metodo para establecer el numero de columnas del tablero
int Config::setcolumnasTablero(int columnasTablero)
{
    this->columnasTablero=columnasTablero; //Asigna el valor recibido al atributo columnasTablero
}
//Metodo para obtener el numero de minas del tablero
int Config::getminasTablero()
{
    return this->minasTablero; // Devuelve el valor de minasTablero
}
//Metodo para establecer el numero de minas en el tablero
int Config::setminasTablero(int minasTablero)
{
    this->minasTablero=minasTablero; //Asigna el valor recibido del atributo minasTablero
}
//Metodo para obtener el modo desarrollador del tablero
bool Config::getmodoDesarrolladorTablero()
{
    return this->modoDesarrolladorTablero; //Devuelve el valor de modoDesarrolladorTablero
}
//Metodo para establecer el modo desarrollador del tablero
bool Config::setmodoDesarrolladorTablero(bool modoDesarrolladorTablero)
{
    this->modoDesarrolladorTablero=modoDesarrolladorTablero; //Asigna el valor recibido del atributo modoDesarrolladorTablero
}
//Metodo para obtener el numero de vidas del tablero
int Config::getvidasTablero()
{
    return this->vidasTablero; //Devuelve el valor de vidasTablero
}//Metodo para establecer el numero de vidas del tablero
int Config::setvidasTablero(int vidasTablero)
{
    this->vidasTablero=vidasTablero; //Asigna el valor recibido del atributo vidasTablero
}
