 

#include <linux/kernel.h>
#include <linux/module.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR ("Author")


static short count ;
module_param(count,short, 0664);
MODULE_PARAM(count,"Quantity of philosophers");

int __init init_module(){
  
    int RetCode = 0 ;
    
    if(count < 0) {
        RetCode = -EINVAL; 
        goto END;
    }
    
    
    
    
    
    printk(KERN_ALERT "Dinner started\n");
    return 0;
    
END: 

    return RetCode;
}

void __exit cleanup_module(
    
    printk(KERN_ALERT "Dinner finished\n");
)
