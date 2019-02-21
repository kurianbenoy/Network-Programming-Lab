#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *myThreadFun(void *vargp)
{
	sleep(1);
	printf("3 \n");
	if(pthread_detach(pthread_self()) == 0)
	{
		perror("pythread detach() success");
	}
	else
	{
	perror("pthread detach() error");
	printf("After Thread \n");
	sleep(1);
	printf("2 \n");
	sleep(1);
	pthread_exit(NULL);
	printf("1 \n");
	sleep(1);
	printf("0 \n");
	printf(" In function \n THREADID = %lu\n",pthread_self());
	return NULL;
	}
}

int main()
{
	pthread_t thread;
	printf("Beforeee Thread");
	pthread_create(&thread,NULL,myThreadFun,NULL);
	pthread_join(thread,NULL);
	exit(0);
	return 0;
}
