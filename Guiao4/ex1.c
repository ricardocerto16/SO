#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>


// int dup(int fd);
// int dup2(int fd1, int fd2);

// 0 -> standart input
// 1 -> standart output
// 2 -> standart error


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

	// leitura de caracter a caracter
	while(read(0,&c,1)==1) {
		write(1,&c,1);
		write(2,&c,1);
	}	

	puts("Hello World");

	return 0;

}