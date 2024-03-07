#ifndef UTILCLASS
#define UTILCLASS
#include"util.h"
#include<stdlib.h>
#include<cstdio>

void errif(bool cond,const char* mesg){
  if(cond){
    perror(mesg);
    exit(EXIT_FAILURE);
  }
}


#endif
