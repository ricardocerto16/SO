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

	int pfd[2];
  	char buf[10];
  	char dados[1024];
  	int i;

  	pipe(pfd);

  	 if(fork()==0) {
    	close(pfd[0]);

    	dup2(pfd[1],1);
    	close(pfd[1]);
    	execlp("ls", "ls", NULL);
    	perror("ERRO COMANDO: ls");
    	_exit(1);
	  }
  	else {
    	close(pfd[1]);
    	while(read(pfd[0], buf, 1) > 0) {
        	printf("%c", buf[0]);
    	}
  	}

	return 0;
}