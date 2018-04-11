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

	int op, n;
	char buffer[512];


	op = open("pipe_1",O_RDONLY);

	if( op == -1){
		printf("ERRO NA ABERTURA DO PIPE\n");
	}


	while( (n = read(op,buffer,512)) > 0 ){
		
		write(0,buffer,n);

		printf("Mensagem recebida\n");
	}

	close(op);

	return 0;
}