all : rotate-matrix

rotate-matrix : rotate.o read-matrix.o
	gcc -o rotate-matrix rotate.o read-matrix.o 

rotate.o : rotate.c
	gcc -c rotate.c

