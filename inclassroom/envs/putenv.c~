#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#define VARNAME ("YMY")

int main(int argc, char *argv[]){

  char *newValue = 0;
  if (argc <2){
    fprintf( stderr, "???\n");
  }

  newValue = argv[1] ;

  int result = setenv(VARNAME, newValue, 1);
  if ( result ) {
    fprintf(stderr, "Oshibka :p c %s : %d\n", VARNAME, errno);
    return 3;
  }
  
  char *Value = getenv(VARNAME);

  if ( ! Value ) {
    fprintf(stderr, "Variable \" %s\" not found\n", VARNAME);
    return 1;
  }

  printf("%s\n", Value);

  return 0;
} 
