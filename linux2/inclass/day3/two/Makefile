.PHONY : default clean

CURRENT := $(shell uname -r)
PWD := $(shell pwd)

KDIR := /lib/modules/$(CURRENT)/build

obj-m := one.o two.o

one-objs := one_init.o one_func.o

two-objs := two_start.o two_stop.o

default:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	rm -f *.o *.ko
