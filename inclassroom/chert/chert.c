#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>


void mylog(char * szText){
  char buf[16*1024];
  sprintf( buf , "%5d -- %s\n", getpid(), szText );
  int fd = open ("my.log", O_WRONLY | O_APPEND| O_CREAT, 0644 );
  write(fd , buf, strlen(buf));
  close(fd);
}

void term_handler(int sigid){
  mylog("Terminating");
  unlink("/var/lock/chert-lock");
  _exit(0);
}

int main (int argc, char *argv[]) {

   mylog("Deamon is ready to stert");

   int fd = open("/var/lock/chert-lock", O_RDONLY);
   if(fd >=0){
      mylog("Already started, terminated!");
      return 1;
   }
   
    pid_t pid = fork();

   if(pid){
     mylog("I am deamon, deamon started");
     return 0;
   }
  
   fd = open ("/var/lock/chert-lock", O_WRONLY| O_CREAT| O_TRUNC, 0600);
   
   char szBuf[16*1024] ;
   sprintf(szBuf, "%d", getpid());
   write(fd, szBuf, strlen(szBuf));
   close (fd);
 
   struct sigaction sa;
   sa.sa_handler = term_handler;
   sigaction(SIGTERM, &sa, 0);

   int sock = socket (AF_INET, SOCK_STREAM, 0);


   if(sock < 0) {
     mylog("Cannot create socket, exiting");
     return 1;
   }
   
   struct sockaddr_in sadr;
   sadr.sin_family = AF_INET;
   sadr.sin_addr.s_addr  = INADDR_ANY;
   sadr.sin_port   = htons(5431);
   if(bind(sock, (struct sockaddr*)&sadr, sizeof(sadr)) < 0){
     mylog(" Cannot bind socet");
     return 2;
   }





   for(;;){
     mylog("i am deamon, i am running");
     listen(sock, 10);
     int pid = fork();
     if(! pid) break;
   }
     
     struct sockaddr_in client;
     int clen= sizeof(client);
     int newsock = accept(sock,(struct sockaddr*)&client, &clen  );
 
     if(newsock < 0){
      mylog("Error accepting");
      return 3;
     }
     
     char Buf[16*1024];
     read(newsock, Buf, sizeof(Buf));
     mylog( Buf );
     sprintf(Buf, "deamon accept pid : %d\n", getpid());
     mylog(Buf);
     write(newsock, "OK", 2);
     close(newsock);
     
     
   
   return 0;

}
