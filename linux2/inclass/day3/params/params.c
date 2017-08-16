#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("John Dow <johndow@mail.ru>");

static short int par1 = 1;
module_param( par1, short, 0644 );
MODULE_PARM_DESC( par1, "A short integer!");


static char *par2 = "Hello,world!";
module_param( par2, charp, 0644 );
MODULE_PARM_DESC( par2, "A text parametr!");

int __init init_module(){
    printk( KERN_ALERT"Module started!");
    printk( KERN_ALERT "par1 = %hd\n", par1 );
    printk(KERN_ALERT "par2 = %s\n", par2);
    return 0;    
} 

void __exit cleanup_module(){
    printk( KERN_ALERT"Module stopped\n");
}

