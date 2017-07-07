#include <stdio.h>
#include <string.h>

int parent(int src){

    char Buf[16*1024];
    
    for(int i = 0;;i++){
       int count = read(src, Buf , sizeof(Buf) );
       if (count <= 0) break;
       
       printf("[%s] %d %d\n", Buf, i, count);
    }
    return 0;
   
}

int child(int trg){

      char Buf[16*1024];
      printf(": ");
      fgets(Buf, sizeof(Buf), stdin);
        
      write(trg, Buf , strlen(Buf)+1 );
 
      close(trg);
 
      return 0;

}

int main(int argc, char *argv[]){
  
  int k =0;
  
  int pipes[2];
  pipe(pipes);  

  printf("!!!!!\n");

  int pid = fork();
  if(pid > 0){ 
   
    int src = pipes[0];
    close(pipes[1]);
    return parent(src);
  

  }else if(pid == 0){
  
    int trg = pipes[1];
    close(pipes[0]);
    return child(trg);

  }else{
    fprintf(stderr, "Oi Oi!! pid =  %d", pid);
  }
}
