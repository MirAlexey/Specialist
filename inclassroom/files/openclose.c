#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define FAMSIZE (35)

struct _man_str{
  char szFam[FAMSIZE] ;
  int nResult ;
};

typedef struct _man_str MAN ; 

int main(int argc, char *argv[]){

  int TRG = open("myfile.dat", O_CREAT | O_WRONLY, 0644 );

  MAN X ;

  strncpy(X.szFam, "Pupkin", FAMSIZE-1);
  X.nResult = 25;
  write(TRG, &X, sizeof(X));

  strncpy(X.szFam, "Ivanof", FAMSIZE-1);
  X.nResult = 20;
  write(TRG, &X, sizeof(X));


  lseek(TRG, 1000*sizeof(MAN), SEEK_END );
  strncpy(X.szFam, "Sidoroff", FAMSIZE-1);
  X.nResult = 15;
  write(TRG, &X, sizeof(X));
  
  //strncpy(X.szFam, "John_Dow", FAMSIZE-1);
  //X.nResult = 10;
  //write(TRG, &X, sizeof(X));
  
  close(TRG);

  
}
