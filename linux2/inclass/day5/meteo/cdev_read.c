#include <linux/kernel.h> 
#include <linux/module.h>
#include <linux/fs.h>
#include <asm/uaccess.h>

#include "cdev.h" 

ssize_t cdev_read(struct file *file, 
                  char __user *buffer,
                  size_t length,
                  loff_t *ofs){
    if(length == 0) return 0;
    if(*ofs < 0) return -EIO;
    if(*ofs >= DevContSize) return 0;
    
    if(*ofs + length > DevContSize) {  
        length = DevContSize - *ofs;
    }    
    copy_to_user(buffer, DevContents+*ofs, length);
    *ofs += length;
    printk(KERN_ALERT "%lu bytes read\n", length);
      
    return length;
}


