#include <unistd.h>

int main ( ){


	execlp("ls","ls","-l",NULL);

	return 0;
}