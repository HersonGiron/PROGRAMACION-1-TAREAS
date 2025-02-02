Algoritmo calculadora_de_edad
	Definir anioActual Como Entero
	Definir anioNacimiento Como Entero
	Definir mesNacimiento Como Entero
	Definir anioMes Como Entero
	Escribir 'Bienvenido al programa que permite calcular la edad del usuario'
	Escribir 'Ingrese el año en el que nacio'
	Leer anioNacimiento
	Escribir 'Ingrese el mes en el que nacio, (Ingreselo como numero de mes 1-12)'
	Leer mesNacimiento
	anioActual <- 2025-anioNacimiento
	anioMes <- (anioActual*12)
	Escribir 'El usuario tiene ', trunc((anioMes-mesNacimiento)/12), ' años de edad '
FinAlgoritmo
