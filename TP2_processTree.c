#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void create_tree(int depth, int max_depth);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <depth>\n", argv[0]);
    exit(1);
  }
  
  int depth = atoi(argv[1]);
  create_tree(1, depth);
  return 0;
}

void create_tree(int depth, int max_depth) {
  if (depth > max_depth) {
    return;
  }
  
  pid_t pid_left, pid_right;
  
  pid_left = fork();
  
  if (pid_left < 0) {
    fprintf(stderr, "error\n");
    exit(1);
  } else if (pid_left == 0) {
    printf("Left child (PID %d)\n", getpid());
    sleep(7); // wait a little bit
    create_tree(depth+1, max_depth);
    exit(0);
  }
  
  pid_right = fork();
  
  if (pid_right < 0) {
    fprintf(stderr, "error\n");
    exit(1);
  } else if (pid_right == 0) {
    printf("Right child (PID %d)\n", getpid());
    sleep(7); // wait a little bit
    create_tree(depth+1, max_depth);
    exit(0);
  }
  
  printf("Parent (PID %d) created left child (PID %d) and right child (PID %d)\n", getpid(), pid_left, pid_right);
  
  waitpid(pid_left, NULL, 0);
  waitpid(pid_right, NULL, 0);
}
