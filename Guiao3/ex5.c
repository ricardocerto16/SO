#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h> 
<<<<<<< HEAD

int main (int argc , char * argv[]) {
	int i;
	int x = fork();
	//char a[10];

	for(i = 0; i < argc ; i++){
		if (x == 0) { // código filho
			//a[i] = argv[i];
			execlp("ls","ls","-l",NULL);

	 	}
		else { // código pai


		}
	 }
=======
#include <fcntl.h>

int main (int argc , char * argv[]) {
	
	int fork_f , exec_f , i;

	// TODO : o i tem de começar em 1
	for(i=1; i<argc; i++){

		fork_f = fork();

		if(fork_f == 0) { // filho

			printf("Sou o filho %d e vou executar o comando %s\n",getpid(),argv[i]);


			exec_f = execlp(argv[i],argv[i],NULL);

			perror("Erro na execução");

			// terminar a execução do filho
			_exit(exec_f);
		}
	}

	for(i=1;i<argc;i++) {
		printf("Sou o processo pai estou á espera da execução dos meus filhos\n");
		wait(NULL);
	}

	printf("Todos os filhos foram executados\n");
	_exit(1);

>>>>>>> f6ab6d2db0a195ee9d9d864978236fc88e8a4cab
  return 0;
}