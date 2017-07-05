.PHONY: all clean dependencies

SOURCES = goodbye.c \
	  hello.c

HEADERS = hello.h

OBJECTS = $(patsubst %.c,%.o,$(SOURCES))

TARGET = libhello.so

CFLAGS = -fPIC

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	gcc -shared $(CFLAGS) -o $@ $^ 

%.o : %.c
	gcc $(CFLAGS) -c $<

clean :
	rm -f *.o   $(TARGET) *~ dependencies

dependencies : $(SOURCES) $(HEADERS)
	gcc -MM $(SOURCES) >$@

include dependencies
