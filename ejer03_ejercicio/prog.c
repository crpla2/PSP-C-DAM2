#include <stdio.h>      //printf
#include <unistd.h>     //fork, sleep, wait
#include <sys/types.h>  //pid_t
#include <sys/wait.h>   //wait

int main(int argc, char const *argv[]){
    pid_t padre,hijo1,hijo2;
    padre=getpid();
    hijo1=fork();  
    if (hijo1==0){ 
        printf("Soy el hijo1 mi pid es %d\n",getpid());
        return 1;  

    }else{
        printf("soy el padre, mi pid es: %d, mi hijo1 ha sido creado su pid es %d\n",padre,hijo1);
        hijo2=fork();
            if (hijo2==0){ 
               printf("Soy el  hijo2 mi pid es %d\n",getpid());
                return 2;
                }else{
                    int estado;
                    pid_t hijofinalizado;
                    printf("Sigo siendo el padre, mi pid es: %d, mi hijo2 ha sido creado su pid es %d\n",padre,hijo2);
                   for (int i = 0; i < 2; i++)
                   {
                        hijofinalizado=wait(&estado);
                        printf("Un hijo ha finalizado con pid %d y con estado %d\n",hijofinalizado,WEXITSTATUS(estado));
                   }
                   
                
                }
        
    }
    printf("Hola");
   
    return 0;
}
