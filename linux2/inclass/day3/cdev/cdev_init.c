#include <linux/kernel.h> 
#include <linux/module.h>
#include <linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Author");


#define DEVICE_NAME "cdev"
// старший номер устройства
static int major = 0;
module_param (major, int, 0644);
MODULE_PARM_DESC(major, "Major device number");

// устройство открыто? 
static int Device_Open = 0;

/*используется для предовращения одновременного обращения из нескольких процессов*/

static char msg[BUF_LEN];
static char* msg_ptr;




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
