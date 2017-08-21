// #include <linux/kernel.h> 
// #include <linux/module.h>
// #include <linux/fs.h>
// #include <asm/uaccess.h>
// #include <linux/slab.h>
// 
#include "meteo.h" 

#define MIN MINORE(file->f_inode-i_rdev) ;
// 
ssize_t meteo_write(struct file *file, 
                   const char __user *buffer,
                   size_t length,
                   loff_t *ofs){
    
    
    
    int ItemNo = 0;
    
    if(length == 0) return 0;
    if(*ofs < 0) {
        printk(KERN_ALERT "Negative ofset\n");
        return -EIO;
    }
    
    if(length % sizeof(struct meteo_item) > 0){
        printk(KERN_ALERT "Invalid length\n");
        return -EINVAL;
    }
    ItemCount = length  / sizeof(struct meteo_item);
    
    if(*ofs %sizeof(struct meteo_item) > 0){
        printk(KERN_ALERT "Invalid offset\n");
        return -EIO;
    }
    
     ItemNo = *ofs / sizeof(struct meteo_item);
     if(ItemNo + ItemCount >  METEO_COUNT) {  
         printk(KERN_ALERT "Invalid item number\n");
         return -EIO
         
     }    
     //  проверить разрешено ли писать
     
     for(k = 0 ; k < ItemCount ; k++){
        copy_from_user(&(AllDEV[mIN].Buffer), buffer+k*sizeof(struct meteo_item), sizeof(struct meteo_item)); 
        AllDev[MIN].Item[k].f_status = AllDev[MIN].Buffer[f_status];
    }

     
     
     
     
     printk(KERN_ALERT "%lu bytes read\n", length);
       
     return length;
}
//  
//  
// loff_t cdev_llseek (struct file *file, loff_t ofs,  int whence){
//     switch (whence) {
//         case SEEK_CUR:
//             file->f_pos += ofs;
//             break;
//             
//         case SEEK_SET:
//             file->f_pos = ofs;
//             break;
//             
//         case SEEK_END:
//             file->f_pos = DevContSize + ofs;
//             break;
//         default:
//             return -EINVAL;
//     }
//     
//     return 0;
// } 
//  
//  
//  
