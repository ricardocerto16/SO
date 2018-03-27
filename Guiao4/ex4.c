#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>


//int dup(int fd);
//int dup2(int fd1, int fd2);


//dup2(origem,destino)

int main(int argc, char *argv[]){

	int dp1, dp2;
	int icmd = 1;
	int fdout, fdin;
	


	if ((strcmp(argv[1],"-i") == 0) && (strcmp(argv[3],"-o") == 0)) {
	    fdout = open(argv[2],O_RDONLY | O_TRUNC, 0666);
	    fdin = open(argv[4],O_RDONLY | O_TRUNC, 0666);
		dp1 = dup2(fdout,0);
		dp2 = dup2(fdin,1);
		icmd = 5;	
	}
	else if ((strcmp(argv[1],"-i") == 0)) {
		fdout = open(argv[3],O_CREAT | O_WRONLY | O_TRUNC, 0666);
		dp1 = dup2(fdout,0);
		icmd = 3;
	}
	else if ((strcmp(argv[1],"-i") == 0)) {
		fdout = open(argv[3],O_CREAT | O_WRONLY | O_TRUNC, 0666);
		dp2 = dup2(fdout,1);
		icmd = 3;
	}


	int f = fork();
	if (f == 0)
		execvp(argv[icmd],&argv[icmd]);

	return 0;

}