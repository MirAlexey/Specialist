.PHONY: all clean dependencies

SOURCES = main.c 

HEADERS =

OBJECTS = $(patsubst %.c,%.o,$(SOURCES))

CFLAGS = -I../hello

LIBS = -L../hello -lhello

all : hello

hello : $(OBJECTS)
	gcc -o $@ $^ $(LIBS)

%.o : %.c
	gcc -c $(CFLAGS) $<

clean :
	rm -f *.o hello *~ dependencies

dependencies : $(SOURCES) $(HEADERS)
	gcc -MM $(CFLAGS) $(SOURCES) >$@

include dependencies
