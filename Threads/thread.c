#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int sum=0,fac=1;


void* sums(void *p){

    int n=atoi(p);

    printf("INSIDE SUM THREAD ...\n");

    for(int i=1;i<n;i++){

        sum=sum+i;
    }

    printf("EXITING SUM THREAD...\n");
}

void* facs(void *p){

    int n=atoi(p);

    printf("INSIDE FAC THREAD ...\n");

    for(int i=1;i<n;i++){

        fac=fac*i;
    }

    printf("EXITING FAC THREAD...\n");
}

int main(int argc ,char *argv[]){

    pthread_t t1,t2;

    pthread_create(&t1,NULL,sums,argv[1]);
    pthread_create(&t2,NULL,facs,argv[1]);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    printf("INSIDE MAIN THREAD ....\n");
    printf("SUM : %d\n",sum);
    printf("FAC : %d\n",fac);

}