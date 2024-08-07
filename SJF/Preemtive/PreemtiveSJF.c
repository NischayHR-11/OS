#include<Stdio.h>

struct process {

    int Pid,at,bt,ct,wt,tt,rt,v,rm;
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
        processes[i].rm=processes[i].bt;
        printf("\n");
    }

    int ttt=0,twt=0,trt=0,p=0,rp=n,elapsedTime=0;

    printf("Gant Chart:\n\n");
    int pt[100];
    int tt[1000];
    int j=-1,k=-1;
    tt[++k]=0;


    while(rp!=0){

        p=-1;
        int sb=9999;
        for(int i=0;i<n;i++){

            if(processes[i].rm>0 && processes[i].at<=elapsedTime){

                if(processes[i].rm<sb){

                    p=i;
                    sb=processes[i].rm;
                }
            }
        }

        if(p==-1){

            pt[++j]=0;
            elapsedTime++;
            pt[++k]=elapsedTime;
            continue;
        }

        if(processes[p].bt==processes[p].rm){
            processes[p].rt=elapsedTime-processes[p].at;
            trt=trt+processes[p].rt;
        }

        processes[p].rm--;
        pt[++j]=processes[p].Pid;
        elapsedTime++;
        tt[++k]=elapsedTime;

        if(processes[p].rm==0){

            processes[p].ct=elapsedTime;
            processes[p].tt=processes[p].ct-processes[p].at;
            processes[p].wt=processes[p].tt-processes[p].bt;
            ttt=ttt+processes[p].tt;
            twt=twt+processes[p].wt;
            rp--;
        }

    }

     printf("\nGantt Chart\n(P0-->idle time)\n");
    for (int i = 0; i <= k; i++)
        printf("| P%d\t", pt[i]);

    printf("|\n");

    for (int i = 0; i <= j; i++)
        printf("%d\t", tt[i]);


    printf("\nTABLE :\n");

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
