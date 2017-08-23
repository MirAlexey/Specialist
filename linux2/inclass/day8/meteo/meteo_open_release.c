#include "meteo.h"

#define MIN MINOR(inode->i_rdev)

 int meteo_open (struct inode *inode,
                struct file *file  ) {
     int RetCode =0;
     
     if(MIN >= AllCount ) { 
         // устройство не существует
         RetCode = -ENOENT;
         goto END;
     }     
     
     
     if(!try_module_get(THIS_MODULE)){
         printk( KERN_ALERT "Can not lock module\n");
         
         RetCode = -EACCES;
         goto END1;
     }
     
     // здесь проверка не открыто ли устройство уже
     
  
     printk(KERN_ALERT "Device opened\n");
     
     return 0;

END1:
  // убрать мусор, если он остался после проверки устройства
     

END:
       return RetCode;
}


    int meteo_release(struct inode *inode,
                 struct file *file){
     
    // здесь установить параметры сброса
    
     module_put(THIS_MODULE);   
        
     printk(KERN_ALERT "Device closed\n");                
     
     return 0; 
 }
 
