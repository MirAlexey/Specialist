#include "semaphor.h"

  const char *MySemaphore::szName = SEMNAME ;
  key_t MySemaphore::iKey   = -1      ;
  int MySemaphore::idSem    = -1      ;
  int MySemaphore::nCount   = 0       ;

  MySemaphore::MySemaphore(int index){
    if (iKey < 0){
        iKey = ftok(szName, 1);
        if(iKey < 0) {throw (int)1;}
        idSem = semget (iKey, 2 , 0666 | IPC_CREAT);
    }
    iIndex = index; 
    Buf.sem_num = iIndex;
    Buf.sem_flg = SEM_UNDO;
    semctl(idSem, 0 , SETVAL, 1);
    nCount++;
    lock();
     
  } 

 MySemaphore::~MySemaphore(){
      free();
      semctl(idSem, 2 , IPC_RMID);
      iKey = -1;
      idSem = -1;
   }

 void MySemaphore::lock(){
     Buf.sem_op  = -1 ;    
     semop(idSem, &Buf, 1);
 }
 
 void MySemaphore::free(){
     Buf.sem_op  = 1 ;    
     semop(idSem, &Buf, 1);
 }

