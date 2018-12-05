#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define KEY 24601 //NOT A GOOOD IDEA
#define SEG_SIZE 200

int main()
{
	int shmd;
	char * data;
	char input[3];
	
	shmd = shmget(KEY, SEG_SIZE, IPC_CREAT | 0644); //not overwrite
	data = shmat(shmd, 0 , 0);
	if(!(*data)){printf("New segment, no data to display\n");}
	else{printf("woo\n");}	
	printf("data:%s\n",data);
	fgets(data, SEG_SIZE, stdin);
	*strchr(data, '\n') = 0;
	
	
	
	shmdt(data);
	shmctl(shmd, IPC_RMID, 0);
	

		
    return 0;
}
