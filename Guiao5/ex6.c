#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>



int myopen (char* comando , char* modo){

	int dir = (strcmp(modo,"w") == 0), fd[2];
	pipe(fd);

	if(fork() == 0){

		close(fd[dir]);
		dup2(fd[1-dir],1-dir);
		close(fd[1-dir]);

		//execlp("sh","sh","-c","wc","-l",NULL);
		execlp("sh","sh","-c",comando,NULL);
		_exit(1);
	}

	wait(NULL);
	close(fd[1-dir]);

	return fd[dir];
}



int main(int argc, char *argv[]){

	//int f = myopen("wc -l","w");
	int f = myopen("ls","w");
	printf("%d\n",f);
	close(f);
	return 0;

}