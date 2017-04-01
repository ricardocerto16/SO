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

int main(int argc , char* argv[]) {

	int fd[2];
	int fk;
	char stg[1024];
	int n;


	 if ( pipe(fd) < 0) {
	 	perror("ERRO AO CRIAR PIPE");
	 	return 1;
	 }

	 fk = fork();
	 if(fk == 0) {
	 	close(fd[0]); // fechar a saída ao filho 
	 	
	 	while((n = read(fd[0],stg,sizeof(stg))) > 0) {
	 		//sleep(5);
	 		write(1,stg,n);
	 	}
	 	close(fd[1]);
	 	_exit(1);

	 }
	 else {
	 	if(fk==-1) {perror("ERRO NO FORK"); return 1;}
	 	else {

	 		
	 	
	 		while((n=read(0,stg,sizeof(stg))) > 0) {

	 			//sleep(5);
	 			write(fd[1],stg,n);
	 		}
	 		_exit(1);
	 		close(fd[1]);

	  }
	 }


	return 0;
}
