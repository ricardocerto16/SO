#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

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
	
	int fdfifo;

	fdfifo = mkfifo("pipe_1",0777);

	if (fdfifo == -1){
		printf("ERRO NO PIPE\n");
	}

	return 0;
}