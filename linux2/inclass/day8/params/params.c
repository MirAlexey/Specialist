#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>

#define PARAM_SIZE 256

#define PROC_ITEM_NAME "ololo"
/// неизвестная часть


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Author");


static short par1 = 0;
module_param (par1, short, 0644);
MODULE_PARM_DESC(par1, "Param 1");
    
    
static char *par2 = "Hello World!";
module_param (par2, charp, 0644);
MODULE_PARM_DESC(par2, "Param 2");

/// 

static struct proc_dir_entry *pde = 0;

    struct file_operations fops = {
//       .open = meteo_open,
//       .release = meteo_release,
//       .read = meteo_read,
//       .write = meteo_write
        .owner = THIS_MODULE
    };  


int __init init_module(){

    printk(KERN_ALERT "Module started\n" );
    printk(KERN_ALERT "part1 = %hd\n", par1);
    printk(KERN_ALERT "part2 = %s\n", par2);

    //pde = create_proc_entry(PROC_ITEM_ITEM, NULL);
    pde = proc_create (PROC_ITEM_NAME, 
                       0664|S_IFREG, 
                       NULL,
                       &fops
                      );
    
    if(!pde){
        printk(KERN_ALERT "Cannot create proc entry\n");
        return -ENOMEM;
    }

//     pde->uid = 0;
//     pde>gid = 0;
//     pde->proc_fops = &fops;
    
    printk(KERN_ALERT "Proc entry created\n");
    return 0;
}

void __exit cleanup_module(){
    remove_proc_entry(PROC_ITEM_NAME, NULL);
    printk(KERN_ALERT "Module stoped\n");
}





 
