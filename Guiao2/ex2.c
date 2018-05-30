#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main( int argc , char **argv) {

	pid_t pid = fork();
	if(pid == 0){
		printf("Sou o processo filho e o meu pid é %d, o do meu pai é %d\n", getpid(),getppid());
		if(getppid() == 1)
			printf("Fiquei orfão\n");
	}
	else
		printf("Sou o pai e o meu pid é %d, o do meu pai é %d e o do meu filho é %d\n", getpid(), getppid(),pid);
}


