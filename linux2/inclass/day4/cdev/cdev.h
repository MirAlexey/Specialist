#ifndef CDEV_H 
#define CDEV_H

extern char  *DevContents;
extern size_t DevContSize;
extern int    DevOpened;

int cdev_open(struct inode *inode, struct file *file);
int cdev_release(struct inode *inode, struct file *file);
ssize_t cdev_read(struct file *file, char __user *buffer, size_t length, loff_t *ofs);
#endif // CDEV_H
