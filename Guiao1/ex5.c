#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define TAM 100




int readlinha(int fd, char *buf, int max){
         int n;
         int i=0;
   
         for(i=0; i<max-1;i++){
         
         n = read(fd,buf+i,1);
         if(n==0) return 0;
         if(buf[i]=='\n') return i; 
         
         }
         
         return i;
}     




int main (int argc, char** argv) {
	char *buff;
	int n;

	if (argc !=1) { // permite apenas passarmos um argumento 
		printf("ERROR\n");
		return 1;
	}

	buff = malloc(TAM);

	while (1) {
		n = readlinha(0,buff,TAM);

		write (1,buff,n);

		if (n == 0) return 0;

	}
	free(buff);
	return 0;
}