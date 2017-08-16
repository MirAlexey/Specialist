.PHONY : default clean

CURRENT := $(shell uname -r)
PWD := $(shell pwd)

KDIR := /lib/modules/$(CURRENT)/build

obj-m := cdev.o

cdev-objs := cdev_init.o 

default:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	rm -f *.o *.ko
