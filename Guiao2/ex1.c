#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>


/*
	pid_t getpid(void);
    pid_t getppid(void);
    pid_t fork(void);
    void _exit(int status);
	pid_t wait(int *status);
	pid_t waitpid(pid_t pid, int *status, int options);
	int WIFEXITED(int status); 
	int WEXITSTATUS(int status);
*/ 

int main(int argc , char **argv) {

	printf("Eu filho - %d\n", getpid());
	printf("Pai - %d\n", getppid());
	return 0;

}