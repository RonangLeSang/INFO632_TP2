#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  pid_t pid;
  
  pid = fork();
  
  if (pid < 0) {
    fprintf(stderr, "Failed to create child process\n");
    exit(1);
  } else if (pid == 0) {
    printf("Child process (PID %d) exiting\n", getpid());
    exit(0);
  } else {
    printf("Parent process (PID %d) created child process (PID %d)\n", getpid(), pid);
    sleep(10); // wait 10 seconds
    wait(NULL); // clean up child process exit status
    printf("Parent process (PID %d) exiting\n", getpid());
    exit(0);
  }
}
