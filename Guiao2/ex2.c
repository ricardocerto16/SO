#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main( int argc , char **argv) {

		int x;
		x = fork();
		if (x == 0) {
			printf("filho: %d\n", getpid());
		}
		else {
			printf("pai: %d\n",getpid());
			wait(NULL);
		}
}


