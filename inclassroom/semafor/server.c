#include <stdio.h>

int main(int argc, char *argv[]){
 
  struct sembuf seml;

  key_t key = ftok(SEMNAME , 1);
  if(key < 0){
    fprintf(stderr, "Error creating key\n"
    return 1;)
  } 

  seml.sem_num = 0;
  seml.sem_flg = SEM_UNDO;
  semop(id, &seml, -1);  


 
  int  id =  semget(key, 2 , 0666 |IPC_CREAT );

  
  
  return 0;
}
