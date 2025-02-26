/*
 * $Id: hello.c,v 1.5 2004/10/26 03:32:21 corbet Exp $
 */
#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("Dual BSD/GPL"); // 声明模块的许可证 会污染内核符号表吗？
/*
不是必须的，但推荐使用。
`__init` 可以在模块初始化后释放这部分内存，
`__exit` 在模块卸载时才会被调用；即使不加它们，模块也能正常工作，但加上能够帮助内核更好地管理内存。
*/
static int __init hello_init(void)
{
	// insmod后 能够存取内核符号表 日志写入内核环形缓冲区 dmesg /var/log/dmesg
	// printk 优先级有8个 从高到低排序： KERN_EMERG KERN_ALERT KERN_CRIT KERN_ERR KERN_WARNING KERN_NOTICE KERN_INFO KERN_DEBUG
	printk(KERN_ALERT "Hello, world\n");
	return 0;
}

static void __exit hello_exit(void)
{
	printk(KERN_ALERT "Goodbye, cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);
