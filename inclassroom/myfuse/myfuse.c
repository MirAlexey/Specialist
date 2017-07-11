#include <fuse.h>
#include <sys/

/***********************/
int my_getattr(const char *path, , struct stat *stbuf){

  memset (stbuf, 0 , sizeof(struct stat));
  if(strcmp(path, "/") == 0){

     stbuf->st_mode = S_IFDIR | 0755;
     stbuf->st_nlink = 2;
 
  } else if (strcmp(path, "/example.txt") == 0){

     stbuf->st_mode =  0655;
     stbuf->st_nlink = 1;
 
  } else if (strcmp(path, "/exampl.sh") == 0){


     stbuf->st_mode =  0755;
     stbuf->st_nlink = 1;
 
  } else {
     Result = = -ENOENT;
  } 

  return  0;
}


struct fuse_operations oper = {


};
/**************************************************************/

/*
*  path  -путь
*  buf - список элементов в папке
*  fuse_fill_dir_t - информаци о папке (заполняется на низком уровне)
*  offset - необходима для того чтобы когда нужна только части папки 
*  fuse_file_info  - ссылка на внутреннюю функцияю fuse ссылка на функцию которая добавляет новый элемент в список  расположенный в buf
*/

int my_readdir(const char * path, void *buf, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info &fi){

  int Result = 0;
  
  if(strcmp(path, "/") == 0){

     filler(buf , ".", NULL, 0);
     filler(buf , "..", NULL, 0);
     filler(buf , "example.txt", NULL, 0);
     filler(buf , "example.sh", NULL, 0);
     
  } else {
     Result = = -ENOENT;
  } 

  return Result;
}

}

/*********************************/

int main(int argc, char *argv[])

// инициализация структуры

memset( &oper, 0 , sizeof(oper));
oper.getattr = my_getattr ;
oper.reddir = my_readdir ;

return fuse_main(argc, argv, &oper , NULL);
}

