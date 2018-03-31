#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char *argv[]){
		
	int fd[2];

	if (pipe(fd) < 0) { printf("ERRO PIPE\n"); return 1;}


	if ( fork() == 0) {

		close(fd[0]);
		dup2(fd[1],1);
		close(fd[1]);

		execlp("ls","ls","/etc",NULL);
		perror("ls");
		_exit(1);
	}

	// processo pai
	close(fd[1]);
	wait(NULL);
	dup2(fd[0],0);

	execlp("wc","wc","-l",NULL);

	_exit(1);

	return 0;
}