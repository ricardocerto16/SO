# Guião 4


0 -> standart input


1 -> standart output


2 -> standart error


dup2(origem,destino)


## Chamadas ao sistema:


* int dup(int fd);


A chamada ao sistema dup cria uma cópia do descritor de arquivos oldfd, usando o descritor não usado de numeração mais baixa para um novo descritor.


* int dup2(int fd1, int fd2);


A chamada do sistema dup2 () executa a mesma tarefa que dup (), mas em vez de usar o descritor de ficheiro de numeração mais baixa, ele usa a descritor de ficheiro especificado no newfd.


Se o descritor newfd foi previamente aberto, é silenciosamente fechado antes de ser reutilizado.





* dup2(fd,0);
redirecionar o std input para o ficheiro que tem fd como descritor de ficheiro. fd é o resultado de fazer um open ao ficheiro.
	