#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/semaphore.h>
#include <linux/kthread.h>
#include <linux/sched.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Author");

#define LIMIT 20

static short count = 5;
module_param(count,short, 0664);
MODULE_PARM_DESC(count,"Quantity of philosophers");

static short food = 10;
module_param(food,short, 0664);
MODULE_PARM_DESC(food, "Quantity of food");

static unsigned int Food[LIMIT];

static struct semaphore Stick[LIMIT];
static struct task_struct *People[LIMIT];

static int Numbers[LIMIT];

int dinner_process(void* data){
    int n = *(int*)data;
   
    
    while(Food[n]>0){
        if(down_trylock(Stick+n)){
            schedule();
            continue;
        }
        if(down_trylock( Stick + (n+1)%count)){
            up(Stick+n);
            schedule();
        }
        Food[n] -=1;
        
        up(Stick + (n+1)%count);
        up(Stick + n);
        
        schedule_timeout(n*100);
        
        printk( KERN_ALERT "Rest of %d is %d\n", n , Food[n]);
    }
    
    return 0;
}



int __init init_module(){
  
    int RetCode = 0 ;
    int k;
    
    if(count < 2 || count > LIMIT) {
        RetCode = -EINVAL; 
        goto END;
    }
    
    // расскладываем палочки
    
    for(k=0; k<count; k++){
        sema_init(Stick+k, 1);
    }
    
    // раскладываем рис
    
    for(k = 0 ; k < count ; k++){
        Food[k] = food;
        Numbers[k]=k;
    }
    
    //запускаем обед
    
    for(k=0;k<count; k++){
        
        People[k] = kthread_run(dinner_process, 
                                   (void*)(Numbers+k),
                                   "dinner%d", k);
    }
        
    printk(KERN_ALERT "Dinner started\n");
    return 0;
    
END: 

    return RetCode;
}

void __exit cleanup_module(){
    
    printk(KERN_ALERT "Dinner finished\n");
}
