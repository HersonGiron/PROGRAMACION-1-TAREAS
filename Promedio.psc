// Calcula el promedio de una lista de N datos
Algoritmo Promedio
	Definir dato Como Real
	Definir prom Como Real
	Definir acum Como Real
	Escribir 'Ingrese la cantidad de datos:'
	Leer n
	acum <- 0
	Para i<-1 Hasta n Hacer
		Escribir 'Ingrese el dato ', i, ':'
		Leer dato
		acum <- acum+dato
	FinPara
	prom <- acum/n
	Escribir 'El promedio es: ', prom
FinAlgoritmo
