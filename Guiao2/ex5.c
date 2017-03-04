#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main( int argc , char **argv) {

	int p,status,i;
	p=fork();
	for(i=1;i<=10;i++){
		if(p == 0) {
			p=fork();
		}
		else {
			wait(&status);
			printf("Eu -> %d Status -> %d | Pai -> %d \n\n",getpid(),WEXITSTATUS(status),getppid());
			_exit(1);
		}
	}

return 0;

}