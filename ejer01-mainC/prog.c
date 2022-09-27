#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
/*  En la consola:
compilar => gcc prog.c -o prog.exe
"man" para ver el manual*/
int main(int argc, char const *argv[]) 
{
//  Para que se repita un proceso(procesos paralelos):
    fork();
    fork();
//  Para imprimir los argumentos con que se ejecuta un programa(el primero es el nombre del programa)
//  printf("Número de argumentos: %d. Primer argumento: %s \n", argc, argv[0]);

//  Para impprimir el número de identificación de un proceso y su padre
    printf("Mi PID es: %d y mi padre es: %d\n", getpid(),getppid());
    return 0;
}
