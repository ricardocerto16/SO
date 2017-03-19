#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


// int system(const char *comand) 
// executa um comando como fosse o terminal

int mysystem(char *comando){

	int fork_t , exec_t , wait_t , status , res;

	// assumindo que o nr max de args é 20
	// doutra forma tinhamos que fazer realloc
	char *exec_args[20];
	char *string;
	int i = 0;

	// strtok -> parte uma string dada uma partição
	string = strtok(comando," ");

	while(string!=NULL) {
		exec_args[i] = string;
		string = strtok(NULL," ");
		i++;
	}

	exec_args[i] = NULL;

	fork_t = fork();
	if( fork_t == 0) {

		exec_t = execvp(exec_args[0],exec_args);
		_exit(exec_t);
	}
	else {
		if(fork_t!=-1){

			wait_t = wait(&status);

			if(WIFEXITED(status)) {
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






int main(int argc , char *argv[]){

	char comando1[] = "ls -l -a -h";
	char comando2[] = "sleep 10";
	char comando3[] = "ps";
	int ret;

	printf("A executar o mysystem para %s\n", comando1 );
	ret = mysystem(comando1);
	printf("ret : %d \n",ret);

	printf("A executar o mysystem para %s\n", comando2 );
	mysystem(comando2);

	printf("A executar o mysystem para %s\n", comando3 );
	mysystem(comando3);

	return 0;
}

