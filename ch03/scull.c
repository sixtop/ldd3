#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Victor Palacios");

static char *whom = "world";
static int howmany = 1;

module_param(howmany, int, S_IRUGO);
module_param(whom, charp, S_IRUGO);

static __init int hello_init(void)
{
	int i;
	printk(KERN_ALERT "Invoked from %d\n", current->pid);	
	for(i = 0; i < howmany; i++)
	{
		printk(KERN_ALERT "Hello, %s\n", whom);
	}
	
	return 0;
}
static void hello_exit(void)
{
	printk(KERN_ALERT "Goodbye, kernel world\n");
}

module_init(hello_init);
module_exit(hello_exit);
