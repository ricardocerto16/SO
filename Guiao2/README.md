# Guião 2


## Chamadas ao Sistema:


* pid_t getpid();


Retorna o id do processo atual.

* pid_t getppid();


Retorna o id do processo pai do processo atual. Esse id de processo vai ser o mesmo do que o id que criou o processo atual usando o fork(). 

* pid_t fork();


Cria um novo processo contendo todo o espaço de memória igual ao do pai, mas que a partir desse momento as memórias de cada um passam a ser idependentes. 
Se o resultado for negativo o processo de criação do filho não foi bem sucedida, se o resultado for zero corresponde ao processo filho e se o resultado for um valor positivo corresponde ao processo pai (criador).

* void _exit(int status);


Usamos o _exit para abortarmos a execução do processo filho, de forma a esse processo não interferir nos dados externos do processo pai (principalmente para quando usamos execs).

* pid_t wait(int *status);


Suspende a execução do processo atual até que um dos seus filhos termine a sua execução.

* pid_t waitpid(pid_t, int *status, int options);


wait() é equivalente a waitpid(-1,&status,0);


Suspende a execução do processo atual até que que um filho especificado pelo argumento status pid.
Os valores possiveis de pid são os seguintes:
** <-1 significa esperar por qualquer processo filho cujo ID do grupo de processos seja igual ao valor absoluto de pid .
** -1 significa esperar por qualquer processo filho.
** 0  significa esperar por qualquer processo filho cujo ID do grupo de processos seja igual ao do processo de chamada.
** > 0 significa esperar pela criança cujo ID do processo é igual ao valor de pid .


* int WIFEXITED(int status);


Retorna true se o filho terminar normalmente, isto é, chamando exit (3) ou _exit (2) ou retornando de main ().

* int WEXITSTATUS(int status);


Retorna o status de saída do filho. Isso consiste nos 16-8 bits menos significativos do argumento de status que o filho especificou em uma chamada para exit () ou _exit () ou como o argumento para uma instrução de retorno em main (). Essa macro só deve ser usada se WIFEXITED retornar true.


Exemplo de utilização:


´´
if(WIFEXITED(status)){
				res = WEXITSTATUS(status);
			}
´´