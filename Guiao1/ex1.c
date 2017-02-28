
#include <unistd.h> 
#include <fcntl.h>
#include <stdio.h>
#define TAM 10

/*  
int     open(const char*path, int oflag [, mode]);
open -> serve para abrir um ficheiro

ssize_t read(int fildes, void*buf, size_t nbyte);
read -> serve para ler um ficheiro

ssize_t write(int fildes, const void *buf, size_t nbyte);
write -> serve para escrever no ficheiro

int  close(int fildes);
close -> fecha um ficheiro
*/

// stdin -> 0 
// stdout -> 1




int main (int argc, char **argv) {

	char buff[TAM];
	int n;

	if (argc !=1) { // permite apenas passarmos um argumento 
		printf("ERROR\n");
		return 1;
	}

	while (1) {
		n = read (0,buff,TAM);
		
		if (n <= 0) return 0;

		write (1,buff,TAM);

	}


}
