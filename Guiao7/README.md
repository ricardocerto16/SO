# Sinais

* **signal(SINAL,handler)** => associa o handler ao SINAL. Alguns sinais como SIGKILL e SIGSTOP, não podem ser alterados.
* **kill(pid_do_processo, SINAL)** => envia um sinal para um processo.
* **raise(sinal)** =>  envia um sinal para o próprio processo (também se pode conseguir o mesmo objectivo utilizando a função kill).
* **pause()** => suspende o processo corrente até à chegada de um sinal (assim não "gasta" tempo de CPU, por não estar escalonado).
* **alarm(n)** => envia ao processo invocador um sinal SIGALRM dentro de n segundos, mesmo que este não esteja a ser executado.


É o modo mais simples de comunicação entre processos. Funcionam como interrupções de software.


Cada sinal tem associado a si um handler - uma função que é executada quando um sinal é recebido por um processo. Esse handler pode ser alterado pelo utilizador. Os sinais são utilizados para o tratamento de excepções e de acontecimentos assíncronos.




### Processos:
O processo destino ao receber o sinal executa o handler que foi associado ao sinal, originando um desvio do programa principal;


No fim do handler o CPU continua a execução do programa no ponto onde ficou;


Logo que um sinal é enviado e recebido, o handler default é novamente associado a esse sinal;


Só é possível enviar sinais a processos com mesmo uid (User IDentification).


kill(0,SINAL) - envia o sinal <SINAL> a todos os processos do mesmo uid do processo actual.


### Sinais mais Utilizados:

* **SIGSTOP** => bloqueia um processo.
* **SIGCONT** => desbloqueia um processo se estiver bloqueado.
* **SIGKILL** => mata um processo.
* **SIGUSR1** => sinal para ser usado pelo utilizador.
* **SIGUSR2** => sinal para ser usado pelo utilizador.
* **SIGINT** => interrupção do terminal (gerado pela tecla DEL ou Break)
* **SIGHUP** => terminal desligado.
* **SIGQUIT** => abortar a execução.
* **SIGILL** => instrução ilegal.
* **SIGTERM** => terminação ordenada do processo.
* **SIGCHLD** => sinal que um processo recebe quando um filho morre (através do exit).
* **SIGALRM** =>  manda o sinal SIGALRM (de alarme) a um processo.
