#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void *print_message_function( void *ptr );

int main()
{
	pthread_t t1,t2;
	char *message1 = "jadslk";
	char *message2 = "jasd";
	int iret1,iret2;

     iret1 = pthread_create( &t1, NULL, print_message_function, (void*) message1);
     iret2 = pthread_create( &t2, NULL, print_message_function, (void*) message2);


     pthread_join( t1, NULL);
     pthread_join( t2, NULL); 

     printf("Thread 1 returns: %d\n",iret1);
     printf("Thread 2 returns: %d\n",iret2);
     exit(0);
	return 0;
}

void *print_message_function( void *ptr )
{
     char *message;
     message = (char *) ptr;
     printf("%s \n", message);
}
