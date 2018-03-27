#include <unistd.h>

/*
int execl(const char *path, const char *arg0, ..., NULL);
int execlp(const char *file, const char *arg0, ..., NULL);
int execv(const char *path, char *const argv[]);
int execvp(const char *file, char *const argv[]);
*/

// execl -> temos de indicar o path para o comando
// execlp -> procura o ficheiro que queremos

// execlp(executável,args ...)


// execlp("ls","ls","-l",NULL);
// execl("/bin/ls","ls","-l",NULL);

// depois do exec não executa mais nada

// wait retorna o pid do processo

int main(int argc, char const *argv[]){
	
	execlp("ls","ls","-l",NULL);

	return 0;
}