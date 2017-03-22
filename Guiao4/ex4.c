#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int main( int argc , char *argv[]){

	int fd;

	// cláusula ficheiro de entrada
	if (strcmp(argv[1],"-i")==0){

		fd=open(argv[2],O_RDONLY,0666);
		dup2(fd,0);
		close(fd);
		execvp(argv[3],&argv[3]);  //&argv[3] -> tudo o que está guardado a partir das pos3
		perror("ERRO FICHEIRO DE ENTRADA");



	}
	//cláusula ficheiro de saída
	else if (strcmp(argv[1],"-o")==0){

		fd=open(argv[2],O_CREAT|O_WRONLY|O_TRUNC,0666);
		dup2(fd,1);
		close(fd);
		execvp(argv[3],&argv[3]);  
		perror("ERRO FICHEIRO DE SAÍDA");

	}
	else {
		perror(">>>ERRO NA EXECUÇÂO<<<");
	}

	return 0;
}