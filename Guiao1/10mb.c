#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// EXERCÍCIO 2 -> GUIÃO 1

// programa que cria um ficheiro com 10MB cujo
// nome é passado como argumento

int main(int argc, char const *argv[]) {
	
	char carac = 'a';
	int descritor = open(argv[1],O_CREAT | O_RDWR);
	int x;

	if (descritor < 0) {
		printf("ERRO AO CRIAR FICHEIRO\n");
	} 


	for(int i = 0 ; i < 10000000 ; i++) {

		x = write(descritor,&carac,1);
		if (x != 1) exit(1);
	}

	close(descritor);
	return 0;
}