# Guião 5

## PIPES:


    pfd[0]-> leitura (output)

    
    pfd[1]-> escrita (input)


                      ______________
          _(pfd[1])->|____PIPE______|->(pfd[0])_ 


         /                                      \


        |                                        |


    write()                                   read()


0 -> Standard input 	    stdin 	 Keyboard


1 -> Standard output 		stdout 	 Screen


2 -> Standard error 	    stderr 	 Your screen


### Leitura e escrita pipes
A leitura de um pipe é feita usando o pfd[0] e a escrita é feita usando o fdp[1].


Por exemplo quando queremos apenas escrever/ler de um pide devemos fazer close da saída de leitura/escrita, de modo ao conteúdo a ser escrito ou a ser lido não possa ser alterado.
(Em alguns momentos um processo vai escrever em algum lado, e o outro não deve fazer nada, além de esperar.) Tem que existir um sicronismo ao nível do pipe para saber quando processo deve agir.



### Deadlock:
Deadlock (interbloqueio, blocagem, impasse), no contexto de sistemas operacionais (SO), refere-se a uma situação em que ocorre um impasse, e dois ou mais processos ficam impedidos de continuar suas execuções - ou seja, ficam bloqueados, esperando uns pelos outros. 