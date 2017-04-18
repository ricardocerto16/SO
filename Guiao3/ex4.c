#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h> 

int main (int argc , char * argv[]) {

<<<<<<< HEAD
		argv[0] = "./3"
		execv("./ex3",&argv[1]);
		perror("Erro ao realizar o execv");
=======
		argv[0] = "./3";
		execvp("./ex3",&argv[1]);
		perror("Erro ao realizar o execv");
		// execvp -> executa um ficheiro
>>>>>>> f6ab6d2db0a195ee9d9d864978236fc88e8a4cab

	return 0;
}