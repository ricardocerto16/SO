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


int main(int argc , char* argv[]) {

	int op,n;
	char dd[1024];

	op = open("ola",O_WRONLY); 

	if (op == -1) {
		perror("ERRO NO INPUT DO PIPE");
		_exit(-1);
	}

	while((n = read(0,dd,1024)) > 0) {
		
		write(op,dd,n);
	}

	close(op);

	return 0;
}