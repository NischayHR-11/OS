#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(){

    pid_t childpid,mypid,parentpid;

    childpid = fork();

    if(childpid<0){

        printf("FORK FAILED !!\n");
        exit(0);

    }else if(childpid ==0){

        printf("[CHILD] THIS IS CHILD PROCESS.\n");
        mypid = getpid();
        parentpid = getppid();

        printf("[CHILD] MY PID IS : %d.\n",mypid);
        printf("[CHILD] MY PARENT PID IS : %d.\n",parentpid);
        printf("[CHILD] EXITING.\n");
        exit(0);

    }else{

        printf("[PARENT] THIS IS PARENT PROCESS.\n");
        mypid =  getpid();
        parentpid = getppid();
        printf("[PARENT] MY PID IS : %d.\n",mypid);
        printf("[PARENT] MY PARENT PID IS : %d.\n",parentpid);
        printf("[PARENT] SLEEPIG FOR 10 SEC.\n");
        sleep(10);
        printf("[PARENT] CHILD PROCESS IS FINISHED BUT IT AS ENTRY IN PROCESS TABLE");
        printf("[PARENT] IT IS ZOMBIE PROCESS");
    }

    return 0;
}