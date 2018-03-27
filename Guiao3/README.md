# Guião 3

## Chamadas ao Sistema:

* int execl(const char *path, const char *arg0, ..., NULL);


execl("/bin/ls","ls","-l",NULL);


Executa uma system call de tamanho conhecido, no final do seus argumentos temos de por NULL, para sabermos quando termina. Nesta função de exec também precisamos de passar a path do executável como podemos verificar no exemplo em cima.

* int execlp(const char *file, const char *arg0, ..., NULL);


execlp("ls","ls","-l",NULL);


Esta chamada de sistema não necessita que seja indicado o caminho para o executável. Executa uma system call de tamanho conhecido, no final do seus argumentos temos de por NULL, para sabermos quando termina.


* int execv(const char *path, char *const argv[]);


Executa uma lista de parametros aonde temos de passar a diretoria do executável como argumento.


* int execvp(const char *file, char *const argv[]);


Executa uma lista de parametros aonde não é necessário passar a diretoria do executável como argumento.


execl -> temos de indicar o path para o comando


execlp -> procura o ficheiro que queremos


execlp(executável,args ...)


Depois do exec não é executado mais nada, normalmente usamos os execs no processo filho para o processo pai não ser matado.


wait retorna o pid do processo