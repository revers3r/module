#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/sched.h>

MODULE_LICENSE("GPL");
void device_exit(void);
int device_init(void);

int device_init(void)
{
	struct task_struct *task;
	for_each_process(task) {
		printk("%s[%d]\n", task->comm, task->pid);
	}
	return 0;
}
void device_exit(void)
{
	printk(KERN_NOTICE "assignment: exiting module");
}

module_init(device_init);
module_exit(device_exit);
