/* This module takes in command line arguments
to initialise the value of variables specified
at the run time. The command line arguments
need to be declared before they are used in the
code elsewhere */

#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>
// Header files for Command Line Arguments
#include<linux/moduleparam.h>
#include<linux/stat.h>

// Variable declaration
static int array_size = 10;
/* Explicit parameter declaration
as part of the command line args */
module_param(array_size,int,0);
// Description of the argument
MODULE_PARM_DESC(array_size, "Size of the array");


// Array declaration
static int array[10] = {1,2,3,4,5,6,7,8,9,10};
// Explicit paramter and size declaration
module_param_array(array,int,&array_size,0000);
// Description of the argument
MODULE_PARM_DESC(array, "An array of numbers");

static int __init initialise_saber(void)
{
	int i;
	printk(KERN_INFO "Starting countdown for launch of Death Star\n");
	if(array_size > 10)
		array_size = array_size%10;
	printk(KERN_INFO "Number of seconds to destruction %d\n",array_size);
	for(i = 0; i < array_size; i++)
		printk(KERN_INFO "%d seconds passed\n",array[i]);
	return 0;
}

static void __exit drop_saber(void)
{
	printk(KERN_INFO "Republic is destroyed! Dark side wins!!\n");
}

module_init(initialise_saber);
module_exit(drop_saber);

// Licensing information
MODULE_LICENSE("GPL");
MODULE_AUTHOR("najeeb.khan96@gmail.com");
MODULE_DESCRIPTION("Module with command line arguments");

	
