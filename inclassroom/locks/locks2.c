#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char *argv[]){
 
  if(argc < 4){
    printf("Мало параметров\n");
    return 1;
  }
  char file_name[80];
  int start;
  int end;
  if (sscanf(argv[1], "%s", file_name) != 1) {return 2;};
  if (sscanf(argv[2], "%d", &start) != 1) {return 2;}
  if (sscanf(argv[3], "%d", &end) !=1){return 2;}
   
  printf("file = %s, start = %d, end = %d\n", file_name, start, end); 
 
  int fd = open( file_name , O_WRONLY);
  
  printf("%d\n",fd);
 
  struct flock fi;
  struct flock fi2;

  fi.l_type = F_WRLCK;
  fi.l_whence = SEEK_SET;
  fi.l_start = start;
  fi.l_len = end;


  int R =fcntl(fd, F_SETLK, &fi);
    if (R){
      fprintf(stderr, "Already locked\n");
      int R =fcntl(fd, F_GETLK, &fi2);
      printf ("R = %d, pid = %d, type = %d ", R , fi2.l_pid, fi2.l_type);
      return 1; 
    }
  lseek(fd, start, SEEK_SET);
  write(fd, "QQQQQQQQ", 8);

  fgetc(stdin);

  fi.l_type = F_UNLCK;
  fcntl(fd, F_SETLK, &fi );

  close (fd);
  
  return 0;
}
