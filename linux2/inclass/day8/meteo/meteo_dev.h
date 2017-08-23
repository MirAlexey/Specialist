#ifndef METEO_DEV_H 
#define METEO_DEV_H


// #include <linux/kernel.h>
// #include <linux/module.h>
// #include <linux/fs.h>
// #include <linux/slab.h>
// #include <linux/uaccess.h>
// #include <linux/kthread.h>
// #include <linux/sched.h>

#define METEO_COUNT 16


// really  sizeof(double)
#define DATASIZE    8
#define METEO_NAME "meteo"


struct meteo_item {
   char   f_ID[4];
   int    f_status;
#ifdef __KERNEL__
   char   f_data[DATASIZE];
#else
   union {
       char f_data[DATASIZE];
       double f_value;
   } D; 
#endif   
   time_t f_last;
};

#define METEO_ACTIVE   1
#define METEO_INACTIVE 0

#ifndef __KERNEL__
#define CHECK_SIZE ( sizeof(double) == DATASIZE )
#endif


#endif // METEO_DEV_H
