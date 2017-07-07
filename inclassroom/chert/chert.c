#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void mylog(char * szText){
  char buf[16*1024];
  sprintf( buf , "%5d -- %s\n", getpid(), szText );
  int fd = open ("my.log", O_WRONLY | O_APPEND| O_CREAT, 0644 );
  write(fd , buf, strlen(buf));
  close(fd);
}



int main (int argc, char *argv[]) {

   mylog("Deamon is ready to stert");
   int pid = fork();

   if(pid){
     mylog("I am deamon, deamon started");
     return 0;
   }
   for(;;){
   mylog("i am deamon, i am running");
   sleep( 2 );
   }
   return 0;

}
