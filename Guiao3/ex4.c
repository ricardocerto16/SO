#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]){

	argv[0] = "./ex3";
	execvp(argv[0],argv);
	perror("Erro no exec")
	


	return 0;
}