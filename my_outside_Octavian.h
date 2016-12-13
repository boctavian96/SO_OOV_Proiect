#include<sys/wait.h>

void help_outside()
{
  printf("---> Octavian Bodnariu outside <---\n");
  printf("outside poate primi orice comanda din terminalul Linux\n");
}

int my_outside(char** argumente)
{
  if(strcmp(argumente[1], "-h") == 0)
  {
    help_outside();
  }
  int pid;
  int status;

  pid = fork();

  if(pid == 0)
  {
    execvp(argumente[1], &argumente[1]);
  }
  else
  {
    waitpid(pid, &status, WUNTRACED);
  }
  execv(*argumente, ++argumente);
return 1;
}
