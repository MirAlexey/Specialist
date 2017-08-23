.PHONY : default clean

CURRENT := $(shell uname -r)
PWD := $(shell pwd)

KDIR := /lib/modules/$(CURRENT)/build

obj-m := meteo.o

meteo-objs := meteo_init.o meteo_data.o meteo_open_release.o meteo_read.o meteo_write.o

default:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	rm -f *.o *.ko *.mod.c 
	rm Module.symvers modules.order
