#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]){
	
	int i, status;

	for(i = 1 ; i < argc ; i ++) {

		if(fork() == 0){
			execlp(argv[i],argv[i],NULL);
		}
		else{
			wait(&status);
		}
	}
	return 0;
}