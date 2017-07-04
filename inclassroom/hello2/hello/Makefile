.PHONY: all clean dependencies

SOURCES = goodbye.c \
	  hello.c

HEADERS = hello.h

OBJECTS = $(patsubst %.c,%.o,$(SOURCES))

TARGET = libhello.a

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	ar -r $@ $^

%.o : %.c
	gcc -c $<

clean :
	rm -f *.o $(TARGET) *~ dependencies

dependencies : $(SOURCES) $(HEADERS)
	gcc -MM $(SOURCES) >$@

include dependencies
