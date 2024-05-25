prog: fun2.o prog.o Makefile
		gcc -o prog fun2.o prog.o
fun.o: fun2.c fun.h Makefile
		gcc -c fun2.c
prog.o:prog.c fun.h Makefile
		gcc -c prog.c



