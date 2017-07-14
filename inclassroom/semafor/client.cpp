#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/shm.h>


#include "semaphor.h"

int main(int argc, char *argv[]){
  
  struct shared_memory *Mem = 0;
    
  int key = ftok ("./server", 1);
  int idMem = shmget (key, sizeof(struct shared_memory), 0666);  
  Mem = (struct shared_memory*) shmat(idMem, 0,0);  
    
    
    
 // try {
  
   // MySemaphore M(0);
  
  // printf("%s (1)\n", argv[2]);

    printf(" status= %d , data = %s", Mem->status, Mem->szData);

    Mem->status=2;
    strncpy(Mem->szData, "and Hello!!! for you!!!\n", DATASIZE);
    Mem->sizeData = strlen(Mem->szData);
  
    
    
    
    
    
 //   sleep(atoi(argv[1]));
 //   printf("%s (2)\n", argv[2]);
  
//  } catch (int) {
//    fprintf(stderr, "Cannot create semaphore\n");
//  }
    
  shmdt( (void*) Mem);
  shmctl(idMem, IPC_RMID, 0 );
   
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

 
