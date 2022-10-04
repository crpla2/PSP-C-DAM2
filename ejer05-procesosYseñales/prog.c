#include <sys/types.h>
#include <unistd.h>//Fork Sleep, Wait
#include <stdio.h>
#include <signal.h>

void manejadorSenyal(int numSenyal);

int main(int argc, char const *argv[])
{
    signal(SIGUSR1,manejadorSenyal);// señal que le voy a mandar
    signal(SIGUSR2,manejadorSenyal);// señal que le voy a mandar
    printf("PID: %d\n",getpid());
   // sleep(20);//paramos 20 seg para darnos tiempo a ver la señal
    pause();//para indefinidamente
    return 0;
} //kill SIGUSR1 (PID) para mandar la señal

void manejadorSenyal(int numSenyal)
{
    printf("He recibido una señal numero:%d\n",numSenyal);
}
