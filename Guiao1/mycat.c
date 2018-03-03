#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#define TAM 100

// EXERCÍCIO 1 -> GUIÃO 1

// Programa similar ao comando da bash cat, quê lê 
// um caracter de cada vez

int main(int argc, char const *argv[]){
	
	if (argc < 0) return -1;

	int desc;
	int w = 0;
	char c;

	desc = read(0,&c,1);

	while( desc != -1){

		w = write(1,&c,1);
		if (w == -1) exit(1);

		desc = read(0,&c,1);
	}

	return w;
}


// versão alternativa
// que lê tudo de uma só vez
/*
int altmycat (int argc, char **argv) {

	char buff[TAM];
	int n;

	if (argc !=1) { // permite apenas passarmos um argumento 
		return 1;
	}

	while ((n = read (0,buff,TAM)) > 0) {
		write (1,buff,TAM);
	}

	return 0;
}
*/