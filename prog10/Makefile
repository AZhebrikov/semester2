prog: prog.o fun.o Makefile
			gcc -o prog prog.o fun.o
prog.o: prog.c fun.h Makefile
			gcc -c prog.c
fun.o: fun.c fun.h Makefile
			gcc -c fun.c
