proyectil.png : Ejercicio28.py proyectil.dat 
	python Ejercicio28.py

proyectil.dat : Ejercicio28.x
	./Ejercicio28.x 

Ejercicio28.x : Ejercicio28.cpp
	c++ Ejercicio28.cpp -o Ejercicio28.x
	
clean : 
	rm Ejercicio28.x proyectil.dat proyectil.png
