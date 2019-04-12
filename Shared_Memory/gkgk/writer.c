#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main()
{
	key_t key = ftok("shmfile",65);
	int shmid = shmget(key, 1024, 066 | IPC_CREAT);

	char *str = (char*) shmat(shmid, (void*)0,0);
	printf("Write data: ");
	gets(str);
	
	printf("Data written in memory: %s\n", str);

	shmdt(str);
	return 0;

}
