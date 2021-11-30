files = main.c createMaze.c createMaze.h maze.h maze.c

compile:
	clear
	gcc -Wall $(files) -lm

all: compile
	./a.out < inp.txt

debug:
	clear
	gcc -g $(files) -lm

