#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]){
    char buf[100];
    
    
    int fd = open("../cdev0", O_RDONLY);
    if(fd< 0){
        printf("fd = %d", fd);
         return 0;
    }
    
    
    for(int k=0 ; k<10 ; k++){
        
        
    memset(buf, 0 , 10);
    int r = read(fd, buf, 5);
    
    printf("{%d}[%s]\n", r, buf);
    sleep(1);
    }
    
    close(fd);
} 
