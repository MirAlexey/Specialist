#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char *argv[]){
 
  int fd = open("data.txt", O_WRONLY);
  printf("%d\n",fd);
 
  struct flock fi;

  fi.l_type = F_WRLCK;
  fi.l_whence = SEEK_SET;
  fi.l_start = 16;
  fi.l_len = 8;


  int R =fcntl(fd, F_SETLK, &fi);
    if (R){
      fprintf(stderr, "Already locked\n");
      return 1;
    }
  lseek(fd, 16 , SEEK_SET);
  write(fd, "QQQQQQQQ", 8);

  fgetc(stdin);

  fi.l_type = F_UNLCK;
  fcntl(fd, F_SETLK, &fi );

  close (fd);
  
  return 0;
}
