#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/*
    pfd[0]-> leitura (output)
    
    pfd[1]-> escrita (input)

                      ______________
          _(pfd[1])->|____PIPE______|->(pfd[0])_ 
         /                                      \
        |                                        |
    write()                                   read()
*/

/*
0 -> Standard input 	    stdin 	 Keyboard
1 -> Standard output 	stdout 	 Screen
2 -> Standard error 	    stderr 	 Your screen
*/

int main(int argc , char* argv[]) {

	int fd[2];
	int fk;
	char stg[1024];
	int n;
	pipe(fd); 

	 fk = fork();
	 if(fk == 0) {
	 	close(fd[0]); // fechar a leitura ao filho pois só vai ler
	 	
	 	//sleep(5);

	 	write(fd[1],"filho ",6);
	 	write(fd[1],"123 ",4);	


	 }
	 else {
	 	if(fk==-1) {perror("ERRO NO FORK"); return 1;}
	 	else {

	 		close(fd[1]); // fechar a escrita ao pai pois só vai escrever
	 	
	 		while((n=read(fd[0],stg,1)) > 0) {

	 			//sleep(5);
	 			printf("%c\n",stg[0]);
	 		}

	  }
	 }


	return 0;
}
