#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("kent");

static int __init hello_init(void)
{
	printk(KERN_ALERT "hello, world - this is the kernel speaking!\n");
	return 0;
}

static void __exit hello_exit(void)
{
	printk(KERN_ALERT "short is the life of a kernel module!\n");
}

module_init(hello_init);
module_exit(hello_exit);