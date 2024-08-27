#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fnctl.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/shm.h>
#include<sys/mman.h>
#include<sys/ipc.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc ,char *argv[] ){


    if(argc<3){

        printf("INSUFFIENT ARGUMENTS !!");
        exit(0);
    }

    int n1=atoi(argv[1]);
    int n2=atoi(argv[2]);

    if(n2<n1){

        printf("INVALID ARGUMETS !!\n");
        exit(0);
    }

    pid_t childpid;


    if((childpid=fork())==0){

        execlp("./child","./child",argv[1],argv[2],NULL);

    }else{

        wait(NULL);

        int shmid= shmopen("vss",4096,O_RDONLY,0666);
        void *ptr=mmap(0,4096,PRO_READ,MAP_SHARED,shmid,0);

        printf("CHILD FINISHED EXECUTION :\n");

        printf("PARENT PRINTING : %s\n",(char *)ptr);

        shm_unlink("vss");

    }
}
