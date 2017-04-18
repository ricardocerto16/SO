#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main ( ){

	int x = fork();
	if (x == 0) {
<<<<<<< HEAD
	execlp("ls","ls","-l",NULL);
=======
	execl("/bin/ls","ls","-l",NULL);
>>>>>>> f6ab6d2db0a195ee9d9d864978236fc88e8a4cab
	}
	_exit(1);
	return 0;
}