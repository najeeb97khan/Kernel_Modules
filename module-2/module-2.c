/* This simple module interacts with the
log messages file and produces a message
using the printk() function. The module
in addition also contains the license and
associated information */

#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>

static int __init initialise_saber(void)
{
	printk(KERN_INFO "In a galaxy far far away!\n");
	return 0;
}

static void __exit drop_saber(void)
{
	printk(KERN_INFO "May the force be with you!\n");
}

module_init(initialise_saber);
module_exit(drop_saber);

/* Adding Licensing Information */

MODULE_LICENSE("GPL");

/* Adding Author Information */

MODULE_AUTHOR("najeeb.khan96@gmail.com");

/* Adding description for the module */

MODULE_DESCRIPTION("A module with license information");

/* Supported device information present in /dev/ file */

MODULE_SUPPORTED_DEVICE("testdevice");

