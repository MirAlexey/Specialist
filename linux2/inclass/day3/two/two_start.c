#include <linux/kernel.h>
#include <linux/module.h>

#include "one.h"

MODULE_LICENSE( "GPL" );
MODULE_AUTHOR( "Author" );

int __init init_module(){
    printk(KERN_ALERT "Module 'two' started!\n");
    one_report("Hello!");
    return 0;    
}
