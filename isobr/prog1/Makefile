prog: fun1.o prog1.o  Makefile
			gcc -o prog fun1.o prog1.o
fun1.o: fun1.c fun1.h Makefile
			gcc -c fun1.c
prog1.o: prog1.c fun1.h Makefile
			gcc -c prog1.c
prog2: fun2.o prog2.o Makefile
			gcc -o prog2 fun2.o prog2.o
fun2.o: fun2.c fun1.h Makefile
			gcc -c fun2.c
prog2.o: prog2.c fun1.h Makefile
			gcc -c prog2.c
