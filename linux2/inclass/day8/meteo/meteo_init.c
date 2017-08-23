#include "meteo.h"





 MODULE_LICENSE("GPL");
 MODULE_AUTHOR("Author");

 
 
 
// старший номер устройства
    static int major = 0;
    module_param (major, int, 0644);
    MODULE_PARM_DESC(major, "Major device number");
 
   // устройство открыто? 
    static short count = 1;
// 
    module_param (count, short, 0644);
    MODULE_PARM_DESC(count, "Count device number");
   

    static struct file_operations fops = {
      .open = meteo_open,
      .release = meteo_release,
      .read = meteo_read,
      .write = meteo_write
      
    } ; 

 
    int __init init_module(){
        
//    int k; 
    
    int RetCode = 0;
        
    if(count <1 || count> 256 ){
        RetCode = -EINVAL ;
        goto END;
    } 
         
        
    {    
        AllDev = (struct meteo_group*) kmalloc(sizeof(struct meteo_group)*count, GFP_KERNEL ) ;
        if(!AllDev){
            printk(KERN_ALERT "'meteo': out of memory (1)\n");
            RetCode = -ENOMEM;
            goto END; 
        }
        memset(AllDev, 0 , count*sizeof(struct meteo_group));                
            
        //  так как мы выделяем память для структур group то выделяется память сразу под всю группу 
        //(у нас объявлен макссив нужного размера и под него стразу выделяется память)
//         for(k = 0 p; k < count ; k++){
//             AllDev[k] = (struct meteo_item*) kmalloc(METEO_COUNT * sizeof(struct meteo_item), GFP_KERNEL) ;
//             if(! AllDem[k]){
//                 
//                 printk(KERN_ALERT "meteo': out of memory (2)\n");   
//                 RetCode = _ENOMEM;
//                 goto EMD1;
//             }
//             memset (AllDev[k], 0 , METEO_COUNT*sizeof(meteo_item) );
//         }
        
        AllCount = count;
    }{
         int M = register_chrdev(major, METEO_NAME, &fops) ;
         if( M < 0){
            printk(KERN_ALERT "Error: %d\n", M);
            RetCode = M ;
            goto END1;
            
         }else if (major == 0){
            major = M;
         }
     }
    // END2 нужен для того что бы если появиться дополнительные действия между регистрацие и выходом
    // нужно вставить место где устройство разрегистрируется
     
     printk(KERN_ALERT "'%s' registered with number %d\n", METEO_NAME, major);
     
     return 0;
     
//END2:
    unregister_chrdev(major, METEO_NAME);
     
// END1: удаляем аналогично вверхнему куску, по тойже причине
//     for(k=0; k<count ; k++){
//         if(AllDev[k]){
//             kfree(AllDev[k]);
//         }
//     }
END1: ;

//END1a: 
    kfree(AllDev);
     
END: 
    
    return RetCode;
 
   
 
}
 
 void __exit cleanup_module(){
     
//     int k;
     unregister_chrdev(major, METEO_NAME);
     printk(KERN_ALERT "'%s' unregistred\n", METEO_NAME);
     
//      for(k=0; k<AllCount ; k++){
//         if(AllDev[k]){
//             kfree(AllDev[k]);
//         }
//      }
     kfree(AllDev);
     
 
         
 }
