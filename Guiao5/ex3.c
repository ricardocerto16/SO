#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

 //pfd[0]-> leitura (output)
    
    //pfd[1]-> escrita (input)

 /*                  _______________
          _(pfd[1])->|____PIPE______|->(pdf[0])_ 
         /                                      \
        |                                        |
    write()                                   read()

    end of file acontece quando se fecha todas as entradas dos processos ativos,do pipes deles.
*/

int main( int argc , char* argv[]) {

	int fd[2];
	int fk;
	int n;
	char buff[1024];

	if ( pipe(fd) < 0) {
	 	perror("ERRO AO CRIAR PIPE");
	 	return 1;
	}

	fk=fork();
	
	if(fk == 0) {
		//close(fd[1]);
		dup2(fd[0],0);
		//close(fd[0]);

		execlp("wc","wc","guiao-05.pdf",NULL);
		wait(NULL);
		_exit(1);

	}
	else {

		if( fk == -1) {
			perror("ERRO NO FORK");
			return 1;
		}
		else {

			dup2(fd[1],1);

			while((n=read(0,buff,sizeof(buff)))>0){
				write(fd[1],buff,n);
			}

			close(fd[1]);
			_exit(1);
		}
	}


	return 0;
}