.PHONY : all clear

all : server

server : server.o semaphor.o
	gcc -o $@ $^ -lstdc++

server.o : server.cpp semaphor.h
	gcc -c $<

semaphor.o : semaphor.cpp semaphor.h
	gcc -c $<

clear :
	rm  -f server  *.o  *~
 
