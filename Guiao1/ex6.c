#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

 

int readln(int fd, char *buf, int max){
         int n;
         int i=0;
   
         for(i=0; i<max-1;i++){
         
         n = read(fd,buf+i,1);
         if(n==0) return 0;
         if(buf[i]=='\n') return i; 
         
         }
         
         return i;
}     
   


int main(int argc, char* argv[])
{
   char *buf = malloc(1024);
   char *a = malloc(1024);
   int fd=1,n=1,s=0;

   // caso em que lê de um ficheiro
   if(argc == 2){
      fd = open(argv[1],O_RDONLY);
      if(fd==-1){ perror("ERRO"); return 1;}
      while((s=readln(fd,buf,1024))!=0){  
      sprintf(a,"\t%d %s",n,buf);
      write(1,a,s+4); 
      n++;
         }
   }
   
   // caso que lê de um stdin
   while((s=read(0,buf,1024))!=0){ 
      sprintf(a,"\t%d %s",n,buf);
      write(1,a,s+4); //s+4 porque tem que ser espaço correto s + \t + 2 para o %d + " " ----- so funciona até 99. para 999 3 para o %d
      n++;
   }
  
   
   return 0;
}