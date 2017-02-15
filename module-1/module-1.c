/* A simple module to interact with the log file
and print messages when any of the initialisation
and the cleanup functions are called */

#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>

static int __init initialise_saber(void)
{
	printk(KERN_INFO "Luke, I am your father!\n");
	return 0;
}

static void __exit drop_saber(void)
{
	printk(KERN_INFO "NO!!!!!!!!!!!\n");
}

module_init(initialise_saber);
module_exit(drop_saber);
