#include <unistd.h>
#include <stdio.h>


int main(int argc, char const *argv[]){
	
	int i;

	for (i = 0 ; i < argc ; i++ ){
		printf("Arg %d -> %s \n",i,argv[i]);
	}

	return 0;
}