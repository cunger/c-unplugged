CC = gcc
CFLAGS = -Wall -g

build:
	gcc -Wall -g database.c main.c -o run

test:
	./run aquarium c 
	./run aquarium s 0 goldfish
	./run aquarium s 1 triggerfish
	./run aquarium l
	./run aquarium g 0
	./run aquarium f triggerfish 
	./run aquarium d 0 
	./run aquarium l

clean:
	rm -f run aquarium
