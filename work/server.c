




void mylog(char * szText){
   char buf[16*1024];
   sprintf( buf , "%5d -- %s\n", getpid(), szText );
   int fd = open ("my.log", O_WRONLY | O_APPEND| O_CREAT, 0644 );
   write(fd , buf, strlen(buf));
   close(fd);
}



int main (int argc, char *argv[]){

    pid_t pid = fork();
    if(pid){
      mylog("I am deamon, deamon started");
      return 0;
    }
    
       




}

