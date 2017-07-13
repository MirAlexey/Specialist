#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "semaphor.h"

int main(int argc, char *argv[]){
  
  try {
  
    MySemaphore M(0);
  
    printf("%s (1)\n", argv[2]);
    sleep(atoi(argv[1]));
    printf("%s (2)\n", argv[2]);
  
  } catch (int) {
    fprintf(stderr, "Cannot create semaphore\n");
  }
  
  return 0;
}

/*  struct sembuf seml;

  key_t key = ftok(SEMNAME , 1);
  if(key < 0){
    fprintf(stderr, "Error creating key\n"
    return 1;)
  } 

  int  id =  semget(key, 2 , 0666 |IPC_CREAT );




  seml.sem_num = 0;
  seml.sem_flg = SEM_UNDO;
  semop(id, &seml, -1);   */

 
