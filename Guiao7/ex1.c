#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>


// Kill pode matar um processo mas também pode enviar
// um sinal para outro processo

//  typedef void (*sighandler_t)(int);
//  sighandler_t signal(int signum, sighandler_t handler);
//  int kill(pid_t pid, int sig);
//  unsigned int alarm(unsigned int seconds);
//  int pause(void);


static int conta;
static int tempo;


void my_alarm(int x){
	tempo ++;
	alarm(1); // envia ao processo que o invocou um alarme dentro de 1 segundo
}


void print_sair(){
	printf("\t nº vezes: %d \n", conta);
	_exit(0);
}


void ctrlC(){
	conta++;
	printf("\t time: %d\n", tempo);
}


int main(int argc, char *argv[]){

	int n;
	conta = 0;
	tempo = 0;

	signal(SIGALRM,my_alarm);    // SIGALRM -> manda o sinal SIGALRM a um processo
	signal(SIGINT,ctrlC);        // SIGINT -> interrupção do sinal
	signal(SIGQUIT,print_sair);  // SIGQUIT -> aborta a execução
	alarm(1);

	while(1){ pause(); } // pause -> suspende o processo até receber um sinal

	return 0;
}