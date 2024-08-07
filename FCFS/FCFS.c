#include<stdio.h>

struct process {

    int Pid,at,bt,ct,wt,tt,rt;
};

int main(){

    int n;
    printf("ENTER THE NUMBER OF PROCESSES : \n");
    scanf("%d",&n);

    struct process processes[n];

    printf("ENTER THE DETAILS OF EACH PROCESSES :\n\n");

    for(int i=0;i<n;i++){

        printf("Process %d : \n",i+1);
        processes[i].Pid=i+1;
        printf("\nArival Time : ");
        scanf("%d",&processes[i].at);
        printf("Burst Time : ");
        scanf("%d",&processes[i].bt);

        printf("\n");
    }

    for(int i=0;i<n-1;i++){

        for(int j=0;j<n-i-1;j++){

            if(processes[j].at>processes[j+1].at){
                int t=processes[j].at;
                processes[j].at=processes[j+1].at;
                processes[j+1].at=t;
            }
        }
    }

    int elapsedTime=0;
    int twt=0;
    int ttt=0;
    int trt=0;

    printf("Gant Chart:\n\n");

    for(int i=0;i<n;i++){

        if(processes[i].at>elapsedTime){
            elapsedTime=elapsedTime+(processes[i].at-elapsedTime);
        }

        int t=elapsedTime;

        processes[i].rt=elapsedTime-processes[i].at;
        elapsedTime=elapsedTime+processes[i].bt;
        processes[i].ct=elapsedTime;
        processes[i].tt=processes[i].ct-processes[i].at;
        processes[i].wt=processes[i].tt - processes[i].bt;
        ttt=ttt+processes[i].tt;
        twt=twt+processes[i].wt;
        trt=trt+processes[i].rt;

        printf("|(%d)  p%d  (%d)",t,i+1,elapsedTime);
    }

    printf("|\n\n");


    printf("TABLE :\n");

    printf("Process ID\tArrivalTime\tBurstTime\tCompletionTime\tResponseTime\tTurnAroundTime\tWaitingTime\n");
    for(int i=0;i<n;i++){

        printf("\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",processes[i].Pid,processes[i].at,processes[i].bt,processes[i].ct,processes[i].rt,processes[i].tt,processes[i].wt);
    }

    printf("\nTOTAL RESPONSE TIME :%d\n",trt);
    printf("TOTAL TURNAROUND TIME :%d\n ",ttt);
    printf("TOTAL WATING TIME :%d\n\n",twt);
    printf("AVERAGE RESPONSE TIME :%.2f\n",(float)(trt)/n);
    printf("AVERAGE TURNAROUND TIME :%.2f\n ",(float)(ttt)/n);
    printf("AVERAGE WATING TIME :%.2f\n ",(float)(twt)/n);
}