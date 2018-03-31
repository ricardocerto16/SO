#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>



FILE * myopen (char* comando , char* modo){

	int dir = (strcmp(modo,"w") == 0), fd[2];
	pipe(fd);

	if(fork() == 0){

		close(fd[dir]);
		dup2(fd[1-dir],1-dir);
		close(fd[1-dir]);

		execlp("sh","sh","-c",comando,NULL);
		_exit(1);
	}

	close(fd[1-dir]);

	return fdopen(fd[dir],modo);
}



int main(int argc, char *argv[]){

	FILE *p = myopen("wc -l","w");
	fprintf(p, "OLA\n");
	fclose(p);

	return 0;

}