#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

// EXERCÍCIO 3 -> GUIÃO 1

// função alternativa de cat que permite escolher quantos 
// bytes queremos que sejam lidos de cada vez

int main(int argc, char const *argv[]){
	
	if (argc < 0) return -1;

	int desc;
	int w;
	int nbytes = atoi(argv[1]);
	char buff[nbytes];

	desc = read(0,&buff,nbytes);

	while( desc > 0){

		w = write(1,&buff,nbytes);
		if (a != nbytes) exit(1);

		desc = read(0,&buff,nbytes);
	}

	return 0;
}

/*
versão alternativa que permite escolher quantos 
bytes queremos que sejam lidos de cada vez

int main(int argc, char** argv){
    int n;
    int N = atoi(argv[1]);
    char* buffer = malloc(N);

    while ((n=read (0, buffer, N)) >0){
         write (1, buffer, n);
  }
}
*/