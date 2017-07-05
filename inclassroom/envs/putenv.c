#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define VARNAME ("YMY")
#define BUFSIZE (16*1024)


int main(int argc, char *argv[]){

  char *newValue = 0;
  
  if (argc <2){
    fprintf( stderr, "???\n");
  }

  
  newValue = argv[1] ;

  char *Buf = (char*)malloc(BUFSIZE);

  memset (Buf, 0 , BUFSIZE);

  strncpy(Buf, VARNAME, BUFSIZE-1 );
  strncat (Buf, "=", BUFSIZE-1);
  strncat(Buf, newValue, BUFSIZE-1 );

  printf("%s\n", Buf);
  
  int result = putenv(Buf);
  if ( result ) {
    fprintf(stderr, "Oshibka :p c %s : %d\n", VARNAME, errno);
    return 3;
  }

  strncat(Buf, "Hello world", BUFSIZE-1);



  
  char *Value = getenv(VARNAME);

  if ( ! Value ) {
    fprintf(stderr, "Variable \" %s\" not found\n", VARNAME);
    return 1;
  }

  printf("%s\n", Value);

  free(Buf);
  
  return 0;
} 
