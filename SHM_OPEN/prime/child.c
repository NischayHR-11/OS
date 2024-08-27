#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fnctl.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include<sys/mman.h>
#include<sys/ipc.h>
#include<sys/stat.h>
#include<string.h>


int main(int argc, char * argv[]){

    int n1=atoi(argv[1]);
    int n2=atoi(argv[2]);

    int shmid = shm_open("VSS",O_RDWR|O_CREAT,0666);
    void *ptr= mmap(0,4096,PRO_WRITE,MAP_SHARE,shmid,0);


    for(int i=n1;i<=n2;i++){

        int flag=0;

        for(int j=2;j<=i/2;i++){

            if(i%j==0){

                flag=1;
                break;
            }
        }

        if(flag==0){
            sprintf(ptr,"%d\t",i);
        }
    }


    munmap(ptr,4096);
}