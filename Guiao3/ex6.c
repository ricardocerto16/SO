#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

//system("ls -l");
int mysystem( char * comando ) {

	char * string;
	char * exec_args[20];
	int i = 0;
	int resfork, execution, espera, status, res;

	string = strtok(comando," ");

	while(string != NULL) {
		exec_args[i] = string;
		string = strtok(NULL," ");
		i++;
	}

	exec_args[i] = NULL;


	resfork = fork();
	if(resfork == 0) { // filho

		execution = execvp(exec_args[0],exec_args);
		_exit(execution);
		// o exit retorna o valor do exec dizendo se correu bem ou não
	}
	else {
		if( resfork != -1) { // PAI

			// espera que o pai execute
			espera = wait(&status);

			
			if(WIFEXITED(status)){
				res = WEXITSTATUS(status);
			}
			else {
				res = -1;
			}
		}

		else {
			res = -1;
		}
	}
	return res;
}

int main(int argc, char const *argv[]){
	
	char comando1[] = "ls -l -a -h";
	char comando2[] = "sleep 10";
	int ret1, ret2;

	printf("A executar o comando: %s\n",comando1);
	ret1 = mysystem(comando1);
	printf("RETURN: %d\n", ret1);


	printf("A executar o comando: %s\n",comando2);
	ret2 = mysystem(comando2);
	printf("RETURN: %d\n", ret2);


	return 0;
}