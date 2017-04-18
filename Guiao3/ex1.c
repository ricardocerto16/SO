#include <unistd.h>

int main ( ){


<<<<<<< HEAD
	execlp("ls","ls","-l",NULL);
=======
	execl("/bin/ls","ls","-l",NULL);
>>>>>>> f6ab6d2db0a195ee9d9d864978236fc88e8a4cab

	return 0;
}