prog1:fun.o prog1.o Makefile
			gcc -o prog1 prog1.o fun.o
prog1.o: prog1.c fun.h Makefile
			gcc -c prog1.c
prog: fun.o prog.o Makefile
			gcc -o prog fun.o prog.o
fun.o: fun.c fun.h Makefile
			gcc -c fun.c
prog.o:prog.c fun.h Makefile
			gcc -c prog.c



