prog: fun.o prog.o Makefile
			gcc -o prog -O3 -fopenmp prog.o fun.o
fun.o: fun.c fun.h Makefile
			gcc -c -O3 -fopenmp fun.c
prog.o: prog.c fun.h Makefile
			gcc -c -O3 -fopenmp prog.c
