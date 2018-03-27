## Guião 01:

### Funções usadas:

* int     open(const char*path, int oflag [, mode]);
open -> serve para abrir um ficheiro com as devidas permissões
returns -> retorna -1 em caso de insucesso em caso de sucesso retorna um descritor desse ficheiro


* ssize_t read(int fildes, void*buf, size_t nbyte);
read -> serve para ler um ficheiro
returns -> retorna o nº de bytes lidos ou -1 em caso de erro

* ssize_t write(int fildes, const void *buf, size_t nbyte);
write -> serve para escrever no ficheiro
returns -> retorna o nº de bytes escritos ou -1 em caso de erro

* int  close(int fildes);
close -> fecha um ficheiro



#### Standart Inputs/Outputs

stdin -> 0 -> Teclado


stdout -> 1 -> Monitor
