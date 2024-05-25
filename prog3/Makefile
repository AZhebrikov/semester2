prog: fun.o prog.o Makefile
		gcc -o prog fun.o prog.o
fun.o: fun.c fun.h Makefile
		gcc -c fun.c
prog.o:prog.c fun.h Makefile
		gcc -c prog.c 

