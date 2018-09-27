bp:	bp.o func.o 
	g++	 bp.o imp.o -Wall

bp.o: bp.cpp
	g++  -c bp.cpp -std=c++11 -Wall

func.o: func.cpp 
	g++	-c func.cpp -std=c++11 -Wall

fun.o: fun.h 
	g++ -c fun.h -std=c++11 -Wall

clean:
	rm *.o