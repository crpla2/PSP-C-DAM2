#include <unistd.h> //excel
#include <stdlib.h> //system

int main(int argc, char const *argv[])
{
  //  execl("/usr/bin/firefox", "firefox","https://educa.aragon.es" ,NULL);
   //  system("/usr/bin/firefox");
  //system("ls -l > ls.txt");

  char*v[]={"firefox","https://educa.aragon.es",NULL};
  execv("/usr/bin/firefox",v);

    return 0;
}
