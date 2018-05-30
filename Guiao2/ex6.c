#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#define C 10
#define L 5



int matriz[C][L];


int main( int argc , char **argv) {

	int j = 0 , i = 0;
	int k = 0;
	int status[C];
	int filho;

	if(argc > 1) {

		for(i=0;i<C;i++){
			for(j=0;j<L;j++) {

				matriz[i][j] = rand() % 10;
			}
		}

		int nr = atoi(argv[1]);

			for(k=0;k<C;k++){
				filho = fork();

				if(filho == 0) {

					for(j=0;j<L;j++){

						if(matriz[k][j] == nr){
							_exit(1);
						}
					}
					_exit(0);
				}

				else { waitpid(filho,&(status[k]),0); }
			}	

			i = 0;

			while(i<C){
				printf("o filho %d %s\n", i, WEXITSTATUS(status[i])==1?"encontrou":"não encontrou");
	        	
	        	if(WEXITSTATUS(status[i])==1) {
                         
                         printf("Linha  %d\n",i);
                     }		

                  i++;
              }
	}

	else printf("Introduza um numero\n");

	return 0;

}


/* VERSÃO ALTERNATIVA
void ex6(int x){
	srand(time(NULL));
	int matriz[4][100000];
	pid_t pids[4];
	int i, j,r=0, status;
	for ( i = 0; i < 4; i++) {
		for ( j = 0; j < 100000; j++) {
			matriz[i][j] = rand() % 200;	
		}
	}
	for ( i = 0; i < 4; i++) {
		pids[i] = fork();
		if(pids[i]==0){
			for ( j = 0; j < 100000; j++) {
				if(matriz[i][j] == x)	
					r++;
			}
			printf("(Filho %d encontrou %d %d\n", i, r, x);
			exit(r);
		}
	}
	for(i=0; i<4;i++){
		waitpid(pids[i],&status,0);
		printf("(Filho %d encontrou %d %d\n", i, WEXITSTATUS(status), x);
	}
}
*/
