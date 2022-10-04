#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>// atoi, exit

int main(int argc, char const *argv[])//argc: numero de argumentos argv:vector de argumentos  argv[0]:nombre del programa
{
    if(argc != 2){
        fprintf(stderr,"Error, el programa debe de tener un parametro.\n\n");
        fprintf(stdout,"Uso del programa:\n\t %s <num_pid> \n\n", argv[0]);
        exit(-1);
    }
    pid_t pidParametro= atoi(argv[1]);

    kill(pidParametro,SIGUSR1);
    return 0;
}

