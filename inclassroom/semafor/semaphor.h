#ifndef SEMAPHOR_H
#define SEMAPHOR_H
#define SEMNAME "server" 
#include <sys/sem.h>
#include <stdio.h>

class MySemaphore {
  private:
   static  const char *szName  ;
   static  key_t iKey    ;
   static  int idSem     ;
   static  int nCount    ;

   int iIndex            ; 
   struct sembuf Buf     ; 
    
   void lock()           ;
   void free()           ;
 public:
   MySemaphore(int index);
   virtual ~MySemaphore();
};


#define DATASIZE (512)
struct shared_memory {
  int status;
  int sizeData ;
  char szData[DATASIZE];
};



#endif // SEMAPHOR_H

