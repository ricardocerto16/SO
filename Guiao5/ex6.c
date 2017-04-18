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
	char buffer[20];
	int i;

	pipe(fd);

	if( fork()== 0 ) {
		close(fd[0]);

		dup2(fd[1],1);
		close(fd[1]);

		execlp("ls","ls","/etc",NULL);
		_exit(1);
	}
	else {
		
		close(fd[1]);
		wait(NULL);
		dup2(fd[0],0);
		execlp("wc","wc","-l",NULL);
	}

	return 0;
}