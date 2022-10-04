#define N_HIJOS 150
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    for (int i = 0; i < N_HIJOS; i++)
    {
       if (fork()==0)
       {//codigo de los hijos
        printf("Hola soy el hijo numero: %d.\n",getpid());
        sleep(1);
        return i;       
       }
    }
    int estado;
    int pidHijo;
    for (int i = 0; i < N_HIJOS; i++)   
    {       
        pidHijo=wait(&estado);
        printf("El hijo %d ha finalizado con valor de retorno %d\n",pidHijo,WEXITSTATUS(estado));
        
    }
    
  
    return 0;
}
