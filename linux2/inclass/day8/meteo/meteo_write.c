// #include <linux/kernel.h> 
// #include <linux/module.h>
// #include <linux/fs.h>
// #include <asm/uaccess.h>
// #include <linux/slab.h>
// 
#include "meteo.h" 

#define MIN MINOR(file->f_inode->i_rdev) 




int meteo_item_dispatcher (void *data){
    struct meteo_item *Dt = (struct meteo_item *)data;
    if (! Dt) return -ENOENT ;
    
    try_module_get(THIS_MODULE);
    Dt->f_status = METEO_ACTIVE;
    
    while(!kthread_should_stop()){
     //  проверить разрешено ли писать   
    //    полезные действия
        
      printk(KERN_ALERT "Step counted\n");
      schedule_timeout_interruptible(1000);
    }
    
    Dt->f_status = METEO_INACTIVE;
    module_put(THIS_MODULE);
    return 0;
}

// 
ssize_t meteo_write(struct file *file, 
                   const char __user *buffer,
                   size_t length,
                   loff_t *ofs){
    
    
    
    int ItemNo = 0;
    int ItemCount = 0;
    int k = 0;
    
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
         return -EIO;
         
     }    
     
     
     for(k = 0 ; k < ItemCount ; k++){
        copy_from_user(&(AllDev[MIN].Buffer), buffer+k*sizeof(struct meteo_item), sizeof(struct meteo_item)); 
        if (AllDev[MIN].Items[ItemNo+k].f_status == AllDev[MIN].Buffer.f_status) continue;
        if(AllDev[MIN].Buffer.f_status == METEO_ACTIVE) {
            
           // запуск потока 
           AllDev[MIN].Threads[ItemNo+k] = kthread_run ( meteo_item_dispatcher , (void*)(AllDev[MIN].Items+ItemNo+k), "meteo%dn%d", (int)(MIN), ItemNo+k);
           
           // проверить ошибка
            
        }else{
            kthread_stop (AllDev[MIN].Threads[ItemNo+k]);
            // остановка потока
            // ожидание окончания работы потока
            
            AllDev[MIN].Threads[ItemNo+k] = 0;
        }
        
        
    }

     
     
     
     
     printk(KERN_ALERT "%lu bytes read\n", length);
       
     return length;
}


  
 loff_t cdev_llseek (struct file *file, loff_t ofs,  int whence){
    int ItemNo = 0;
    int ItemCur = 0;
    
    if(!(ofs %sizeof(struct meteo_item) == 0 || ((ofs == -1 || ofs == 1) && whence == SEEK_DATA ))){
        printk(KERN_ALERT "Invalid offset\n");
        return -EINVAL;
    }
    
     ItemNo = ofs / sizeof(struct meteo_item);
     ItemCur = file->f_pos / sizeof(struct meteo_item);
     
     if( (ItemCur + ItemNo) >  METEO_COUNT) {  
         printk(KERN_ALERT "Invalid item number\n");
         return -EINVAL;
         
     }    
     
     
     switch (whence) {
         case SEEK_CUR:
            file->f_pos += ofs;
             break;
             
         case SEEK_SET:
             file->f_pos = ofs;
             break;
             
         case SEEK_END:
             file->f_pos = METEO_COUNT*sizeof(struct meteo_item) - ofs;
             break;
         case SEEK_DATA:
             file->f_pos = ofs * sizeof(struct meteo_item);
             break;
         default:
             return -EINVAL;
     }
     
     return 0;
 } 
//  
//  
//  
