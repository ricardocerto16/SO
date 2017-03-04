#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main( int argc , char **argv) {

	int p,i;

	for(i=1;i<=10;i++){
		p = fork();
		if(p == 0) {
			sleep(1);
			break;
		}
	}
	wait(NULL);
	printf("Eu  -> %d | Pai -> %d \n",getpid(),getppid());
	return 0;
}