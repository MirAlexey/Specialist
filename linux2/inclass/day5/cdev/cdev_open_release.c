#include <linux/kernel.h> 
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/slab.h>

#include "cdev.h"

#define STATR_TEXT "Hello, world and you!!!"
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
        return -EACCES;
    }
    
    
    
    DevContSize  = strlen(STATR_TEXT);
    DevContents = (char*)kmalloc(DevContSize+1,GFP_KERNEL);
    if(! DevContents){
        printk(KERN_ALERT "Out of memory\n");
        DevContSize = 0;
        return -ENOMEM ;
    }
    
    memset(DevContents, 0 , DevContSize+1);
    strncpy(DevContents, STATR_TEXT, DevContSize+1);
    DevOpened = 1;
    
    
    
    printk(KERN_ALERT "Device opened\n");
    
    return 0;
                   
}

int cdev_release(struct inode *inode,
                struct file * file){
    
    kfree(DevContents);
    DevContSize = 0;
    DevContents = 0;
    DevOpened = 0;
    printk(KERN_ALERT "Device closed\n");                
    module_put(THIS_MODULE);
    return 0; 
}

