//Directiva para evitar inclusiones múltiples del archivo
#ifndef CONFIG_H
#define CONFIG_H

//clase para manejar la configuración del juego.
class Config
{
    public:
        //Constructor de la clase Config
        Config(int filasTablero, int columnasTablero, int minasTablero, bool modoDesarrolladorTablero, int vidasTablero);
        // Métodos getter y setter para acceder y modificar los atributos privados
        int getfilasTablero();
        int setfilasTablero(int filasTablero);
        int getcolumnasTablero();
        int setcolumnasTablero(int columnasTablero);
        int getminasTablero();
        int setminasTablero(int minasTablero);
        bool getmodoDesarrolladorTablero();
        bool setmodoDesarrolladorTablero(bool modoDesarrolladorTablero);
        int getvidasTablero();
        int setvidasTablero(int vidasTablero);
        //Muestra un menú de configuración para modificar parámetros del tablero
        void menuConfiguracion();
    protected:

    private:
        //indica el numero de filas, columnas, minas, vidas del tablero y muestra si el modo desarrollador esta activado o desactivado
        int filasTablero;
        int columnasTablero;
        int minasTablero;
        bool modoDesarrolladorTablero;
        int vidasTablero;
};

//Finalización de la directiva
#endif // CONFIG_H
