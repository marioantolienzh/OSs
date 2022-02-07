#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
  pid_t pid, pid2;
  /* fork a child process */

  pid = getpid();
  printf("pid1 PID: %d\n", pid);
  printf("-----------------------------\n");
  pid = getppid();
  printf("pid1 PPID: %d\n", pid);
  printf("-----------------------------\n\n");

  pid = fork(); //prints all the parent PIDs

  if (pid < 0) { /* error occurred */
    fprintf(stderr, "Fork Failed");
    return 1;

  } else if (pid == 0) { /* child process */
    /* execlp("/bin/ls","ls","-s","/tmp",NULL); */
    for (int i=1; i<10; i++){
      printf("%d ",i);
    }
    fflush(stdout);
    printf("Child Complete\n");

  } else { /* parent process */
    /* parent will wait for the child to complete */
    for (int i=11; i<50; i++) {
      printf("%d ",10*i);
      fflush(stdout);
    }
    wait(NULL);
    pid2 = fork();
    pid2 = fork();
    printf("Parent Complete\n");
    //there are 2^n where n is the # of forks, (4) child processes => 4 printf "parent complete"
  }
  return 0;
}
