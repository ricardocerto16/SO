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
	int fd1[2];
	int fd2[2];

	pipe(fd);

	if(fork()==0) {
		close(fd[0]);
		pipe(fd1);

		if(fork()==0){
			close(fd1[0]);
			pipe(fd2);


			if(fork()==0) {
				close(fd2[0]);
				dup2(fd2[1],1);
				close(fd[1]);

				execlp("grep","grep","-v","^#","/etc/passwd",NULL);
				_exit(1);
			}

			dup2(fd2[0],0);
			close(fd2[1]);
			close(fd2[0]);
			dup2(fd1[1],1);
			close(fd1[1]);
			wait(NULL);

			execlp("cut","cut","-f7","-d:",NULL);
			_exit(1);
		}

		dup2(fd1[0],0);
		close(fd1[0]);
		close(fd1[1]);
		dup2(fd[1],1);
		close(fd[1]);
		wait(NULL);

		execlp("uniq","uniq",NULL);
		_exit(1);


	}
	else {
		wait(NULL);
		close(fd[1]);
		dup2(fd[0],0);

		execlp("wc","wc","-l", NULL);

	}

	return 0;
}