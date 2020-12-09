obj-m+=hello.o

KDIR = /home/harold/wsl_kernel/WSL2-Linux-Kernel

all:
	make -C $(KDIR) M=$(PWD) modules
clean:
	make -C $(KDIR) M=$(PWD) clean