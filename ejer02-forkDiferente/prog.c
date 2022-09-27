#include <stdio.h>      //printf
#include <unistd.h>     //fork, sleep, wait
#include <sys/types.h>  //pid_t
#include <sys/wait.h>   //wait

int main(int argc, char const *argv[]){
    pid_t numPid;
    int num=12;
    
    numPid=fork();  //se gneneran 2 procesos padre e hijo
    if (numPid==0){ //proceso hijo devolerá cierto y entrará en el if.
        printf("Soy el hijo mi pid es %d\n",getpid());
        num=15;     //cambiamos el valor a la variable en el proceso hijo
        sleep(1);   //el hijo espera un segundo

    }else{
        printf("soy el padre, mi pid es: %d\n", getpid());
        int estado;//declaro un entero donde el wait guarda la información sobre el retorno
        pid_t pidFinalizado=wait(&estado);//'&' sirve para pasar la dirección de memoria  de estado no una copia del mismo
  //2   pid_t pidFinalizado=wait(NULL);//El padre espera al hijo y asigna el valor de retorno a una variable
  //1   wait(NULL);//el padre espera al hijo
  //2   printf("El hijo con pid: %d finalizó\n",pidFinalizado);
        printf("El hijo con pid: %d finalizó con estado %d, el valor de estado es %d\n",
                                                pidFinalizado,WEXITSTATUS(estado),estado);
        // el valor de estado no tiene ningún sentido prático ya que en todos los bits de ese entero el wait codifica
        // diferentes datos que nos dan información sobre la finalización de ese proceso.
        sleep(1);
    }
    printf("Hola, num es: %d\n",num);
   
    return 23;
}
