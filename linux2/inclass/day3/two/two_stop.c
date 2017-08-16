#include <linux/kernel.h>
#include <linux/module.h>



void __exit cleanup_module(){
    printk(KERN_ALERT "Module 'two' stopped\n");    
} 
