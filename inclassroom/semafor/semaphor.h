#ifndef SEMAPHOR_H
#define SEMAPHOR_H
#define SEMNAME "server" 
#include <sys/sem.h>

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
#endif // SEMAPHOR_H

