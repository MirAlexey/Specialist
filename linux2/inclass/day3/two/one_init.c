#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE( "GPL" );
MODULE_AUTHOR( "Author" );

int __init init_module(){
    printk(KERN_ALERT "Module 'one' started!\n");
    return 0;    
}

void __exit cleanup_module(){
    printk(KERN_ALERT "Module 'one' stopped\n");    
}
