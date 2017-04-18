#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

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

	int op, w;
	char dd[1024];
	

	op = open("ola",O_RDONLY); 
	

	while(1) {

		printf("Estou á espera\n");
		
		w = read(op,dd,1024);
		write(0,dd,w);
		
		printf("1 2 3 Mensagem recebida\n");
		printf("Repito , mensagem repetida\n");

	}


	close(op);

	return 0;
}