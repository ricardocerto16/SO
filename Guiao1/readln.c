#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

// 0 -> SDTIN (teclado)
// 1 -> STDOUT (ecra)

// EXERCÍCIO 5 -> GUIÃO 1

// linha de leitura da função readln cujo protótipo
// é compatível com a chamada ao sistema read,
// nesta versão lê um caractere de cada vez


int readlinha(int descritor , char *buffer, int max){

	int n , i = 0;

	for(i = 0 ; i < max - 1 ; i++){

		n = read(descritor,buffer+i,1);
		if (n == 0)  {
			//printf("ERRO : ERRO NA LEITURA DA LINHA\n");
			return 0;
		}
		if (buffer[i] == '\n') return i;
	}
	return i;
}


int main(int argc, char *argv[]){
	
	char *buffer; 
	int nbytes;
	int leitlinha;

	if (argc != 1) {
		printf("ERRO: Nº DE ARGUMENTOS INVÀLIDOS\n");
	}

	buffer = malloc(256);

	while(1) {

		leitlinha = readlinha(0,buffer,256);

		write(1,buffer,leitlinha);

		if (leitlinha == 0)  {
			//printf("ERRO : ERRO NA LEITURA DA LINHA\n");
			return 0;
		}

	}
	free(buffer);
	return 0;
}