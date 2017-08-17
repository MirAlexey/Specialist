#include <linux/kernel.h> 
#include <linux/module.h>
#include <linux/fs.h>

#include "cdev.h"


int cdev_open (struct inode *inode,
               struct file *file  ) {
                   
    if(MINOR(inode->i_rdev) > 0 ) { 
        return -ENOENT;
    }
    if(DevOpened){
        return -EBUSY;
    }
    
    if(!try_module_get(THIS_MODULE)){
        printk( KERN_ALERT "Can not lock module\n");
        return -EACCESS;
    }
    
    DevContSize  = strlen(DevContents);
    DevOpened = 1;
    
    
    
    printk(KERN_ALERT "Device opened\n");
    
    return 0;
                   
}

int cdev_release(struct inode *inode,
                struct file * file){
    
    DevOpened = 1;
    printk(KERN_ALERT "Device closed\n");                
    module_put(THIS_MODULE);
    return 0; 
}

