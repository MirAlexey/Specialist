#include "semaphor.h"

  union semun {
            int              val;
            struct semid_ds  *buf;
            unsigned short   *array;
            struct seminfo   *__buf;
  };


  const char *MySemaphore::szName = SEMNAME ;
  key_t MySemaphore::iKey   = -1      ;
  int MySemaphore::idSem    = -1      ;
  int MySemaphore::nCount   = 0       ;

  MySemaphore::MySemaphore(int index){
    if (iKey < 0){
        iKey = ftok(szName, 1);
        if(iKey < 0) {throw (int)1;}
        printf("iKey = %d\n",iKey);
        idSem = semget (iKey, 2 , 0666);
        printf("Имеющийся idSem = %d\n",idSem);
        if ( idSem < 0){
            idSem = semget (iKey, 2 , 0666 | IPC_CREAT);
            printf("Созданный idSem = %d\n",idSem);
            semctl(idSem, 0 , SETVAL, 1);
        }
    }
    iIndex = index; 
    Buf.sem_num = iIndex;
    Buf.sem_flg =0;//SEM_UNDO;
    
    nCount++;
    lock();
     
  } 

 MySemaphore::~MySemaphore(){
      int id =semget (iKey, 2 , 0666);
      if(id >= 0){
        free();
        semctl(idSem, 2 , IPC_RMID, 0);
      }
      iKey = -1;
      idSem = -1;
   }

 void MySemaphore::lock(){
     int res = semctl(idSem, 0 , GETVAL, 0);
     printf("status = %d\n", res);
     Buf.sem_op  = -1 ; 
     semop(idSem, &Buf, 1);
 }
 
 void MySemaphore::free(){
     int res = semctl(idSem, 0 , GETVAL, 0);
     printf("status = %d\n", res);
     Buf.sem_op  = 1 ;    
     semop(idSem, &Buf, 1);
 }

