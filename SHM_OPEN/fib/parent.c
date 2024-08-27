#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include<sys/mman.h>
#include<sys/ipc.h>


int main(int argc,char *argv[]){

    if(argc <2){

        printf("INSUFFIENT ARRGUMENTS !!");
        exit(0);
    }

    int n=atoi(argv[1]);

    if(n<1 ||n<0){

        printf("INVALID ARRGUMENTS!!");
        exit(0);
    }

    pid_t childpid=fork();

    if(childpid==0){

        execlp("./child","./child",argv[1],NULL);
    }else{

        wait(NULL);

        printf("CHILD FINISHED EXECUTION ..\n");

        int shmid=shm_open("TEST",O_RDONLY,0666);
        void *ptr = mmap(0,4096,PROT_READ,MAP_SHARED,shmid,0);

        printf("PARENT READING : ");

        printf("FIB NUMBERS ARE : %s\n",(char *)ptr);

        shm_unlink("TEST");

    }


}