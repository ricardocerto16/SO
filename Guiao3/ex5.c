#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h> 

int main (int argc , char * argv[]) {
	int i;
	int x = fork();
	//char a[10];

	for(i = 0; i < argc ; i++){
		if (x == 0) { // código filho
			//a[i] = argv[i];
			execlp("ls","ls","-l",NULL);

	 	}
		else { // código pai


		}
	 }
  return 0;
}