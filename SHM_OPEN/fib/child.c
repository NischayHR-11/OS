#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/mman.h>

int main(int argc,char *argv[]){

    int n=atoi(argv[1]);

    int shmid=shm_open("TEST",O_CREAT | O_RDWR,0666);
    ftruncate(shmid,4096);
    void *ptr=mmap(0,4096,PROT_WRITE,MAP_SHARED,shmid,0);

    int a[100];

    a[0]=0;
    sprintf(ptr,"%d\t",a[0]);
    ptr=ptr+strlen(ptr);
    a[1]=1;
    sprintf(ptr,"%d\t",a[1]);
    ptr=ptr+strlen(ptr);

    for(int i=2;i<=n;i++){

        a[i]=a[i-1]+a[i-2];
        sprintf(ptr,"%d\t",a[i]);
        ptr=ptr+strlen(ptr);

    }


    munmap(ptr,4096);

    close(shmid);

}