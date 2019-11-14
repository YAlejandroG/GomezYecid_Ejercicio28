friccion.png : Ejercicio28.py proyectil.dat proyectilSF.dat
	python Ejercicio28.py

proyectil.dat proyectilSF.dat : Ejercicio28.x
	./Ejercicio28.x 

Ejercicio28.x : Ejercicio28.cpp
	c++ Ejercicio28.cpp -o Ejercicio28.x
	
clean : 
	rm Ejercicio28.x proyectil.dat proyectilSF.dat friccion.png 
