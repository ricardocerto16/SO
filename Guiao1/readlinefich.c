#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

// EXERCÍCIO 6 -> GUIÃO 1

// linha de leitura da função readln cujo protótipo
// é compatível com a chamada ao sistema read,
// nesta versão lê um caractere de cada vez e
// suporta a leitura de ficheiros



/*
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
*/

int readlinha(int fildes, char *buf, size_t nbyte){
    int i=0;

    while(i <nbyte-1 &&
         read(fildes, buf+i,1)>0 &&
         buf[i] != '\n'){
         i++;
    }
    if(i >= nbyte)
           buf[i] = 0;
    else
           buf[i+1] = 0;

    return i;
}

int main(int argc, char const *argv[]){

	int descritor, i=1, c;
	char n = '\n';
	char buff[128];
	char l[10];

	if(argc == 2) descritor = open(argv[1],O_RDONLY);
	else if (argc == 1) descritor = 0;
	else printf("ERRO: Nº ARGUMENTOS\n");


	while((c = readlinha(descritor,buff,128)) > 0){
		write(1,l,sprintf(l,"\n   % d   -> \t",i));
		write(1,buff,c);
		i++;
	}

	printf("\n\n");
	return i;
}