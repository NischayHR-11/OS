#include<Stdio.h>

struct process {

    int Pid,at,bt,ct,wt,tt,rt,v;
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
        processes[i].v=0;
        printf("\n");
    }

    int ttt=0,twt=0,trt=0,p=0,rp=n,elapsedTime=0;

    printf("Gant Chart:\n\n");

    while(rp!=0){

        p=-1;
        int sb=99999;

        for(int i=0;i<n;i++){

            if(!processes[i].v && processes[i].at <= elapsedTime){

                if(processes[i].bt<sb){
                    p=i;
                    sb=processes[i].bt;
                }
            }
        }

        if(p==-1){

            printf("|(%d) *** (%d)",elapsedTime,elapsedTime+1);
            elapsedTime++;
        }
        else{
        int t=elapsedTime;

        elapsedTime=elapsedTime+processes[p].bt;
        processes[p].v=1;
        processes[p].rt=t-processes[p].at;
        processes[p].ct=elapsedTime;
        processes[p].tt=processes[p].ct-processes[p].at;
        processes[p].wt=processes[p].tt-processes[p].bt;
        ttt=ttt+processes[p].tt;
        twt=twt+processes[p].wt;
        trt=trt+processes[p].rt;

        printf("|(%d)  p%d  (%d)",t,processes[p].Pid,elapsedTime);
        rp--;
        }
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