#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>



int main(int argc, char *argv[]){
	
	int fd[2];
	int fk, n;
	char buffer[1024];
	pipe(fd);
	char * msg1 = "mensagem inicial \n";
	char * msg2 = "Final \n";

	fk = fork();
	if( fk == 0) {

		close(fd[1]); // fechou a escrita ao filho porque ele só vai escrever
		while(1){

			n = read(fd[0],buffer,sizeof(buffer));
			if(n<0) break;
			write(1,buffer,n);
		} 
		close(fd[0]); // depois de efetuar as leituras fecha o descritor de leitura
		_exit(0);
	}
	else {
		if (fk == -1) { printf("ERRO NO FORK\n");}
		else {

			close(fd[0]); // fechou a leitura para o pai
			sleep(5); // bloqueia o read até ser sido escrito alguma coisa no pipe

			write(fd[1],msg1,strlen(msg1));
			write(fd[1],msg2,strlen(msg2));

			close(fd[1]); // fecha a escrita depois de um pai escrever

		}
	}


	return 0;
}