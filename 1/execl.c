#include<stdio.h>
#include<unistd.h>

void main()
{
  int pid;
  if (pid == fork() == -1)
	printf("Fork error");
  else if (pid ==0)
  {
    execl("newfile","newfile",NULL);
	printf("Return not executed\n");
   }
}
