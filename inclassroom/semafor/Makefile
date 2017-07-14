.PHONY : all clear

all : server client

server : server.o semaphor.o
	gcc -o $@ $^ -lstdc++

client : client.o semaphor.o
	gcc -o $@ $^ -lstdc++


server.o : server.cpp semaphor.h
	gcc -c $<

semaphor.o : semaphor.cpp semaphor.h
	gcc -c $<
	

client.o : client.cpp semaphor.h
	gcc -c $<	
	
	
clear :
	rm  -f server client  *.o  *~
 
