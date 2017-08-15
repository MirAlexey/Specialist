.PHONY: default clean

CURRENT := $(shell uname -r)

KDIR :=/lib/modules/$(CURRENT)/build

PWD := $(shell pwd)

obj-m := hello.o

default:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	rm -f hell.o hello.ko
