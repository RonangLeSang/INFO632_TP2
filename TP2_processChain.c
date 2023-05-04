#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  
  int n = atoi(argv[1]);
  int i;
  pid_t pid;

  printf("Parent process : (PID %d)\n", getpid());
  
  for (i = 0; i < n; i++) {
    pid = fork();
    
    if (pid < 0) {
      fprintf(stderr, "erreur\n");
      exit(1);
    } else if (pid == 0) {
      printf("Child process %d (PID %d)\n", i+1, getpid());
      sleep(5); // modifier ici pour avoir le temps de faire pstree
    } else {
      wait(NULL);
      exit(0);
    }
  }
  
  return 0;
}
