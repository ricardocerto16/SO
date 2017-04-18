#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/*
    pfd[0]-> leitura (output)
    
    pfd[1]-> escrita (input)

                 _______________
          _(pfd[1])->|____PIPE______|->(pfd[0])_ 
         /                                      \
        |                                        |
    write()                                   read()
*/

int main(int argc, char *argv[]) {

	int fd[2];
	char buf[10];
	char escreve[10] = "aleatorio";
	int i;
	int fk;

	pipe(fd);

	fk=fork();
	if( fk == 0) {
		close(fd[0]);

		for(i=0;i<10;i++){
			int n = write(fd[1],escreve,sizeof(escreve));
			printf("Nº bytes : %d , vez = %d \n ", n, i);
		}
	}
	else {

		if(fk==-1) {perror("ERRO NO FORK"); return 1;}
	 	else {
	 		// temos de fechar o fd[1] , para evitarmos
	 		// deadlock e o pai não fica infinitamente 
	 		// á espera que o filho acabe de escrever 
	 		// e para também o filho não ficar sempre á
	 		// que o pai lhe envie o sinal de EOF. Para
	 		// evitarmos isso temos de fazer um close do 
	 		// descritor do fd[1] antes de fazermos o WAIT.

	 		close(fd[1]);
	 		wait(NULL);
	 		// leitura byte a byte
	 		while(read(fd[0],buf,1)>0) {
	 			printf("%c\n", buf[0]);
	 			//sleep(1);
	 		}
	 	}
	}


	return 0;
}