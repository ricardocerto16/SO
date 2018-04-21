# Guioes 6:

# Pipes com nome:

* int mkfifo (const char *pathname, mode_t mode);
* fd[0] -> leitura (output)
* fd[1] -> escrita (input) 


Os pipes com nome possuem um bloqueio extra, e só começam a executar quando existe um par de leitura/escrita.


# Abertura do pipe:
A abertura do pipe é feita com o comando open especificando o modo de abertura do pipe, dizendo por exemplo se é para leitura ou para escrita, como podemos ver no seguinte exemplo:
* op = open("pipe",O_RDONLY);


# Fecho do pipe:
Para fecharmos o pipe usamos o close com o descritor do pipe que queremos fechar. Exemplo:
* close(op)




                      ______________

                   
          _(pfd[1])->|____PIPE______|->(pfd[0])_ 
         

         /                                      \
        

        |                                        |
    

    write()   									read()
