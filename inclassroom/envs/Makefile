.PHONY : all clean 

all : envlist getenv putenv

envlist : envlist.c
	gcc -o $@ $^

getenv : getenv.c
	gcc -o $@ $^

putenv : putenv.c
	gcc -o $@ $^

clean :
	rm -f envlist getenv putenv
