files = main.c createMaze.h createMaze.c mouse.h mouse.c maze.h maze.c stack.h stack.c node.h node.c

compile:
	clear
	gcc -Wall $(files) -lm

all: compile
	./a.out < inp.txt

debug:
	clear
	gcc -g $(files) -lm

