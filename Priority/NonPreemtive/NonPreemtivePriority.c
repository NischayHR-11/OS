#include<stdio.h>

struct process {

    int Pid,at,bt,ct,wt,tt,rt,v,p;
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
        printf("Priority : ");
        scanf("%d",&processes[i].p);
        processes[i].v=0;
        printf("\n");
    }

    int ttt=0,twt=0,trt=0,p=0,rp=n,elapsedTime=0;

    printf("Gantt chart :\n\n");

    while(rp!=0){

        p=-1;
        int minp=9999;

        for(int i=0;i<n;i++){

            if(processes[i].at<=elapsedTime && !processes[i].v){

                if(processes[i].p<minp||(processes[i].p=minp && processes[i].at<processes[p].at)){

                    p=i;
                    minp=processes[i].p;
                }
            }
        }

        if(p==-1){

            printf("|(%d) *** (%d)",elapsedTime,elapsedTime+1);
            elapsedTime++;
            continue;
        }

        int t=elapsedTime;

        elapsedTime=elapsedTime+processes[p].bt;
        processes[p].rt=t-processes[p].at;
        processes[p].ct=elapsedTime;
        processes[p].tt=processes[p].ct-processes[p].at;
        processes[p].wt=processes[p].tt-processes[p].bt;
        processes[p].v=1;
        ttt=ttt+processes[p].tt;
        twt=twt+processes[p].wt;
        trt=trt+processes[p].rt;
        rp--;

        printf("|(%d) P%d (%d)",t,processes[p].Pid,elapsedTime);
    }


}