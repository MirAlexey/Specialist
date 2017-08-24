.PHONY : default clean

CURRENT := $(shell uname -r)
PWD := $(shell pwd)

KDIR := /lib/modules/$(CURRENT)/build

obj-m := dinner.o

dinner-objs := dinner_init.o

default:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	rm -f *.o *.ko
