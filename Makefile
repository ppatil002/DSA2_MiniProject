final : main.o stmr.o demo.o
	gcc -o final main.o stmr.o demo.o

main.o : main.c 
	gcc -c main.c 

stmr.o : stmr.c stmr.h 
	gcc -c stmr.c

demo.o : demo.c demo.h
	gcc -c demo.c








