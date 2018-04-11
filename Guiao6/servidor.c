#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/* PIPES COM NOME

int mkfifo(const char *pathname, mode_t mode);

	pfd[0]-> leitura (output)
    pfd[1]-> escrita (input)

                      ______________
          _(pfd[1])->|____PIPE______|->(pfd[0])_ 
         /                                      \
        |                                        |
    write()                                   read()

*/

// pipes com nome tem um bloqueio extra
// é só começam a executar quando existe um par na mesma etapa
// 1 de leitura e 1 de escritas

int main(int argc, char *argv[]){

	int fdpipe;
	int fdlog, n;
	char buffer[256];

	fdpipe = mkfifo("server_pipe",0777);

	if (fdpipe == -1) {
		perror("ERRO NO PIPE\n");
	}

	if (fork() == 0) {

		fdpipe = open("server_pipe",O_RDONLY);
		dup2(fdpipe,0);
		close(fdpipe);
		fdlog = open("log.txt",O_CREAT|O_WRONLY,0666);
		dup2(fdlog,1);
		close(fdlog);

		while( (n = read(0,buffer,256)) > 0){

			write(1,buffer,n);
		}
	}


	return 0;
}