#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main( int argc , char **argv) {

	int p,i,status;

	for(i=1;i<=10;i++){
		p = fork();
		
		if (p == 0) {
			// filho
			printf("Eu filho %d -> %d | Pai -> %d \n",i,getpid(),getppid());
			_exit(1);
		}
		wait(&status);
		printf("O filho com pid %d terminou em %d lugar.\n\n",p,i);
	}
return 0;
}