#include <linux/kernel.h>  
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("John Dow <johndow@mail.ru>");

int  __init hello_init(void){
    printk( KERN_ALERT "Hello, world!\n");
    return 0;
}

void __exit hello_exit(void){
   printk(KERN_ALERT "Goodbye!\n");    
}

module_init(hello_init) ;
module_exit(hello_exit) ;
