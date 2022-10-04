#include <sys/types.h>
#include <unistd.h>//Fork Sleep, Wait
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>

void manejadorSenyal(int numSenyal);

int main(int argc, char const *argv[]) 
{
    pid_t padre;
    padre=fork();
    
    if(padre==0)
    {//Soy el hijo
        printf("Hola soy el hijo: %d y voy a matar a papa\n",getpid());
        sleep(1);
        kill(getppid(),SIGUSR1);
        
    }else{//soy el padre
        signal(SIGUSR1,manejadorSenyal);
        printf("[PADRE]: Me quedo esperando la señal de hijo.\n");
        pause(); 
        int estado;
        printf("[PADRE]: Me quedo esperando la finalización de hijo.\n");
        padre=wait(&estado);//"padre" ahora tiene el pid del hijo
        printf("Un hijo %d ha terminado con estado: %d\n",padre,WEXITSTATUS(estado) );
    }
    
    return 0;
}

void manejadorSenyal(int numSenyal)
{
    printf("He recibido una señal numero:%d\n",numSenyal);
}
