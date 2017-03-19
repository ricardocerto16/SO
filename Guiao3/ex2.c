#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main ( ){

	int x = fork();
	if (x == 0) {
	execl("/bin/ls","ls","-l",NULL);
	}
	_exit(1);
	return 0;
}