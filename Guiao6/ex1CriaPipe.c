#include <sys/types.h>
#include <sys/stat.h>

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

int main(int argc , char* argv[]) {

	int pipen;

	pipen = mkfifo("ola",0777);
	
	if (pipen == -1) {
		perror("ERRO NA CRIAÇÃO DO PIPE");
	}

	return 0;
}