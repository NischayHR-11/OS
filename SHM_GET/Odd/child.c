#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<sys/shm.h>
#include<sys/ipc.h>

typedef struct node {

int n;
int a[];

}shared;

int main(){


    int key=1234;
    int shmid=shmget(key,sizeof(shared),0666|IPC_CREAT);

    shared *ptr= (shared *)shmat(shmid,NULL,0666);

    int n=ptr->n;

    for(int i=0;i<=n;i++){

        ptr->a[i]=2*i+1;
    }

    shmdt((void *)ptr);
}