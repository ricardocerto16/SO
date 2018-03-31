#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/*
Programa que executa a seguinte instrução:
grep -v ^# /etc/passwd | cut -f7 -d: | uniq | wc -l
Cada | significa um pipe diferente, e o pipe de mais baixa hirarquia 
(o filho que não é pai de ninguém começa por executar o 1º comando).
*/

int main(int argc, char *argv[]){

	int fd1[2] , fd2[2] , fd3[2];

	pipe(fd1);

	if( fork() == 0) {

		close(fd1[0]);
		pipe(fd2);
		

		if(fork() == 0){

				close(fd2[0]);
				pipe(fd3);

				if(fork() == 0) {

						close(fd3[0]);
						dup2(fd3[1],1);
						close(fd1[1]);

						execlp("grep","grep","-v","^#","/etc/passwd",NULL);
						_exit(1);
				}


				dup2(fd3[0],0);
				close(fd3[0]);
				close(fd3[1]);
				dup2(fd2[1],1);
				close(fd2[1]);
				wait(NULL);

				execlp("cut","cut","-f7","-d:",NULL);
				_exit(1);
		}


		dup2(fd2[0],0);
		close(fd2[0]);
		close(fd2[1]);
		dup2(fd1[1],1);
		close(fd1[1]);
		wait(NULL);

		execlp("uniq","uniq",NULL);
		_exit(1);
	}
	else {

		wait(NULL);
		close(fd1[1]);
		dup2(fd1[0],0);


		execlp("wc","wc","-l", NULL);
		_exit(1);
	}


	return 0;
}