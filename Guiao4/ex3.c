#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>


int main(int argc , char * argv[]){

	int fd = open("/etc/passwd",O_RDONLY);
	char c;
	int fd2;

	if(fd==-1) {
		perror("ERRO EM /etc/passwd");
		_exit(1);
	}

	// redirecionar o std input para o ficheiro /etc/passwd
	dup2(fd,0);
	close(fd);


	fd = open("saida.txt", O_CREAT|O_WRONLY|O_TRUNC, 0666);
	
		if(fd==-1) {
			perror("ERRO no ficheiro saida.txt");
			_exit(1);
		}	

	dup2(fd,1);
	close(fd);

	fd2 = open("erros.txt", O_CREAT|O_WRONLY|O_TRUNC, 0666);

		if(fd2==-1) {
			perror("ERRO no ficheiro erros.txt");
			_exit(1);
			}

	dup2(fd2,2);
	close(fd2);

	execlp("wc","wc",NULL);
	perror("Erro no comando wc");


	puts("Hello World\n");
	puts("Versão do exercício nº3\n");

	return 0;
}