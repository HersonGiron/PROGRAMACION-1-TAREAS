Algoritmo Misil
	Escribir 'Presione una tecla para iniciar el lanzamiento!'
	Esperar Tecla
	// el arreglo cohete tiene el dibujo del cohete como lineas de texto
	Dimensionar cohete(9)
	cohete[1] <- '   /|\   '
	cohete[2] <- '   |B|   '
	cohete[3] <- '   |O|   '
	cohete[4] <- '   |M|   '
	cohete[5] <- '   |B|   '
	cohete[6] <- '  //|\\  '
	cohete[7] <- ' ******* '
	cohete[8] <- '* * * * *'
	cohete[9] <- ' * * * * '
	// primero se muestra la primer parte del dibujo y la cuenta regresiva
	Para i<-1 Hasta 11 Hacer
		Limpiar Pantalla
		Para j<-1 Hasta 15 Hacer
			Escribir ''
		FinPara
		Para j<-1 Hasta 6 Hacer
			Escribir cohete[j]
		FinPara
		Escribir ''
		Escribir 'Lanzamiento en ', 11-i
		Esperar 1 Segundos
	FinPara
	// despues se muestra el dibujo completo y cada vez mas arriba
	Para i<-1 Hasta 15 Hacer
		Limpiar Pantalla
		Para j<-i Hasta 15 Hacer
			Escribir ''
		FinPara
		Para j<-1 Hasta 8 Hacer
			Escribir cohete[j]
		FinPara
		Si i>1 Entonces
			Escribir ' * * * * '
		FinSi
		Esperar 1/i Segundos
	FinPara
	// finalmente se va modificando el dibujo para hacer la explosion
	// estado tiene un entero que dice en que parte de la explosion va cada linea del dibujo
	Dimensionar Estado(6)
	Estado[1] <- 3
	Estado[2] <- 2
	Estado[3] <- 1
	Estado[4] <- 2
	Estado[5] <- 3
	Estado[6] <- 4
	Para i<-1 Hasta 10 Hacer
		Limpiar Pantalla
		Para j<-1 Hasta 6 Hacer
			Estado[j] <- Estado[j]-1
			Según Estado[j] Hacer
				0:
					cohete[j] <- '    +    '
				-1, -5:
					cohete[j] <- '   +X+   '
				-2, -4:
					cohete[j] <- '  +XXX+  '
				-3:
					cohete[j] <- ' +XXXXX+ '
				-6:
					cohete[j] <- '         '
			FinSegún
			Escribir cohete[j]
		FinPara
		Esperar .2 Segundos
	FinPara
FinAlgoritmo
