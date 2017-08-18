#include <linux/kernel.h> 
#include <linux/module.h>

#include "cdev.h"

char  *DevContents = 0;
size_t DevContSize = 0;
int    DevOpened  = 0;
