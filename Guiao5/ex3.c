#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

//dup2(origem,destino)

int main(int argc, char *argv[]){
	
	int fd[2];
	int fk, n;
	char buffer[1024];


	if (pipe(fd) < 0){
		printf("ERRO NO PIPE\n");
		return 1;
	}

	fk = fork();
	if( fk == 0){

		close(fd[1]);
		dup2(fd[0],0); // o modo de leitura passa a ser standart input
		close(fd[0]);
		execlp("wc","wc","guiao-05.pdf",NULL);
		_exit(1); // só executa se o exec falhar
	}
	else {
		if( fk == -1) { printf("ERRO NO FORK\n"); 
					return 1; }

		else {
			close(fd[0]);


				while( (n = read(0,buffer,sizeof(buffer))) > 0) {
					write(fd[1],buffer,n);
				} 
				close(fd[1]);

			}
		}
	
	return 0;

}