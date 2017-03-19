#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h> 

int main (int argc , char * argv[]) {

		argv[0] = "./3";
		execvp("./ex3",&argv[1]);
		perror("Erro ao realizar o execv");
		// execvp -> executa um ficheiro

	return 0;
}