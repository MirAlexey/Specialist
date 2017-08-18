#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]){
    
    int r;
    char buf[1024];
    int fd = open("../cdev0", O_RDWR);
    if(fd< 0){
        fprintf(stderr, "Error opening device%d\n", errno);
         return fd;
    }
    
    
    
    r = read(fd, buf, 5); 
    printf("1. {%d} [%s]\n",  r, buf);
    
    r = lseek(fd , 5 , SEEK_CUR);
    printf("2. {%d}\n", r);
    
    r =read(fd, buf, 5); 
    printf("3. {%d} [%s]\n",  r, buf);
    
    r = write(fd, "12345", 5);
    printf("4. {%d}\n", r);
    
    r = lseek(fd , 0 , SEEK_SET);
    printf("5. {%d}\n", r);
    
    r = read (fd, buf, 1023);
    printf("6. {%d} [%s]\n",  r, buf);
    
    
    close(fd);
} 
