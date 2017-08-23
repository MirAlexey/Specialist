.PHONY : default clean

CURRENT := $(shell uname -r)
PWD := $(shell pwd)

KDIR := /lib/modules/$(CURRENT)/build

obj-m := multi.o

multi-objs := start.o stop.o

default:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	rm -f *.o *.ko
