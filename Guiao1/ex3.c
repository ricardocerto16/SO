#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>




int main (int argc , char **argv) { 

	int n=1;
	int tam;
	char *buffer;

	
	
	if (argc != 2) {
		printf("ERROR\n");
		return 1;
	}


	// converte uma string para inteiro
	// passa a string do nº de args para int de forma a ser
	// o número de bytes que o buffer vai ler de cada vez
	tam = atoi (argv[1]);
	buffer = malloc(tam);


	while ( n > 0) {

		write(1,buffer,n);
		n = read(0,buffer,tam);

		if (n <= 0) return 0;
	}


}