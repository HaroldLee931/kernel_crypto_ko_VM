obj-m+=hello.o
#hello-y:= crypto_entry.o call_drbg.o

KDIR = /home/harold/linux-5.7

all:
	make -C $(KDIR) M=$(PWD) modules
clean:
	make -C $(KDIR) M=$(PWD) clean