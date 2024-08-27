#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/wait.h>

typedef struct node {

    int n;
    int a[];
} shared;

int main(){

int key=1234;
int shmid=shmget(key , sizeof(shared), 0666 | IPC_CREAT);
shared * ptr=(shared*)shmat(shmid,NULL,0666);

printf("ENTER THE NUMBER :\n");
scanf("%d",&ptr->n);

pid_t childpid = fork();

if(childpid==0){

    execlp("./child","./child",NULL);
}else{

    wait(NULL);
    printf("CHILD PROCESS FINISHED \n");
    for(int i=0;i<ptr->n;i++){

        printf("%d",ptr->a[i]);
    }

    shmdt((void *)ptr);
}


}