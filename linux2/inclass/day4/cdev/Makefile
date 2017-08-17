.PHONY : default clean

CURRENT := $(shell uname -r)
PWD := $(shell pwd)

KDIR := /lib/modules/$(CURRENT)/build

obj-m := cdev.o

cdev-objs := cdev_init.o cdev_data.o cdev_open_release.o cdev_read.o

default:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	rm -f *.o *.ko
