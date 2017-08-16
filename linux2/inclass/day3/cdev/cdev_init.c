#include <linux/kernel.h> 
#include <linux/module.h>
#include <linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Author");


#define DEVICE_NAME "cdev"

static int major = 0;
module_param (major, int, 0644);
MODULE_PARM_DESC(major, "Major device number");

static struct file_operations fops ;


int __init init_module(){
    
    memset(&fops , 0 , sizeof(fops));
    // fops.open = ???;
    // fops.read = ???;
    {
        int M = register_chrdev(major, DEVICE_NAME, &fops) ;
        if( M < 0){
           printk(KERN_ALERT "Error: %d\n", M);
           return M;
        }else if (major == 0){
           major = M;
        }
    }
    
    printk(KERN_ALERT "'%s' registered with number %d\n", DEVICE_NAME, major);
    
    return 0;
}

void __exit cleanup_module(){
    
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_ALERT "'%s' unregistred\n", DEVICE_NAME);
        
}
