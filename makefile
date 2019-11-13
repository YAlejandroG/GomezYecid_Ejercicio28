primergrado.png : Ejercicio27.py implicit1.dat implicit0.1.dat implicit0.01.dat explicit1.dat explicit0.1.dat explicit0.01.dat
	python Ejercicio27.py

implicit1.dat implicit0.1.dat implicit0.01.dat explicit1.dat explicit0.1.dat explicit0.01.dat : Ejercicio27.x
	./Ejercicio27.x 

Ejercicio27.x : Ejercicio27.cpp
	c++ Ejercicio27.cpp -o Ejercicio27.x
	
clean : 
	rm Ejercicio27.x implicit1.dat implicit0.1.dat implicit0.01.dat explicit1.dat explicit0.1.dat explicit0.01.dat primergrado.png
