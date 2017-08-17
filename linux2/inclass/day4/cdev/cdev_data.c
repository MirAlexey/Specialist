#include <linux/kernel.h> 
#include <linux/module.h>

#include "cdev.h"

char  *DevContents = "Ололо ололо я водитель НЛО\n";
size_t DevContSize = 0;
int    DevOpened  = 0;
