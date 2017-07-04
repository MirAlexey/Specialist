.PHONY: all clean dependencies

SOURCES = main.c \
	  goodbye.c \
	  hello.c

HEADERS = hello.h

all : hello

hello : main.o hello.o goodbye.o
	gcc -o $@ $^

%.o : %.c
	gcc -c $<

clean :
	rm -f *.o hello *~ dependencies

dependencies : $(SOURCES) $(HEADERS)
	gcc -MM $(SOURCES) >$@

include dependencies
