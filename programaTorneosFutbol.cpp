#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define CANTIDAD_DE_PARTIDOS 10
#define GOLES_MAXIMOS 10
#define GOLES_MINIMOS 0
#define NUMERO_EQUIPOS 6
#define PUNTOS_DE_LIGA 30
#define PUNTOS_DE_VICTORIA 3
#define PUNTOS_DE_EMPATE 1
#define PUNTOS_DE_DERROTA 0

void tablaDeLiga(int goles[NUMERO_EQUIPOS][CANTIDAD_DE_PARTIDOS], string nombres[NUMERO_EQUIPOS]);
void equipos(string nombres[NUMERO_EQUIPOS]);
void punteoDeLiga(int puntos[NUMERO_EQUIPOS], int goles[NUMERO_EQUIPOS][CANTIDAD_DE_PARTIDOS], string nombres[NUMERO_EQUIPOS]);
void gggpgegd(int goles[NUMERO_EQUIPOS][CANTIDAD_DE_PARTIDOS], int puntos[NUMERO_EQUIPOS], string nombres[NUMERO_EQUIPOS]);
void ganador(int puntos[NUMERO_EQUIPOS], string nombres[NUMERO_EQUIPOS], int goles[NUMERO_EQUIPOS][CANTIDAD_DE_PARTIDOS]);
int main()
{
  srand(time(0));
  string nombres[NUMERO_EQUIPOS];
  int goles[NUMERO_EQUIPOS][CANTIDAD_DE_PARTIDOS];
  int puntos[NUMERO_EQUIPOS];
  char siNo;
  do
    {
    cout<<"Primera vuelta de la liga"<<endl;
    equipos(nombres);
    tablaDeLiga(goles,nombres);
    punteoDeLiga(puntos, goles, nombres);
    gggpgegd(goles,puntos,nombres);
    ganador(puntos,nombres,goles);
    cout<<"Segunda vuelta de la liga"<<endl;
        tablaDeLiga(goles,nombres);
        punteoDeLiga(puntos, goles, nombres);
        gggpgegd(goles,puntos,nombres);
        ganador(puntos,nombres,goles);
    cout<<"Quieres volver a intentarlo? (s/n)"<<endl;
    cin>>siNo;
    siNo = tolower(siNo);
  } while (siNo=='s');
  cout<<"Graciah por usar el programa"<<endl;
  return 0;
}


  void equipos(string nombres[NUMERO_EQUIPOS])
  {
   for (int i=0;i<NUMERO_EQUIPOS;i++)
     {
       cout<<"Ingrese el nombre del equipo "<<i+1<<": "<<endl;
        getline(cin,nombres[i]);
     }
    cout<<"Los equipos seleccionados son: ";

      int contadorCantidadEquipos = 1;
      for (int i=0;i<NUMERO_EQUIPOS;i++) {
        cout<<contadorCantidadEquipos++<<" "<<nombres[i]<<endl; 
      }


  }
  void tablaDeLiga(int goles[NUMERO_EQUIPOS][CANTIDAD_DE_PARTIDOS], string nombres[NUMERO_EQUIPOS])
  {

    for (int i= 0; i<NUMERO_EQUIPOS;i++)
      {
        for (int j=0;j<CANTIDAD_DE_PARTIDOS;j++)
        { 
          goles[i][j] = GOLES_MINIMOS + rand() % (GOLES_MAXIMOS - GOLES_MINIMOS + 1);
          cout<<"El equipo "<<nombres[i]<<" en el partido "<<j+1<<" anoto "<<goles[i][j]<<endl;

        }              
      }
  }
  void punteoDeLiga(int puntos[NUMERO_EQUIPOS], int goles[NUMERO_EQUIPOS][CANTIDAD_DE_PARTIDOS], string nombres[NUMERO_EQUIPOS]) 
  {
      for (int i = 0; i < NUMERO_EQUIPOS; i++) 
      {
          puntos[i] = 0;
      }

      for (int j = 0; j < CANTIDAD_DE_PARTIDOS; j++) 
      {
          for (int i = 0; i < NUMERO_EQUIPOS; i += 2)
            { 

              if (i + 1 < NUMERO_EQUIPOS) 
              { 
                  if (goles[i][j] > goles[i + 1][j]) 
                  {
                      puntos[i] += PUNTOS_DE_VICTORIA; 
                  } else if (goles[i][j] < goles[i + 1][j])
                  {
                      puntos[i + 1] += PUNTOS_DE_VICTORIA; 
                  } else {
                      puntos[i] += PUNTOS_DE_EMPATE;  
                      puntos[i + 1] += PUNTOS_DE_EMPATE;
                  }
              }
          }
      }

      cout << "\nTabla de Puntos:\n";
      for (int i = 0; i < NUMERO_EQUIPOS; i++) {
          cout << nombres[i]<< ": " << puntos[i] << " puntos" << endl;
      }
  }
void gggpgegd(int goles[NUMERO_EQUIPOS][CANTIDAD_DE_PARTIDOS], int puntos[NUMERO_EQUIPOS], string nombres[NUMERO_EQUIPOS]) {
    int partidosGanados[NUMERO_EQUIPOS] = {0};  
    int partidosPerdidos[NUMERO_EQUIPOS] = {0}; 
    int partidosEmpatados[NUMERO_EQUIPOS] = {0}; 
    int golesDeDiferencia[NUMERO_EQUIPOS] = {0}; 

    // Primer for para partidos
    for (int j = 0; j < CANTIDAD_DE_PARTIDOS; j++) {
        // Segundo for para equipos
        for (int i = 0; i < NUMERO_EQUIPOS; i += 2) {
            if (i + 1 < NUMERO_EQUIPOS) {
                if (goles[i][j] > goles[i + 1][j]) {
                    partidosGanados[i]++;
                    partidosPerdidos[i + 1]++;
                } 
                else if (goles[i][j] < goles[i + 1][j]) {
                    partidosPerdidos[i]++;
                    partidosGanados[i + 1]++;
                } 
                else {
                    partidosEmpatados[i]++;
                    partidosEmpatados[i + 1]++;
                }
            }
        }
    }

    for (int i = 0; i < NUMERO_EQUIPOS; i++)
        {
        for (int j = 0; j < CANTIDAD_DE_PARTIDOS; j++)
            {
            golesDeDiferencia[i] += goles[i][j];
            if (i + 1 < NUMERO_EQUIPOS) {
                golesDeDiferencia[i] -= goles[i + 1][j];
            }
        }
    }

    for (int i = 0; i < NUMERO_EQUIPOS; i++)
        {
        cout << "Equipo " << nombres[i] << ": " << endl;
        cout << "Partidos ganados: " << partidosGanados[i] << endl;
        cout << "Partidos perdidos: " << partidosPerdidos[i] << endl;
        cout << "Partidos empatados: " << partidosEmpatados[i] << endl;
        cout << "Goles de diferencia: " << golesDeDiferencia[i] << endl;
    }

}
void ganador(int puntos[NUMERO_EQUIPOS], string nombres[NUMERO_EQUIPOS], int goles[NUMERO_EQUIPOS][CANTIDAD_DE_PARTIDOS])
{
    int maxPuntos = puntos[0];
    int indiceGanador = 0;

    for (int i = 1; i < NUMERO_EQUIPOS; i++)
      {
        if (puntos[i] > maxPuntos)
        {
            maxPuntos = puntos[i];
            indiceGanador = i;
        } else if (puntos[i] == maxPuntos)
        {
            int golesDeDiferenciaGanador = 0;
            for (int j = 0; j < CANTIDAD_DE_PARTIDOS; j++)
              {
                golesDeDiferenciaGanador += goles[indiceGanador][j];
                if (i < NUMERO_EQUIPOS - 1) {
                    golesDeDiferenciaGanador -= goles[i][j];
                }
            }
            int golesDeDiferenciaActual = 0;
            for (int j = 0; j < CANTIDAD_DE_PARTIDOS; j++)
              {
                golesDeDiferenciaActual += goles[i][j];
                if (indiceGanador < NUMERO_EQUIPOS - 1)
                {
                    golesDeDiferenciaActual -= goles[indiceGanador][j];
                }
            }
            if (golesDeDiferenciaActual > golesDeDiferenciaGanador)
            {
                indiceGanador = i;
            }
        }
    }

    cout << "El equipo ganador es " << nombres[indiceGanador] << " con " << puntos[indiceGanador] << " puntos." << endl;
}