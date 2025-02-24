Algoritmo votosCandidatos
	Definir i, j, votos Como Entero
	Definir nombres Como Cadena
	Definir totalVotos Como Entero
	Definir maxVotos Como Entero
	Definir minVotos Como Entero
	Definir ganador Como Entero
	Definir perdedor Como Entero
	Dimensionar nombres(5)
	Dimensionar datos(6,5)
	Para i<-1 Hasta 5 Hacer
		datos[6,i]<-0
	FinPara
	Para i<-1 Hasta 5 Hacer
		Escribir 'Ingrese nombre del candidato ', i, ': '
		Leer nombres[i]
	FinPara
	Para i<-1 Hasta 5 Hacer
		Para j<-1 Hasta 5 Hacer
			Escribir 'Ingrese votos de la ronda ', i, ' para el candidato ', nombres[j], ': '
			Leer votos
			datos[i,j]<-votos
			datos[6,j]<-datos[6,j]+votos
		FinPara
	FinPara
	Limpiar Pantalla
	Escribir 'Candidatos y sus votos en cada ronda:'
	Escribir '        'Sin Saltar
	Para i<-1 Hasta 5 Hacer
		Escribir nombres[i], '    'Sin Saltar
	FinPara
	Escribir ''
	Para i<-1 Hasta 5 Hacer
		Escribir 'Ronda ', i, '  'Sin Saltar
		Para j<-1 Hasta 5 Hacer
			Escribir datos[i,j], '        'Sin Saltar
		FinPara
		Escribir ''
	FinPara
	Escribir 'Total:    'Sin Saltar
	Para i<-1 Hasta 5 Hacer
		Escribir datos[6,i], '       'Sin Saltar
	FinPara
	Escribir ''
	maxVotos <- datos[6,1]
	minVotos <- datos[6,1]
	ganador <- 1
	perdedor <- 1
	Para i<-2 Hasta 5 Hacer
		Si datos[6,i]>maxVotos Entonces
			maxVotos <- datos[6,i]
			ganador <- i
		FinSi
		Si datos[6,i]<minVotos Entonces
			minVotos <- datos[6,i]
			perdedor <- i
		FinSi
	FinPara
	Escribir 'El candidato que ganó las elecciones es: ', nombres[ganador], ' con ', maxVotos, ' votos.'
	Escribir 'El candidato que menos votos tuvo es: ', nombres[perdedor], ' con ', minVotos, ' votos.'
FinAlgoritmo
