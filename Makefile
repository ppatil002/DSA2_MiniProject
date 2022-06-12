stem : main.o stmr.o wordnet.o options.o
	gcc -o stem main.o stmr.o wordnet.o options.o

main.o : main.c 
	gcc -c main.c 

stmr.o : stmr.c stmr.h
	gcc -c stmr.c

wordnet.o : wordnet.c wordnet.h
	gcc -c wordnet.c
 
option.o : options.c options.h
	gcc -c options.c

graph.o : graph.c
	gcc -c graph.c








