#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>


//int dup(int fd);
//int dup2(int fd1, int fd2);


//dup2(origem,destino)

int main(int argc, char const *argv[]){

	int fdin = open("/etc/passwd",O_RDONLY);
	int fdout = open("saida.txt",O_CREAT | O_WRONLY | O_TRUNC, 0666);
	// adicionamos a flag 0666, para podermos trabalhar com o ficheiro
	int fderr = open("erros.txt" ,O_CREAT | O_WRONLY | O_TRUNC, 0666);
	
	int din , dout , derr;
	int r, f;
	char buffer[128];


	din = dup2(fdin,0);
	if (din < 0) perror("Erro no dup do passwd");

	dout = dup2(fdout,1);
	if (dout < 0) perror("Erro no dup do out");

	derr = dup2(fderr,2);
	if (derr < 0) perror("Erro no dup do err");


	f = fork();
	if (f == 0){
		execlp("wc","wc",NULL);
	}
	
	close(fdin);
	close(fdout);
	close(fderr);

	return 0;
}