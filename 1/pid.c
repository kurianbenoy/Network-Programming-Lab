#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main() 
{
        pid_t pid, ppid,uid;
    	gid_t gid;

	if ((pid = getpid()) < 0) {
	  perror("unable to get pid");
	} 
else {
	  printf("The process id is %d \n", pid);
	}

	if ((ppid = getppid()) < 0) {
	  perror("unable to get the ppid \n");
	} 
  else {
	  printf("The parent process id is %d \n", ppid);
	}
	
	if((uid=getuid())<0) {
		perror("Unable to get uid");
	}
	else
	{
	printf("User id is %d \n",uid);
	}

	if ((gid = getgid()) < 0) {
	  perror("unable to get the group id");
	} 
    else {
	  printf("The group id is %d \n", gid);
	}

	return(0);
}  

