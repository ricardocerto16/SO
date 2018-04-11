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

	int op;
	char buffer[256];
	int n;

	op = open("server_pipe",O_WRONLY);

	printf("INSIRIR MSG A ENVIAR:\n");

	while( ( n = read(0,buffer,256)) > 0){

		write(op,buffer,n);
	}

	close(op);

	return 0;
}