#include<stdio.h>
#include<stdlib.h>

typedef struct node {

    int id,at,bt,ct,tt,wt,rt,rm,flag;

} process;


void roundrobin(process p[],int n,int qntm){

    int et=p[0].at;int ex,ttt=0,twt=0,trt=0,rm=n;

    int queue[100];int front=0;int rear=0;

    queue[rear++]=0;
    p[0].flag=1;

    while(rm!=0){

        ex = queue[front++];

        if(p[ex].bt == p[ex].rm){

            p[ex].rt =et-p[ex].at;
        }

        if(p[ex].rm >qntm){

            p[ex].rm=p[ex].rm-qntm;
            et=et+qntm;
            printf("|(%d) p%d (%d)",et-qntm,p[ex].id,et);

        }else{

            et=et+p[ex].rm;
            printf("|(%d) p%d (%d)",et-p[ex].rm,p[ex].id,et);
            p[ex].rm=0;
            p[ex].ct=et;
            p[ex].tt=p[ex].ct-p[ex].at;
            p[ex].wt=p[ex].tt-p[ex].bt;
            rm--;
        }

        for(int i=0;i<n && p[i].at<=et;i++){

            if(p[i].flag==0 && p[i].rm>0){
                
                p[i].flag=1;
                queue[rear++]=i;
            }
        }

        if(p[ex].rm>0){
            queue[rear++]=ex;
        }

    }
}

int main(){

    int n,q;
    printf("ENTER THE NUMBER OF PROCESSES : \n");
    scanf("%d",&n);
    printf("ENTER THE QUANTUM TIME :\n");
    scanf("%d",&q);

    process p[n];

    printf("ENTER THE DETAILS OF EACH PROCESSES :\n\n");

    for(int i=0;i<n;i++){

        printf("Process %d : \n",i+1);
        p[i].id=i+1;
        printf("\nArival Time : ");
        scanf("%d",&p[i].at);
        printf("Burst Time : ");
        scanf("%d",&p[i].bt);
        p[i].rm=p[i].bt;
        p[i].flag=0;
        printf("\n");
    }

    for(int i=0;i<n;i++){

        printf("%d ",p[i].at);
    }

    printf("\n");

    for(int i=0;i<n-1;i++){

        for(int j=0;j<n-i-1;j++){

            if(p[j].at>p[j+1].at){
                int t=p[j].at;
                p[j].at=p[j+1].at;
                p[j+1].at=t;
            }
        }
    }

    for(int i=0;i<n;i++){

        printf("%d ",p[i].at);
    }
    printf("\n");

    roundrobin(p,n,q);

}