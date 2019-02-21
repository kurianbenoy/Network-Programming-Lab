#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
  int pid = fork();

  if (pid == -1) {
    fprintf(stderr, "Could not fork process\n");
    return -1;
  } else if (pid == 0) {
    fprintf(stdout, "Child will now replace itself with ls\n");

    // Setup the arguments/environment to call
    char *argv[] = { "/bin/ls", "-la", 0 };
    char *envp[] = { "HOME=/", "PATH=/bin:/usr/bin", "USER=brandon", 0 };

    // Call execve(2) which will replace the executable image of this
    // process
    execve(argv[0], &argv[0], envp);

    // Execution will never continue in this process unless execve returns
    // because of an error
    fprintf(stderr, "Oops!\n");
    return -1;
  } else if (pid > 0) {
    int status;

    fprintf(stdout, "Parent will now wait for child to finish execution\n");
    wait(&status);
    fprintf(stdout, "Child has finished execution (returned %i), parent is done\n", status);
  }

  return 0;
}

