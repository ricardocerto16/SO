#include <unistd.h>
#include <stdio.h>


int main(int argc, char const *argv[]){

	int x;
	x = fork();
	if( x == 0) {
		execlp("ls","ls","-l",NULL);
		//printf("FILHO\n");
	}


	return 0;
}