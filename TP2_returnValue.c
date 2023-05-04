#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  pid_t pid;
  int status, child_value;
  
  pid = fork();
  
  if (pid < 0) {
    fprintf(stderr, "Failed to create child\n");
    exit(1);
  } else if (pid == 0) {
    printf("Child (PID %d) running\n", getpid());
    int value;
    printf("entrer valeur : ");
    scanf("%d", &value);
    exit(value);
  } else {
    printf("Parent (PID %d) waiting for child (PID %d)\n", getpid(), pid);
    wait(&status);
    if (WIFEXITED(status)) {
      child_value = WEXITSTATUS(status);
      printf("Parent (PID %d) received value %d from child (PID %d)\n", getpid(), child_value, pid);
    } else {
      printf("error");
    }
    printf("Parent (PID %d) exiting\n", getpid());
    exit(0);
  }
}
