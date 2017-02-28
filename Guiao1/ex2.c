#include <unistd.h> 
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc , char **argv) {

	int descritor, i;
	char a = 'a';

	if (argc =! 2) { // temos de passar 2 args obrigatoriamente
		printf("ERROR\n");
		return 1;
	}

	
	// ver o que significa o 640

	descritor = open (argv[1], O_CREAT | O_TRUNC | O_WRONLY, 0640);

	for (i=0;i<10000000;i++){
		write (descritor,&a,1);
	}

	close (descritor);

}